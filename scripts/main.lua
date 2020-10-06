LZ_BASIC_RANDOM_SEED = 1;

print(2);

Random = require("lib.random");
print(Random.module_name);

local rs = Random.RandomState:new();
rs:set_seed(LZ_BASIC_RANDOM_SEED);
print(rs:get());

debug.debug();