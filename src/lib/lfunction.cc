#include "lfunctions.h"

void lf_register_c_function(lua_State* L, lua_CFunction func, const char* func_name) {
    lua_checkstack(L, 1);
    lua_pushcfunction(L, func);
    lua_setglobal(L, func_name);
}