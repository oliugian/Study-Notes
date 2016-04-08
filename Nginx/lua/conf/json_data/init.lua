local shared_data = ngx.shared.shared_data
local cj = require "cjson"
local http = require "socket.http"
local responce,state = http.request("http://192.168.80.148/json_data/all_servers.json")
if responce==nil or state~=200 then ngx.log(ngx.EMERG,"fetch remote json data failed.") return
else	
	local content = {}
	if pcall(function(data) content = cj.decode(responce) end) then
		for key,value in pairs(content) do
			local item = cj.encode(value)
			shared_data:set(value.listen,item)
		end
		ngx.log(ngx.EMERG,"init success.") return
	else 
		ngx.log(ngx.ERR,"json format is not correct.") return
	end
end
--[[ get json data from local area
local filepath = "/usr/local/nginx/conf/json_data/all_servers.json"
local file
if pcall(function(data) file = io.open(filepath, "r") end) then
else
	ngx.log(ngx.err,"can't open ",filepath) return
end
local content = {}
if pcall(function(data) content = cj.decode(file:read("*all")) end) then
else
	ngx.log(ngx.EMERG,filepath," contain nothing.")
        file:close() return
end
file:close()
--]]
