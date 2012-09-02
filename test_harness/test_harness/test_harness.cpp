// test_harness.cpp : Defines the entry point for the console application.
//
/*
// UDPClient.cpp : Implementation of CUDPClient
#include "stdafx.h"
#include "udpclientcom.h"
#include "UDPClient.h"

/////////////////////////////////////////////////////////////////////////////
// CUDPClient

// _open file handling
#include "io.h"
#include <fcntl.h>

//bstr
#include <comdef.h>

// _stat
#include "sys\stat.h"

// wnet*
//Header: Declared in winnetwk.h.
//Import Library: Use mpr.lib.

//
#include "Log.h"*/

#include "stdafx.h"

//#include "windows.h"
//#include "stdio.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

//#include <comdef.h> //BSTR
#include "sys\stat.h" // _stat

//
#include "string.h"
#include <time.h>
#include <conio.h>

//
//#include "..\..\udpclientcom\udp.h"
#include "..\..\networkdiscoverycom\Log.h"
#include "..\..\networkdiscoverycom\LANDiscovery.h"

//#include "Log.h"
//#include "LANDiscovery.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("This is a networkdiscovery class debugging test harness.\n");

	///////////////////////////////////////////////////////////////////////////
	printf("-------------------------------------------\n");
	printf("Checking network...\n\n");
	{
		CLANDiscovery u;
			printf("networkdiscovery opened.\n");

			//
			printf("\n-------------------------------------------\n");
			char *szcomputer=NULL;
			u.Computer(szcomputer);
			printf("computer: %s\n",szcomputer);

			//
			printf("\n-------------------------------------------\n");
			char *szip=NULL;
			u.ComputerIP(szip);
			printf("ip: %s\n",szip);

			//
			printf("\n-------------------------------------------\n");
			char *szcomputers=NULL;
			u.NetworkComputers(szcomputers);
			printf("computers: %s\n",szcomputers);

			//
			printf("\n-------------------------------------------\n");
			char *szips=NULL;
			u.NetworkComputersIP(szips);
			printf("ip: %s\n",szips);

			//
			printf("\n-------------------------------------------\n");
			printf("closing networkdiscovery.\n");

			char *szerrors=NULL;
			u.get_log(szerrors);
			printf("Errors: %s\n",szerrors);
	}
	
	printf("PRESS"); _getch();
	return 0;
}

