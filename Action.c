Action()
{
	int j;
	int shopID_index;
	int inventoryNumberId_index;
	long FileVarriable;
	char FileLocation[1024] = "..\\file_id.txt";

	web_url("/", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/login", 
		"URL={Host}:{Port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_start_transaction("UC01_TR01_Login");

	web_set_user("{Login}", "{Password}", "{Domain}:{Port}");
	
	web_submit_data("/api/login", 
		"Action={Host}:{Port}/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer={Host}:{Port}/login", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_url("{/", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/login", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/checkLogin", 
		"URL={Host}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/info", 
		"URL={Host}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/4", 
		"URL={Host}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("/api/ticket/", 
		"URL={Host}:{Port}/api/ticket/?state=-1,0,1,5&page=0" 
		"&size=10",
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);
	
	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR02_Create_incident");

	web_url("/api/user/catalog/node/0/children/", 
		"URL={Host}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Create_incident",LR_AUTO);

	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR03_Incident_data");
	
	web_reg_save_param_json(
        "ParamName=shopIDs",
        "QueryString=$..id",
        "SelectALL=Yes",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_url("/api/shops", 
		"URL={Host}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	
	shopID_index = rand() % atoi(lr_eval_string("{shopIDs_count}")) + 1;
	
	lr_save_string(lr_paramarr_idx("shopIDs", shopID_index), "shopID");

	web_url("/api/shops", 
		"URL={Host}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("/api/user/catalog/node/0/children/", 
		"URL={Host}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
        "ParamName=serviceIdS",
        "QueryString=$..services..id",
        "SelectALL=Yes",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_reg_save_param_json(
        "ParamName=serviceNames",
        "QueryString=$..services..name",
        "SelectALL=Yes",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
   	
	web_url("/api/user/catalog/treeview", 
		"URL={Host}:{Port}/api/user/catalog/treeview?shopid={shopID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
	
	j = rand() % atoi(lr_eval_string("{serviceIdS_count}")) + 1;
	
	lr_save_string(lr_paramarr_idx("serviceIdS", j), "serviceId");
		
	web_url("/api/user/catalog/node/146/children/", 
		"URL={Host}:{Port}/api/user/catalog/node/146/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/catalog/node/146/service/", 
		"URL={Host}:{Port}/api/user/catalog/node/146/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("}/api/user/catalog/breadcrumbs/146", 
		"URL={Host}:{Port}/api/user/catalog/breadcrumbs/146", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
        "ParamName=inventoryNumbers",
        "QueryString=$..services..name",
        "SelectALL=Yes",
        "Notfound=warning",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_url("/api/inventoryNumbers", 
		"URL={Host}:{Port}/api/inventoryNumbers?serviceId={serviceId}" 
		"&shopId={shopID}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("/api/inventoryNumbers", 
		"URL={Host}:{Port}/api/inventoryNumbers?shopId={shopID}" 
		"&serviceId={serviceId}&serviceId=2782&q=&page=0",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_json(
        "ParamName=FileID",
        "QueryString=$..id",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_submit_data("/api/ticket/file/", 
		"Action={Host}:{Port}/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value={File}", "File=yes", ENDITEM, 
		LAST);
	
	lr_save_string("", "c_buffer");
	
	if (atoi(lr_eval_string("{inventoryNumbers_count}")) == 0){
		
		lr_param_sprintf("c_buffer", "%s{\"text\":\"%s\"," 
		                 "\"header\":\"%s\",\"ticketStateId\": 0," 
		                 "\"serviceId\": \"%s\",\"files\": [%s]," 
		                 "\"shopId\": \"%s\"}",
		   lr_eval_string("{c_buffer}"),
		   lr_eval_string("{Text}"),
		   lr_paramarr_idx("serviceNames", j),
		   lr_eval_string("{serviceId}"),
		   lr_eval_string("{FileID}"),
		   lr_eval_string("{shopID}"));
	}
	else {
		inventoryNumberId_index = rand() % 
			atoi(lr_eval_string("{inventoryNumbers_count}")) + 1;
		lr_save_string(lr_paramarr_idx("inventoryNumbers",
		                               inventoryNumberId_index), "inventoryNumberId");
		
		lr_param_sprintf("c_buffer", "%s{\"text\":\"%s\",\"header\":\"%s\"," 
		                 "\"ticketStateId\": 0,\"serviceId\": \"%s\"," 
		                 "\"files\": [%s],\"inventoryNumberId\": \"%s\"," 
		                 "\"shopId\": \"%s\"}",
		   lr_eval_string("{c_buffer}"),
		   lr_eval_string("{Text}"),
		   lr_paramarr_idx("serviceNames", j),
		   lr_eval_string("{serviceId}"),
		   lr_eval_string("{FileID}"),
		   lr_eval_string("{inventoryNumberId}"),
		   lr_eval_string("{shopID}"));
	}
	
	lr_message("c_buffer");
	
	web_reg_save_param_json(
        "ParamName=ID",
        "QueryString=$..id",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	web_custom_request("/api/ticket/", 
		"URL={Host}:{Port}/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"BodyBinary={c_buffer}", 
		LAST);
	
	 FileVarriable = fopen (FileLocation,"w+");
     fprintf (FileVarriable, "%s \n", lr_eval_string("{ID}")); 
     fclose (FileVarriable);
	
	web_url("/", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/checkLogin", 
		"URL={Host}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/info", 
		"URL={Host}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/4", 
		"URL={Host}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("/api/ticket", 
		"URL={Host}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("/api/ticket", 
		"URL={Host}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC01_TR03_Incident_data",LR_AUTO);

	lr_think_time(TNINKTIME);

	lr_start_transaction("UC01_TR04_Logout");

	web_url("/api/logout", 
		"URL={Host}:{Port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/login", 
		"URL={Host}:{Port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_Logout",LR_AUTO);

	return 0;
}