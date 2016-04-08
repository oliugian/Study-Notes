local cjson = require "cjson"
local shared_data = ngx.shared.shared_data
--get share_data using server_port
local host_data = shared_data:get(ngx.var.server_port)
local host_all = {}
if host_data == nil then return "not_found" end
if pcall (function(data) host_all = cjson.decode(data) end,host_data) then
	local host_servers = host_all.servers
			for k,v in pairs(host_servers) do
				if(v.server == ngx.var.host) then
					local host_locations = v.locations
						for k1,v1 in pairs(host_locations) do
							if(v1.location == ngx.var.uri) 								then
								return v1.upstream
								end
						end
				end		
			end
	return "not_found"
else
	return "err"
end
