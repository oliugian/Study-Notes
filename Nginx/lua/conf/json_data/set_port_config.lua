--use post method to manipulate upstreams in shared_data
--the post args use "type" to decide the way to manipulate the upstream data
--including add_upstream del_upstream update_upstream show_upstreams reinit_upstreams
local function del_upstream(conf)
        --check input value
	--del_type can be "l" "s" "p"  by "l" default
	del_type = conf.del_type or "u"
        if (type(conf) ~="table" or conf.listen == nil)
        then
        ngx.say("your post args are not correct.") return
        else    
                all_servers_temp = shared_data:get(conf.listen)
                upstream_temp = {}
                found_server,found_location = false,false
                if not all_servers_temp then
                        --listen port not found
			ngx.say("the listen port is not contained in shared_data") return
                else    
			if del_type == "p" then 
				shared_data:delete(conf.listen)
				ngx.say("delete port value in shared_data success") return
			end
			
			if conf.server ~= nil then
				if pcall(function() all_servers = cj.decode(all_servers_temp).servers end) then
				else
					ngx.say("parse servers in shared data failed") return 
				end 
				
				--all_servers = cj.decode(all_servers_temp).servers
				for s_index =1,table.getn(all_servers)  do
					if(all_servers[s_index].server == conf.server) then
						if del_type == "s" then
							table.remove(all_servers,s_index)
							upstream_temp = {listen = conf.listen,servers = all_servers}
							success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
							if success then
								ngx.say("remove a exist server success") return
							else
								ngx.say("remove a exist server failed ",err) return
							end
						end
		
						locations_t = all_servers[s_index].locations
						for l_index =1,table.getn(locations_t) do
							if(locations_t[l_index].location == conf.location) then
								table.remove(locations_t,l_index)
								upstream_temp = {listen = conf.listen,servers = all_servers}
 	                                                        success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
                                                          	if success then
                                                         	ngx.say("remove a exist upstream success") return
                                                         	else
                                                         	ngx.say("remove a exist upstream failed ",err) return
                                                         	end

							end
				
						end 
						ngx.say("location not found.") return
					end
				end
				ngx.say("server not found.") return
                         else
				ngx.say("server not found.") return
			 end
                end
        end
end

local function add_upstream(conf)
	--check input value
	if (type(conf) ~="table" or conf.listen == nil or conf.server == nil or conf.location ==nil or conf.upstream ==nil)
        then
        ngx.say("your post args are not correct.") return
        else	
                all_servers_temp = shared_data:get(conf.listen)
		upstream_temp = {}
		found_server,found_location = false,false
		if not all_servers_temp then
			--listen port not found
                        location_temp = {location=conf.location,upstream=conf.upstream}
                        server_temp = {server=conf.server,locations={location_temp}}
                        upstream_temp = {listen=conf.listen,servers={server_temp}}
			success,err = shared_data:set(conf.listen,cj.encode(upstream_temp))
                        if success then
                        	ngx.say("create a new listen_port_struct data") return
                        else
                                ngx.say("create a new listen_port_struct data failed ",err) return
                        end

		else	
			if pcall(function() all_servers = cj.decode(all_servers_temp).servers end) then
			else
				ngx.say("parse servers in shared data failed") return
			end

        		for k,v in pairs(all_servers) do
                		if(v.server == conf.server) then
					found_server = true
                        		for k1,v1 in pairs(v.locations) do
                                		if(v1.location == conf.location) then
							found_location = true
                                        		v1.upstream = conf.upstream
                                        		upstream_temp = {listen = conf.listen,servers = all_servers}
                                        		success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
                                       			if success then
                                        		ngx.say("replace a exist upstream success") return
                                       			else
                                       			ngx.say("replace a exist upstream failed ",err) return
                                        		end
						end
                               		end
					if not found_location then
						location_temp = {location=conf.location,upstream=conf.upstream}
						table.insert(v.locations,location_temp)
						upstream_temp = {listen = conf.listen,servers = all_servers}
						success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
						if success then
						ngx.say("create a new location success") return
						else
						ngx.say("create a new location failed ",err) return
						end

					end
                        	end
                	end
			if not found_server then
				location_temp = {location=conf.location,upstream=conf.upstream}
                                server_temp = {server=conf.server,locations={location_temp}}
                                table.insert(all_servers,server_temp)
                                upstream_temp = {listen = conf.listen,servers = all_servers}
				success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
				if success then
				ngx.say("create a new server success") return
				else
				ngx.say("create a new server failed ",err) return
				end

			end
		end
	end
