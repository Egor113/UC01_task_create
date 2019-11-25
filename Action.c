Action()
{

	web_url("learning2.pflb.ru:56902", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/css/fonts/roboto/Roboto-Thin.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Light.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Regular.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Medium.eot?", ENDITEM, 
		"Url=/css/fonts/roboto/Roboto-Bold.eot?", ENDITEM, 
		"Url=/js/core/jqueryformplugin.js?_=1574678972329", ENDITEM, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_add_cookie("sessionExpired=true; DOMAIN=learning2.pflb.ru");

	web_add_cookie("SRCHUID=V=2&GUID=225AA72D8B8C4225A329ED28D9C749D5&dmnchg=1; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("MC1=GUID=2c29678b14674620829ea1e367e840d9&HASH=2c29&LV=201910&V=4&LU=1570625008555; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20190711; DOMAIN=c.urs.microsoft.com");

	web_url("login", 
		"URL=http://learning2.pflb.ru:56902/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/tpl/login/login.dust", ENDITEM, 
		"Url=/images/logo_2.png", ENDITEM, 
		"Url=https://c.urs.microsoft.com/l1.dat?cw=637099391076908467&v=3&cv=9.11.17763.0&os=10.0.17763.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_cookie("SRCHUID=V=2&GUID=225AA72D8B8C4225A329ED28D9C749D5&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MC1=GUID=2c29678b14674620829ea1e367e840d9&HASH=2c29&LV=201910&V=4&LU=1570625008555; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20190711; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

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

	web_add_cookie("sessionExpired=false; DOMAIN=learning2.pflb.ru");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(87);

	web_submit_data("login_2", 
		"Action=http://learning2.pflb.ru:56902/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=http://learning2.pflb.ru:56902/login", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value=master", ENDITEM, 
		"Name=password", "Value=123", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_add_cookie("currentCompany=0; DOMAIN=learning2.pflb.ru");

	web_add_cookie("currentUser=master; DOMAIN=learning2.pflb.ru");

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
		EXTRARES, 
		"Url=/js/core/jqueryformplugin.js?_=1574679101664", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.dust", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.js", ENDITEM, 
		"Url=/css/fonts/material_icons/MaterialIcons-Regular.woff", ENDITEM, 
		"Url=/engineer/tickets/tickets.dust", ENDITEM, 
		"Url=/engineer/tickets/tickets.js", ENDITEM, 
		"Url=/engineer/catalog/catalog.dust", ENDITEM, 
		"Url=/engineer/catalog/catalog.js", ENDITEM, 
		"Url=/images/logo-5ka.png", ENDITEM, 
		"Url=/engineer/addticket.dust", ENDITEM, 
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

	web_url("shops", 
		"URL=http://learning2.pflb.ru:56902/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("shops_2", 
		"URL=http://learning2.pflb.ru:56902/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
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

	web_url("treeview", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/treeview?shopid=4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

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

	web_url("inventoryNumbers", 
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?serviceId=2782&shopId=4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("inventoryNumbers_2", 
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?shopId=4&serviceId=2782&serviceId=2782&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(42);

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
		"Name=files", "Value=file.txt", "File=Yes", ENDITEM, 
		LAST);

	lr_think_time(8);

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
		"BodyBinary={\"text\":\"Some action\",\"header\":\"\\xD0\\x9E\\xD1\\x82\\xD1\\x81\\xD1\\x83\\xD1\\x82\\xD1\\x81\\xD1\\x82\\xD0\\xB2\\xD0\\xB8\\xD0\\xB5 \\xD1\\x83\\xD0\\xB1\\xD0\\xBE\\xD1\\x80\\xD0\\xBA\\xD0\\xB8 \\xD0\\xBF\\xD1\\x80\\xD0\\xB8\\xD0\\xBB\\xD0\\xB5\\xD0\\xB3\\xD0\\xB0\\xD1\\x8E\\xD1\\x89\\xD0\\xB5\\xD0\\xB9 \\xD1\\x82\\xD0\\xB5\\xD1\\x80\\xD1\\x80\\xD0\\xB8\\xD1\\x82\\xD0\\xBE\\xD1\\x80\\xD0\\xB8\\xD0\\xB8\",\"ticketStateId\":0,\"serviceId\":\"2782\",\"files\":[4383],\""
		"inventoryNumberId\":\"6\",\"shopId\":\"4\"}", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	lr_think_time(7);

	web_url("learning2.pflb.ru:56902_3", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/core/jqueryformplugin.js?_=1574679445084", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.dust", ENDITEM, 
		"Url=/engineer/wrapper/wrapper.js", ENDITEM, 
		"Url=/engineer/tickets/tickets.dust", ENDITEM, 
		"Url=/engineer/tickets/tickets.js", ENDITEM, 
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