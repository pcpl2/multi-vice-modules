// SampleModule for Multi-Vice 0.1d
// Created by RootKiller (06.04.2013, 02:32)
#ifdef _WIN32
#include <Windows.h>
#endif
#include <MultiVice.h>

MultiVice::LUA * g_pLUA = 0;

int TestCall(MultiVice::LUA * test)
{
	test->PushInteger(10);
	return 1;
}

void CallSomething()
{
	g_pLUA->GetGlobal("onSampleModuleSaySomething");

	if(g_pLUA->GetType(-1) != MultiVice::FUNCTION)
	{
		g_pLUA->Pop(-1);
		return;
	}

	g_pLUA->PushString("Hello World");
	g_pLUA->Call(1,1);
	MultiVice::sdk.ConsoleOutput("Scripts reply > %s", g_pLUA->GetString(-1));
}

EXPORT void ModuleStart()
{
	g_pLUA = MultiVice::sdk.interfaces.scripting->GetLUA();
	MultiVice::sdk.ConsoleOutput("Sample module started!");

	g_pLUA->PushInteger(32);
	g_pLUA->SetGlobal("TestModuleDefinition");

	MultiVice::sdk.interfaces.scripting->RegisterFunction("test",TestCall);

	CallSomething();
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