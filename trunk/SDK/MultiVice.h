///////////////////////////////////////////////////////
//
// Multi-Vice SDK @ MultiVice.h
// Copyright (C) by Multi-Vice Team
//
//////////////////////////////////////////////////////
#pragma once

#ifndef _MULTIVICE_H_
#define _MULTIVICE_H_

#define MULTI_VICE_SDK_VERSION	0x001

#if defined(_MSC_VER)
    #define EXPORT extern "C" __declspec(dllexport)
#else
    #define EXPORT extern "C" 
#endif

namespace MultiVice
{
#include "IScripting.h"

struct Interfaces
{
	IScripting *scripting;
};

struct sSDK
{
	Interfaces interfaces;
	void (*ConsoleOutput)(char * szLog,...);
};

extern sSDK sdk;
};
#endif
