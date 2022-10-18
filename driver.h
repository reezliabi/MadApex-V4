#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <random>
namespace driver {
    std::string random_string(std::string::size_type length)
    {
        static auto& chrs = "0123456789"
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        thread_local static std::mt19937 rg{ std::random_device{}() };
        thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

        std::string s;

        s.reserve(length);

        while (length--)
            s += chrs[pick(rg)];

        return s;
    }
    typedef INT64(*NtUserSetClipboardViewer)(uintptr_t);
    NtUserSetClipboardViewer communicati = nullptr;
    struct _requests {
        uint32_t    src_pid;
        uint64_t    src_addr;
        uint32_t    dst_pid;
        uint64_t    dst_addr;
        size_t        size;
        size_t transfer;
        std::uintptr_t   buffer;
        uint32_t	pid;
        int request_key;
        std::uintptr_t allocation;
    };
    uint32_t g_pid;
    uintptr_t g_base;
    std::wstring s2ws(const std::string& str)
    {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstrTo(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
        return wstrTo;
    }

    static uintptr_t getpid()
    {
        BYTE target_name[] = { 'r','5','a','p','e','x','.','e','x','e',0 };
        std::wstring process_name = s2ws(std::string((char*)target_name));
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(entry);
        if (!Process32First(snapshot, &entry)) {
            return 0;
        }
        while (Process32Next(snapshot, &entry)) {
            std::string str(entry.szExeFile);
            std::wstring wsTmp(str.begin(), str.end());
            if (wsTmp == process_name) {
                
                return entry.th32ProcessID;
            }
        }
        return 0;
    }
    bool core_init() {
        communicati = (NtUserSetClipboardViewer)GetProcAddress(LoadLibraryA("win32u.dll"), "NtUserCreatePalmRejectionDelayZone");//NtUserRegisterErrorReportingDialog
        if (!communicati)
        {
            printf("[>] driver cant found...");
            return false;
        }
        return true;
    }
    template<typename Value_T>
    void write(uintptr_t addr, Value_T val) {
        _requests out = { 0 };
        out.request_key = 33;
        out.pid = g_pid;
        out.dst_pid = GetCurrentProcessId();
        out.src_addr = addr;
        out.size = sizeof(Value_T);
        out.buffer = (uintptr_t)&val;
        uint64_t status = communicati(reinterpret_cast<uintptr_t>(&out));
    }
    uintptr_t get_base_self()
    {
        _requests out = { 0 };
        out.request_key = 31;
        out.pid = GetCurrentProcessId();
        uint64_t status = communicati(reinterpret_cast<uintptr_t>(&out));
        return out.allocation;
    }
    uintptr_t get_base()
    {
        _requests out = { 0 };
        out.request_key = 31;
        out.pid = g_pid;
        uint64_t status = communicati(reinterpret_cast<uintptr_t>(&out));
        return out.allocation;
    }
    template<typename Value_T>
    Value_T read(uintptr_t addr, size_t size = sizeof(Value_T))
    {
        Value_T val;
        _requests out = { 0 };
        out.request_key = 32;
        out.pid = g_pid;
        out.dst_pid = GetCurrentProcessId();
        out.src_addr = addr;
        out.size = size;
        out.buffer = (uintptr_t)&val;
        uint64_t status = communicati(reinterpret_cast<uintptr_t>(&out));
        return val;
    }
}