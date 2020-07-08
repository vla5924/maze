#include "LuaEnv.h"

LuaEnv::LuaEnv()
{
	L = luaL_newstate();
	luaL_openlibs(L);
}

LuaEnv::~LuaEnv()
{
	lua_close(L);
}

luabridge::LuaRef LuaEnv::getGlobal(const char* varName)
{
	return luabridge::getGlobal(getState(), varName);
}

luabridge::Namespace LuaEnv::getGlobalNamespace()
{
	return luabridge::getGlobalNamespace(getState());
}

LuaEnv& LuaEnv::get()
{
    static LuaEnv instance;
    return instance;
}

lua_State* LuaEnv::getState()
{
	return get().L;
}

int LuaEnv::execute(const char* filename)
{
	int status = luaL_loadfile(getState(), filename);
	if (status)
		return status;
	else if (lua_pcall(getState(), 0, 0, 0))
		return status;
	return status;
}
