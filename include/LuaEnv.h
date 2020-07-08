#pragma once

#include <string>
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "LuaBridge/LuaBridge.h"

using LUA_REF = luabridge::LuaRef;
using LUA_NS = luabridge::Namespace;

class LuaEnv
{
	friend class LuaScript;
	lua_State* L;
	LuaEnv();
public:
	LuaEnv(const LuaEnv&) = delete;
	~LuaEnv();
	static luabridge::LuaRef getGlobal(const char* varName);
	static luabridge::Namespace getGlobalNamespace();
	template<typename T> static void push(const char* ptrName, T* ptr)
	{
		luabridge::push(getState(), ptr);
		lua_setglobal(getState(), ptrName);
	}
	static LuaEnv& get();
	static lua_State* getState();
	static int LuaEnv::execute(const char* filename);
};
