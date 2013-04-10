// SampleModule for Multi-Vice 0.1d
// Created by RootKiller (06.04.2013, 02:32)
#ifdef _WIN32
#include <Windows.h>
#endif
#include <MultiVice.h>

int TestCall(MultiVice::LUA * test)
{
	test->PushInteger(10);
	return 1;
}

EXPORT void ModuleStart()
{
	MultiVice::sdk.ConsoleOutput("Sample module started!");

	MultiVice::sdk.interfaces.scripting->GetLUA().PushInteger(32);
	MultiVice::sdk.interfaces.scripting->GetLUA().SetGlobal("TestModuleDefinition");

	MultiVice::sdk.interfaces.scripting->RegisterFunction("test",TestCall);
}

#ifdef _WIN32
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID)
{
	if (dwReason==DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
	}
	return TRUE;
}
#endif