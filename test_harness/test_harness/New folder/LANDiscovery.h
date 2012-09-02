// LAN.h: interface for the CLANDiscovery class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(CLANDiscovery_H)
#define CLANDiscovery_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//
//#include "winsock2.h"
//project/settings/object/link: ws2_32.lib 

//
#include "Log.h"

//
class CLANDiscovery
{
public:
	CLog log;

public:
	CLANDiscovery();
	virtual ~CLANDiscovery();
	
	void load_winsock();
	void unload_winsock();
	
	void Computer(char* &sz);
	int NetworkComputers(char* &sz);
	void ComputerIP(char* &sz);
	int NetworkComputersIP(char* &sz);
	
private:
	bool m_connected;
};

#endif
