Module = {};

Module.RandomState = {};

Module.module_name = "random";

function Module.RandomState:new(seed)
    local o = {};
    setmetatable(o, self);
    self.__index = self;

    self.state = lstd_create_random_state();
    
    if seed ~= nil
    then
        lstd_random_state_set_seed(self.state, seed);
    end
    
    return o;
end

function Module.RandomState:set_seed(seed)
    lstd_random_state_set_seed(self.state, seed);
end

function Module.RandomState:get()
    return lstd_random_state_get_random(self.state);
end

return Module;