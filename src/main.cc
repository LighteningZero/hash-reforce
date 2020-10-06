#include <string>
#include <cstdio>
#include <cstring>
#include <lua.hpp>
#include "random.h"

random_state lz_basic_random_state;

void init_engine(lua_State* L) {
    // init basic random state
    lua_getglobal(L, "LZ_BASIC_RANDOM_SEED");
    auto global_seed = lua_tointeger(L, -1);
    lz_basic_random_state.set_seed(global_seed);
}

int main() {
    printf("Loaded.\n");
    lua_State* L = luaL_newstate();
    if (L == nullptr) {
        printf("Cannot load lua!\n");
        return 0;
    }
    luaL_openlibs(L);
    lf_random_register(L);
    luaL_dofile(L, "main.lua");
    init_engine(L);

    char* name1 = new char[1024];
    char* name2 = new char[1024];
    scanf("%s %s", name1, name2);

    delete[] name1;
    delete[] name2;
    lua_close(L);
    return 0;
}