#ifndef LZ_LUA_FUNCTIONS
#define LZ_LUA_FUNCTIONS

#include <lua.hpp>

void lf_register_c_function(lua_State* L, lua_CFunction func, const char *func_name);

#endif // LZ_LUA_FUNCTIONS