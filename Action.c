Action()
{
	/*
  1) extraries -  ����� extraries ����� ��� ������ �������?
  ��� html ��������, ��������� ������� ����� ��� extraries,
  ������ ������� ���������
  
  2) �������� ������, ����, ���������
  ����� ������, ����� �������� 
    
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
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	//delete
	web_add_cookie("sessionExpired=true; DOMAIN=learning2.pflb.ru");

	web_url("login", 
		"URL=http://learning2.pflb.ru:56902/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	//delete
	web_add_header("UA-CPU", 
		"AMD64");

	//delete
	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml?cvlp=4999843580514731330", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC01_TR01_Login");

	//delete
	web_add_cookie("sessionExpired=false; DOMAIN=learning2.pflb.ru");

	//delete
	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(87);

	web_set_user("{Login}", "{Password}", "learning2.pflb.ru:56902");
	
	web_submit_data("login_2", 
		"Action=http://learning2.pflb.ru:56902/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=http://learning2.pflb.ru:56902/login", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_add_cookie("currentCompany=0; DOMAIN=learning2.pflb.ru");

	web_add_cookie("currentUser={Login}; DOMAIN=learning2.pflb.ru");

	web_add_cookie("PFLB.pre.login.link=null; DOMAIN=learning2.pflb.ru");

	web_add_cookie("filterSetting="
		"%7B%22page%22%3A%22http%3A%2F%2Flearning2.pflb.ru%3A56902%2F%23tickets%3Fstate%3Dopened%26page%3D1%22%2C%22smho%22%3Anull%2C%22dateStart%22%3A%22%22%2C%22dateEnd%22%3A%22%22%2C%22cat1%22%3Anull%2C%22cat2%22%3Anull%2C%22cat3%22%3Anull%2C%22cat4%22%3Anull%2C%22theme%22%3Anull%2C%22engineer%22%3Anull%2C%22location%22%3Anull%2C%22division%22%3Anull%2C%22overdue%22%3Afalse%2C%22filters%22%3A%7B%22newCheckbox%22%3Atrue%2C%22appointedCheckbox%22%3Atrue%2C%22performedCheckbox%22%3Atrue%2C%22controlCheckbo"
		"x%22%3Atrue%7D%7D; DOMAIN=learning2.pflb.ru");

	web_url("learning2.pflb.ru:56902_2", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/login", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin", 
		"URL=http://learning2.pflb.ru:56902/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info", 
		"URL=http://learning2.pflb.ru:56902/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);

	lr_start_transaction("UC01_TR02_Create_incident");

	web_url("children", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
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
		"URL=http://learning2.pflb.ru:56902/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	
	shopID_index = rand() % atoi(lr_eval_string("{shopIDs_count}")) + 1;
	
	lr_save_string(lr_paramarr_idx("shopIDs", shopID_index), "shopID");

	web_url("shops_2", 
		"URL=http://learning2.pflb.ru:56902/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
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
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
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
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/treeview?shopid={shopID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
	
	j = rand() % atoi(lr_eval_string("{serviceIdS_count}")) + 1;
	
	lr_save_string(lr_paramarr_idx("serviceIdS", j), "serviceId");
		
	web_url("children_3", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/146/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("service", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/146/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("146", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/breadcrumbs/146", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
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
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?serviceId={serviceId}&shopId={shopID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_think_time(5);

	web_url("inventoryNumbers_2", 
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?shopId={shopID}&serviceId={serviceId}&serviceId=2782&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(42);

	web_reg_save_param_json(
        "ParamName=FileID",
        "QueryString=$..id",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_submit_data("file", 
		"Action=http://learning2.pflb.ru:56902/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value={File}", "File=yes", ENDITEM, 
		LAST);
	
	lr_think_time(8);

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
		"URL=http://learning2.pflb.ru:56902/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"BodyBinary={c_buffer}", 
		LAST);
	
	 FileVarriable = fopen (FileLocation,"w+");
     fprintf (FileVarriable, "%s \n", lr_eval_string("{ID}")); 
     fclose (FileVarriable);
	
	web_revert_auto_header("X-Requested-With");

	lr_think_time(7);

	web_url("learning2.pflb.ru:56902_3", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin_2", 
		"URL=http://learning2.pflb.ru:56902/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info_2", 
		"URL=http://learning2.pflb.ru:56902/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_3", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket_3", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("ticket_4", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC01_TR03_Incident_data",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("UC01_TR04_Logout");

	web_url("logout", 
		"URL=http://learning2.pflb.ru:56902/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_url("login_3", 
		"URL=http://learning2.pflb.ru:56902/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_Logout",LR_AUTO);

	return 0;
}