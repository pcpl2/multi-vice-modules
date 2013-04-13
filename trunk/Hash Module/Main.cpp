// Hash Module for Multi-Vice 0.1d
// Created by pcpl2 (11.04.2013, 18:32)
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <MultiVice.h>
#include <md2.h>
#include <md4.h>
#include <md5.h>
#include <sha1.h>
#include <sha2.h>
#include <sha4.h>


int MD2Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[MD2_DIGEST_LENGTH];
	char szResult[33];
	md2((const unsigned char *)szInput, strlen(szInput), ucResult);
	for(int i = 0; i < MD2_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

int MD4Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[MD4_DIGEST_LENGTH];
	char szResult[33];
	md4((const unsigned char *)szInput, strlen(szInput), ucResult);
	for(int i = 0; i < MD4_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

int MD5Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[MD5_DIGEST_LENGTH];
	char szResult[33];
	md5((const unsigned char *)szInput, strlen(szInput), ucResult);
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1;
}

int SHA1Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	char szResult[128];
	sha_buffer((const unsigned char *)szInput, strlen(szInput), (unsigned char*)szResult);
	LUA->PushString(szResult);
	return 1; 
}

int SHA224Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[SHA224_DIGEST_LENGTH];
	char szResult[SHA224_DIGEST_LENGTH*2+1];
	sha2((const unsigned char *)szInput, strlen(szInput), ucResult, 1);
	for(int i = 0; i < SHA224_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

int SHA256Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[SHA256_DIGEST_LENGTH];
	char szResult[SHA256_DIGEST_LENGTH*2+1];
	sha2((const unsigned char *)szInput, strlen(szInput), ucResult, 0);
	for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

int SHA384Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[SHA384_DIGEST_LENGTH];
	char szResult[SHA384_DIGEST_LENGTH*2+1];
	sha4((const unsigned char *)szInput, strlen(szInput), ucResult, 1);
	for(int i = 0; i < SHA384_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

int SHA512Hash(MultiVice::LUA * LUA)
{
	const char * szInput = LUA->GetString(1);
	unsigned char ucResult[SHA512_DIGEST_LENGTH];
	char szResult[SHA512_DIGEST_LENGTH*2+1];
	sha4((const unsigned char *)szInput, strlen(szInput), ucResult, 0);
	for(int i = 0; i < SHA512_DIGEST_LENGTH; i++)
		sprintf(szResult + (i * 2), "%02x", ucResult[i]);
	LUA->PushString(szResult);
	return 1; 
}

EXPORT void ModuleStart()
{
	MultiVice::sdk.ConsoleOutput("Hash module started!");

	MultiVice::sdk.interfaces.scripting->RegisterFunction("md2", MD2Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("md4", MD4Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("md5", MD5Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("sha1", SHA1Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("sha224", SHA224Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("sha256", SHA256Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("sha384", SHA384Hash);
	MultiVice::sdk.interfaces.scripting->RegisterFunction("sha512", SHA512Hash);
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