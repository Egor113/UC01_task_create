Action()
{
	/*
  1) extraries -  ����� extraries ����� ��� ������ �������?
  ��� html ��������, ��������� ������� ����� ��� extraries,
  ������ ������� ��������� +
  
  2) �������� ������, ����, ���������
  ����� ������, ����� �������� +
    
  3) ������ �� �������� � ��������� 
  
  ????????????
  ticketStateId
  
  4) �������� ��������
  
  �������� �������� �������� � ���
    
  5) ������� �� ������� � �����
  
  ????????
  
  6) ������� �� ����� �����
  
  �������� ������� ������ �� learning2.pflb.ru:56902
  
	*/
	
	int j;
	int shopID_index;
	int inventoryNumberId_index;
	long FileVarriable;
	char FileLocation[1024] = "file_id.txt";

	web_url("/", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("login", 
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
	
	web_submit_data("login_2", 
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

	web_url("{Domain}:{Port}_2", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/login", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("checkLogin", 
		"URL={Host}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info", 
		"URL={Host}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4", 
		"URL={Host}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket", 
		"URL={Host}:{Port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
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
	
	lr_think_time(95);

	lr_start_transaction("UC01_TR02_Create_incident");

	web_url("children", 
		"URL={Host}:{Port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Create_incident",LR_AUTO);

	lr_think_time(95);

	lr_start_transaction("UC01_TR03_Incident_data");
	
	web_reg_save_param_json(
        "ParamName=shopIDs",
        "QueryString=$..id",
        "SelectALL=Yes",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_url("shops", 
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

	web_url("shops_2", 
		"URL={Host}:{Port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	//delete
	web_reg_save_param("name",
                 "LB=\"name\":\"",
                 "RB=\"",
				 "Ord=All",
				 LAST);
	
	web_url("children_2", 
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
   	
	web_url("treeview", 
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
		
	web_url("children_3", 
		"URL={Host}:{Port}/api/user/catalog/node/146/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("service", 
		"URL={Host}:{Port}/api/user/catalog/node/146/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("146", 
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
	
	web_url("inventoryNumbers", 
		"URL={Host}:{Port}/api/inventoryNumbers?serviceId={serviceId}&shopId={shopID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("inventoryNumbers_2", 
		"URL={Host}:{Port}/api/inventoryNumbers?shopId={shopID}&serviceId={serviceId}&serviceId=2782&q=&page=0", 
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
	
	web_submit_data("file", 
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
		
		lr_param_sprintf("c_buffer", "%s{\"text\":\"%s\",\"header\":\"%s\",\"ticketStateId\": 0,\"serviceId\": \"%s\",\"files\": [%s],\"shopId\": \"%s\"}",
		   lr_eval_string("{c_buffer}"),
		   lr_eval_string("{Text}"),
		   lr_paramarr_idx("serviceNames", j),
		   lr_eval_string("{serviceId}"),
		   lr_eval_string("{FileID}"),
		   lr_eval_string("{shopID}"));
	}
	else {
		inventoryNumberId_index = rand() % atoi(lr_eval_string("{inventoryNumbers_count}")) + 1;
		lr_save_string(lr_paramarr_idx("inventoryNumbers", inventoryNumberId_index), "inventoryNumberId");
		
		lr_param_sprintf("c_buffer", "%s{\"text\":\"%s\",\"header\":\"%s\",\"ticketStateId\": 0,\"serviceId\": \"%s\",\"files\": [%s],\"inventoryNumberId\": \"%s\",\"shopId\": \"%s\"}",
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
	
	web_custom_request("ticket_2", 
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
	
	//web_revert_auto_header("X-Requested-With");

	//lr_think_time(7);

	web_url("{Domain}:{Port}_3", 
		"URL={Host}:{Port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("checkLogin_2", 
		"URL={Host}:{Port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info_2", 
		"URL={Host}:{Port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4_2", 
		"URL={Host}:{Port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_2", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_3", 
		"URL={Host}:{Port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket_3", 
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

	web_custom_request("ticket_4", 
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

	lr_think_time(15);

	lr_start_transaction("UC01_TR04_Logout");

	web_url("logout", 
		"URL={Host}:{Port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer={Host}:{Port}/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	web_url("login_3", 
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