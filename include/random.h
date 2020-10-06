#ifndef LZ_RANDOM
#define LZ_RANDOM

#include <lua.hpp>

class random_state {
public:
    random_state();
    ~random_state();
    random_state(int seed);

    void set_seed(int seed);
    int get();

private:
    int _last_value;

public:
    static const int random_max;
    static const int alpha;
    static const int beta;
};

int lf_random_state_create(lua_State* L);
int lf_random_state_set_seed(lua_State* L);
int lf_random_state_get(lua_State* L);
void lf_random_register(lua_State* L);

#endif // LZ_RANDOM