end

local function reinit_upstream(path)
	
	local filepath = path or "http://192.168.80.148/json_data/all_servers.json"
	local http = require "socket.http"
	local responce,state = http.request(filepath)
	if responce==nil or state~=200 then ngx.say("fetch remote json data failed.") return
	else    
		local content
		if pcall(function(data) content = cj.decode(responce) end) then
			for key,value in pairs(content) do
				local item = cj.encode(value)
				shared_data:set(value.listen,item)
			end
			ngx.say("reinit success.") return
		else 
			ngx.say("json format is not correct.") return
		end
	end
	
	ngx.say("reinit success.") return
end
function spairs(t, order)
    -- collect the keys
	local keys= {}
	local keys_v ={}
	for k,v in pairs(t) do keys[#keys+1] = v.location keys_v[v.location]=v  end
		
	-- if order function given, sort by it by passing the table and keys a, b,
	-- otherwise just sort the keys 
	if order then
		table.sort(keys, function(a,b) return order(t, a, b) end)
	else
		table.sort(keys)
	end
	
	-- return the iterator function
	local i = 0
	return function()
		i = i + 1
		if keys[i] then
		    return keys[i], keys_v[keys[i]]
		end
	end
end
	
local function show_upstreams(listen_port)
	if (listen_port == nil) then
		all_keys = shared_data:get_keys()
		table.sort(all_keys)
		all_port_count = table.getn(all_keys)
		for i=1,all_port_count do
			listen_port = all_keys[i]
			show_upstreams(listen_port)
		end
	return
	else
		all_servers = {}
                if pcall(function(data) all_servers = cj.decode(shared_data:get(data)).servers end, listen_port) then
                else
                ngx.say("shared_data do not has the listen port and value.") return
                end
	end
	ngx.say("the listen port is ",listen_port,"\n")
	for k,v in pairs(all_servers) do
		ngx.say("server name: ",v.server)
		for k1,v1 in spairs(v.locations) do
			ngx.say("location: ",v1.location,"\tupstream: ",v1.upstream)
		end
		ngx.say("\n")
	--	ngx.say("locations :",table.concat(v.locations,", "))
	end
	return
end
local function update_upstream(conf)
	--check input value
	if (type(conf) ~="table" or conf.listen == nil or conf.server == nil or conf.location ==nil or conf.upstream ==nil)
	then
	ngx.say("your post args are not correct.") return
	else	
		all_servers = {}
		if pcall(function(data) all_servers = cj.decode(shared_data:get(data)).servers end, conf.listen) then
		else
		ngx.say("shared_data do not has the listen port and value.") return
		end
	end
	--update shared_data
	for k,v in pairs(all_servers) do
		if(v.server == conf.server) then
			for k1,v1 in pairs(v.locations) do
				if(v1.location == conf.location) then
					v1.upstream = conf.upstream
					local upstream_temp = {listen =  conf.listen,servers = all_servers}
        				success,err = shared_data:replace(conf.listen,cj.encode(upstream_temp))
        				if success then
       					ngx.say("update success") return
       					else
       					ngx.say("update failed: ",err) return
        				end
				end
			end
		end
	end			
	ngx.say("upstream not found") return
end

--start working
cj = require "cjson"
shared_data = ngx.shared.shared_data
get_args,err = ngx.req.get_uri_args()
if not get_args then 
	ngx.say("failed to get GET args:",err)
return
end
r_type = get_args.type
if r_type=="show" then
	show_upstreams(get_args.port) return
elseif r_type =="reinit" then
	reinit_upstream(get_args.path) return
else
	--get post data
	ngx.req.read_body()
	local args,err = ngx.req.get_post_args()
	if not args then
		ngx.say("failed to get post args: ",err)
	return
	end
	if r_type == "add" then
	--	show_upstreams()
		add_upstream(args) return
	elseif r_type == "update" then
		update_upstream(args) return
	elseif r_type == "delete" then
		del_upstream(args) return	
	end
end

