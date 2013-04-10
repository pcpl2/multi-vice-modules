///////////////////////////////////////////////////////
//
// Multi-Vice SDK @ MultiVice.cpp
// Copyright (C) by Multi-Vice Team
//
//////////////////////////////////////////////////////
#include "MultiVice.h"
#include <string.h>

MultiVice::sSDK MultiVice::sdk;

EXPORT bool IsModuleCompatible(unsigned long ulSdkVersion)
{
	return (ulSdkVersion == MULTI_VICE_SDK_VERSION);
}

EXPORT void InitializeSDK(MultiVice::sSDK * pSDK)
{
	memcpy(&MultiVice::sdk,pSDK,sizeof(MultiVice::sSDK));
}