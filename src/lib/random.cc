#include "random.h"
#include <climits>
#include "lfunctions.h"

const int random_state::random_max = INT_MAX;
const int random_state::alpha = 9;
const int random_state::beta = 7;

random_state::random_state() {
    this->_last_value = 1;
}

random_state::~random_state() {}

random_state::random_state(int seed) {
    this->set_seed(seed);
}

void random_state::set_seed(int seed) {
    this->_last_value = seed;
}

int random_state::get() {
    int val = ((long long)this->_last_value * this->alpha + this->beta) % this->random_max;
    this->set_seed(val);
    return val;
}

int lf_random_state_create(lua_State* L) {
    lua_newuserdata(L, sizeof(random_state));
    return 1;
}

int lf_random_state_set_seed(lua_State* L) {
    auto s = (random_state*)lua_touserdata(L, -2);
    auto seed = lua_tointeger(L, -1);
    s->set_seed(seed);
    return 0;
}

int lf_random_state_get(lua_State* L) {
    auto s = (random_state*)lua_touserdata(L, -1);
    int val = s->get();
    lua_checkstack(L, 1);
    lua_pushinteger(L, val);
    return 1;
}

void lf_random_register(lua_State* L) {
    lf_register_c_function(L, &lf_random_state_create, "lstd_create_random_state");
    lf_register_c_function(L, &lf_random_state_set_seed, "lstd_random_state_set_seed");
    lf_register_c_function(L, &lf_random_state_get, "lstd_random_state_get_random");
}