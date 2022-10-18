#pragma once
#include "vector.h"
#include "offsets.h"
#include "entity.h"

static int AimBotKey;

void Aimbot(uintptr_t pEntity, uintptr_t pLocal, Matrix m, AimContext* Ctx, int index) {

	Vector3 entAimPos = BonePosition(pEntity, 8); //0 Hips //5 Body //7 Neck //8 Head
	uintptr_t entitylist = driver::read<uintptr_t>(driver::g_base + CL_ENTITYLIST);
	PredictPosition(pLocal, &entAimPos, entitylist, pEntity);

	Vector3 w2sEntAimPos = entAimPos.ScreenPosition(m); if (w2sEntAimPos.z <= 0.f) return;

	int entX = w2sEntAimPos.x;
	int entY = w2sEntAimPos.y;

	Ctx->entNewVisTime = driver::read<float>(pEntity + LASTVISIBLETIME);
	int entKnockedState = isKnocked(pEntity);
	int playerTeamID = iTeam(pLocal);
	int entTeamID = iTeam(pEntity);

	if (entTeamID != playerTeamID) {

		if (Ctx->entNewVisTime != Ctx->entOldVisTime[index])
		{
			Ctx->visCooldownTime[index] = 24;

			if (entKnockedState == 0)
			{

				if (abs(Ctx->crosshairX - entX) < abs(Ctx->crosshairX - Ctx->closestX) && abs(Ctx->crosshairX - entX) < Ctx->FOV && abs(Ctx->crosshairY - entY) < abs(Ctx->crosshairY - Ctx->closestY) && abs(Ctx->crosshairY - entY) < Ctx->FOV)
				{
					Ctx->closestX = entX;
					Ctx->closestY = entY;
				}
			}
			Ctx->entOldVisTime[index] = Ctx->entNewVisTime;
		}
		if (Ctx->visCooldownTime[index] >= 0) Ctx->visCooldownTime[index] -= 1;
	}
}

void AimbotMove(AimContext* Ctx) {

	if (Ctx->closestX != 50000 && Ctx->closestY != 50000)
	{
		if (GetAsyncKeyState(AimBotKey))
		{
			Ctx->aX = (Ctx->closestX - Ctx->crosshairX) / Ctx->aSmoothAmount;
			Ctx->aY = (Ctx->closestY - Ctx->crosshairY) / Ctx->aSmoothAmount;

			CURSORINFO ci = { sizeof(CURSORINFO) };
			if (GetCursorInfo(&ci))
			{
				if (ci.flags == 0)
					mouse_event(MOUSEEVENTF_MOVE, Ctx->aX, Ctx->aY, 0, 0);
			}
		}
	}
}