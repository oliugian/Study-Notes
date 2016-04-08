local cj = require "cjson"
local filepath = "/usr/local/nginx/conf/json_data/all_servedrs.json"
local file
if pcall(function(data) file = io.open(filepath, "r") end) then
else
	print("can't open ",filepath) return 
end
if file ==nil then print("!!!!!!!!") return end
local content = {}
if pcall(function(data) content = cj.decode(file:read("*all")) end) then
else
	print(filepath," contain nothing.")
        file:close() return
end
file:close()
print(content[1].listen)
return
	

