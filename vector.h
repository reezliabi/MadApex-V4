#ifndef VECTOR_3_H
#define VECTOR_3_H
#include <d3d9.h>
#include <math.h>
#define UCONST_Pi 3.1415926535
#define RadianToURotation 180.0f / UCONST_Pi
struct Matrix {
	float matrix[16];
};

class Vector3 {
public:
	Vector3() : x(0.f), y(0.f), z(0.f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	~Vector3() {}

	float x;
	float y;
	float z;

	inline float Dot(Vector3 v) {
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v) {
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	Vector3 operator+(Vector3 v) {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v) {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline float Length() {
		return sqrtf((x * x) + (y * y) + (z * z));
	}
	Vector3 operator*(float Scale) {

		return Vector3(x * Scale, y * Scale, z * Scale);
	}

	float Length2D()
	{
		return sqrt((x * x) + (y * y));
	}
	float DistTo(Vector3 ape)
	{
		return (*this - ape).Length();
	}
	void Normalize()
	{
		while (x > 89.0f)
			x -= 180.f;

		while (x < -89.0f)
			x += 180.f;

		while (y > 180.f)
			y -= 360.f;

		while (y < -180.f)
			y += 360.f;
	}
	float Dist2D(Vector3 ape)
	{
		return (*this - ape).Length2D();
	}

	struct Vector3 ScreenPosition(struct Matrix matrix) {
		struct Vector3 out;
		float _x = matrix.matrix[0] * x + matrix.matrix[1] * y + matrix.matrix[2] * z + matrix.matrix[3];
		float _y = matrix.matrix[4] * x + matrix.matrix[5] * y + matrix.matrix[6] * z + matrix.matrix[7];
		out.z = matrix.matrix[12] * x + matrix.matrix[13] * y + matrix.matrix[14] * z + matrix.matrix[15];

		_x *= 1.f / out.z;
		_y *= 1.f / out.z;

		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);

		out.x = width * .5f;
		out.y = height * .5f;

		out.x += 0.5f * _x * width + 0.5f;
		out.y -= 0.5f * _y * height + 0.5f;

		return out;
	}
};

struct Vector2 {
public:
	float x;
	float y;

	inline Vector2() : x(0), y(0) {}
	inline Vector2(float x, float y) : x(x), y(y) {}

	inline float Distance(Vector2 v) {
		return sqrtf(((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y)));
	}

	inline Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}
	void Normalize()
	{
		if (x > 89.0f)
			x -= 180.f;

		if (x < -89.0f)
			x += 180.f;

		if (y > 180.f)
			y -= 360.f;

		if (y < -180.f)
			y += 360.f;
	}
};
struct AimContext {
	int FOV;
	int aSmoothAmount;

	int crosshairX = GetSystemMetrics(SM_CXSCREEN) / 2;
	int crosshairY = GetSystemMetrics(SM_CYSCREEN) / 2;

	int entX = 0;
	int entY = 0;

	int closestX = 0;
	int closestY = 0;

	int aX = 0;
	int aY = 0;

	float entNewVisTime = 0;
	float entOldVisTime[100];
	int visCooldownTime[100];
};
struct Bone {
	BYTE thing[0xCC];
	float x;
	BYTE thing2[0xC];
	float y;
	BYTE thing3[0xC];
	float z;
};
Vector3 Position(uintptr_t entity) {
	return driver::read<Vector3>(entity + ORIGIN);
}
Vector3 BonePosition(uintptr_t Entity, int boneIndex)
{
	Bone bone = {};
	Vector3 vec_bone = Vector3();
	Vector3 pos = Position(Entity);

	ULONG64 bone_array = driver::read<ULONG64>(Entity + BONES);
	ULONG64 bone_location = (boneIndex * 0x30);

	bone = driver::read<Bone>(bone_array + bone_location);
	vec_bone.x = bone.x + pos.x;
	vec_bone.y = bone.y + pos.y;
	vec_bone.z = bone.z + pos.z;
	return vec_bone;
}
void PredictPosition(uintptr_t local, Vector3* bonePos, uintptr_t entitylist, DWORD64 entity)
{
	uintptr_t actWeaponID = driver::read<uintptr_t>(local + M_LASTESTPRIMARYWINDOWS) & 0xFFFF;
	uintptr_t currentWeapon = driver::read<uintptr_t>(entitylist + (actWeaponID << 5));

	if (currentWeapon != 0)
	{
		float bulletSpeed = driver::read<float>(currentWeapon + BULLET_SPEED);
		float bulletGravity = driver::read<float>(currentWeapon + BULLET_SCALE);

		if (bulletSpeed > 1.f)
		{
			Vector3 muzzle = driver::read<Vector3>(local + CAMERAPOS);
			float time = bonePos->DistTo(muzzle) / bulletSpeed;
			bonePos->z += (700.f * bulletGravity * 0.5f) * (time * time);
			Vector3 velDelta = (driver::read<Vector3>(entity + ORIGIN - 0xC) * time);
			bonePos->x += velDelta.x;
			bonePos->y += velDelta.y;
			bonePos->z += velDelta.z;
		}
	}
}
#endif