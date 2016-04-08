ngx.say(cj.encode(shared_data))
ngx.say(cj.encode(shared_data))
--Meta class
local Port_config={listen="",servers={}}
local Server_t={server="",locations={}}
local Location_t={location="",upstream=""}
local function Port_config:new (o,port,all_servers)
        o = o or {}
        setmetatable(o,self)
        self.__index = self
        self.listen = port
        self.servers = all_servers      
        return o
end

local function Server_t:new (o,server,all_locations)
        o = o or {}
        setmetatable(o,self)
        self.__index = self
        self.server = server
        self.locations = all_locations
        return o
end

local function Location_t:new(o,location,upstream)
        o = o or {}
        setmetatable(o,self)
        self.__index = self
        self.location = location
        self.upstream = upstream
        return o
end

