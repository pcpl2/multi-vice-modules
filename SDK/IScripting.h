///////////////////////////////////////////////////////
//
// Multi-Vice SDK @ IScripting.h
// Copyright (C) by Multi-Vice Team
//
//////////////////////////////////////////////////////

#ifndef _ISCRIPTING_H_
#define _ISCRIPTING_H_

class LUA
{
public:
	virtual void PushInteger(int integer) {};
	virtual int GetInteger(int index) { return 0; };

	virtual void PushString(const char * szString) {};
	virtual const char * GetString(int index) { return 0; }

	virtual void SetGlobal(const char * szName) {};

	virtual void * GetLUAPointer() { return 0; };
};

typedef int (*pfnModuleFunction)(LUA * lua);

class IScripting
{
public:
	/* 
	 * LoadScript
	 * @param szString - name of string without lua extension [const char *]
	 * @return boolean state of loading script
	 */
	virtual bool LoadScript(const char * szString) = 0;

	/*
	 * RegisterFunction
	 * @param szName - name of function [const char *]
	 * @param pfnClosure - closure pointer [pfnModuleFunction]
	 * @return none
	 */
	virtual void RegisterFunction(const char *szName, pfnModuleFunction pfnClosure) = 0;

	/*
	 * GetLUA
	 * @param null
	 * @return LUA pointer
	 */
	virtual LUA GetLUA() { return LUA(); };
};

#endif