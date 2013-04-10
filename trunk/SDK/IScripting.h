///////////////////////////////////////////////////////
//
// Multi-Vice SDK @ IScripting.h
// Copyright (C) by Multi-Vice Team
//
//////////////////////////////////////////////////////

#ifndef _ISCRIPTING_H_
#define _ISCRIPTING_H_
/*
 * NOTES for LUA implementation class
 *
 * 1. Some methods in this class are not available due to security issues
 * 2. dofile function = IScripting::LoadScript
 * 3. If you want any function from lua and you doesn't have it here you need to
 *    implement lua api and use GetLUAPointer to get VM which you can use
 *	  with lua apis functions
 */

enum eLUAObjectType
{
	NONE = -1,
	NIL = 0,
	BOOLEAN,
	LIGHTUSERDATA,
	NUMBER,
	STRING,
	TABLE,
	FUNCTION,
	USERDATA,
	THREAD
};

class LUA
{
public:
	LUA() {};
	virtual ~LUA() {};

	virtual void PushNil() {};

	virtual void PushInteger(int value) {};
	virtual int GetInteger(int index) { return 0; };

	virtual void PushString(const char *value, ...) {};
	virtual const char * GetString(int index) { return 0; };

	virtual void PushFloat(float value) {};
	virtual float GetFloat(int index) { return 0.f; };

	virtual void PushBoolean(bool value) {};
	virtual bool GetBoolean(int index) { return false; };

	virtual void SetTable(int index) {};
	virtual void GetTable(int index) {};

	virtual void SetField(int index, const char * name) {};
	virtual void GetField(int index, const char * name) {};
	
	virtual void RawSet(int index) {};
	virtual void RawGet(int index) {};

	virtual void RawSetI(int index, int number) {};
	virtual void RawGetI(int index, int number) {};

	virtual void RawSetP(int index, const void * ptr) {};
	virtual void RawGetP(int index, const void * ptr) {};

	virtual int SetMetaTable(int objindex) { return 0; };
	virtual int GetMetaTable(int objindex) { return 0; };
	
	virtual void SetUserValue(int index) {};
	virtual void GetUserValue(int index) {};

	virtual void CreateTable(int narr, int nrec) {};
	virtual void * NewUserData(size_t sz) { return 0; };

	virtual eLUAObjectType GetType(int index)  { return NONE; };

	virtual void SetGlobal(const char * szName) {};
	virtual void GetGlobal(const char * szName) {};

	virtual bool Call(int arguments, int results) { return false; };

	virtual void * GetLUAPointer() { return 0; };

	virtual void Pop(int index) {};
};

typedef int (*pfnModuleFunction)(LUA * lua);

class IScripting
{
public:
	/* 
	 * LoadScript
	 * @param szString - name of script without lua extension [const char *]
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
	virtual MultiVice::LUA * GetLUA() { return new MultiVice::LUA(); };

	/*
	 * DestroyLUA
	 * @param pLUA - lua pointer to destroy [MultiVice::LUA  *]
	 * @return none
	 */
	void DestroyLUA(MultiVice::LUA * pLUA) {};
};

#endif