net stop "ColdFusion MX Application Server"
net stop "ColdFusion MX ODBC Agent"
net stop "ColdFusion MX ODBC Server"
net stop iisadmin /y
net stop w3svc

net start iisadmin /y
net start w3svc
net start "ColdFusion MX Application Server"
net start "ColdFusion MX ODBC Agent"
net start "ColdFusion MX ODBC Server"

