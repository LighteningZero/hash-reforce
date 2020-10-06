#include "hash.h"
#include <climits>

unsigned _lz_fast_power(unsigned x, unsigned p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    auto hash_res = _lz_fast_power(x, p / 2);
    if (p % 2 == 0)
        return hash_res * hash_res;
    return hash_res * hash_res * x;
}

unsigned _lz_mod_easy_hash(unsigned int x, unsigned alpha, unsigned beta) {
    return _lz_fast_power(x % alpha, beta) % alpha;
}

unsigned run_hash(unsigned x) {
    const unsigned hash_methods[][2] = {
        {20070521, 37},
        {10052037, 91},
        {24124841, 23},
        {77125623, 29},
        {73202609, 89},
        {14441131, 11},
        {72319969, 109},
        {20070109, 521},
    };

    const unsigned hash_method_count = 8;
    const unsigned hash_import_number = (1 << 23) - 1;

    unsigned res = 0;

    for (int i = 0; i < hash_method_count; ++i) {
        auto now_val = _lz_mod_easy_hash(x, hash_methods[i][0], hash_methods[i][1]);
        res = res * hash_import_number + now_val;
    }

    return res;
}

unsigned string_hash(const char *s) {
    unsigned x = 0;
    for (size_t i = 0; s[i] != '\0'; ++i)
        x = x * CHAR_MAX + s[i];
    
    return run_hash(x);
}