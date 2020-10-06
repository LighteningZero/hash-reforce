#ifndef LZ_HASH_FUNCTIONS
#define LZ_HASH_FUNCTIONS

#include <lua.hpp>

unsigned string_hash(const char *s);
unsigned run_hash(int x);
int lf_hash_string(lua_State* L);
void lf_register_hash_functions(lua_State* L);

#endif // LZ_HASH_FUNCTIONS