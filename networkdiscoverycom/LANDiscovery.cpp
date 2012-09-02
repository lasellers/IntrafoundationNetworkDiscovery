// LANDiscovery.cpp: implementation of the CLANDiscovery class.
//
//////////////////////////////////////////////////////////////////////
/*

Simple network discovery functions for LANs.

*/

// mpr.lib ws2_32.lib netapi32.lib 

#include "stdafx.h"

#include "windows.h" //uchar,etc
//#include "winsock2.h" //gethostname,etc

#include "nb30.h" //netbios

//
#include "LANDiscovery.h"

#include "ErrorStringWSA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLANDiscovery::CLANDiscovery()
{
	m_connected=false;

	load_winsock();
}

CLANDiscovery::~CLANDiscovery()
{
	unload_winsock();
}


/*
*/
void CLANDiscovery::load_winsock()
{
#ifdef _DEBUG
	printf("CLANDiscovery::load_winsock\n\n");
#endif

	//verify the winsock version is at least version 2.0
	WORD wVersionRequested=MAKEWORD(2,0);
	WSADATA wsaData;
	int err=WSAStartup(wVersionRequested,&wsaData);
	if(err != 0)
	{
		// abort if less than 2.0
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::load_winsock",
			L"Current winsock is version %d.%d, but require at least 2.0. WSAStartup failure, (%d) (%s).",
			LOBYTE(wsaData.wVersion),
			HIBYTE(wsaData.wVersion),
			err,
			CErrorStringWSA::ErrorString(err));
		m_connected=false;
		return;
	}

#ifdef _DEBUG
	printf("Current winsock version %d.%d\n",LOBYTE(wsaData.wVersion),HIBYTE(wsaData.wVersion));
#endif
	if(LOBYTE(wsaData.wVersion) < 2 && HIBYTE(wsaData.wVersion) < 0)
		// contine but warn if greater than 2.0
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"CLANDiscovery::load_winsock",
		L"Warning: Current winsock is version %d.%d, but class designed for 2.0.",
		LOBYTE(wsaData.wVersion),
		HIBYTE(wsaData.wVersion));
}


/*
*/
void CLANDiscovery::unload_winsock()
{
#ifdef _DEBUG
	printf("CLANDiscovery::unload_winsock\n\n");
#endif

	int const err=WSACleanup();
	if(err==SOCKET_ERROR)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::unload_winsock",
			L"WSACleanup can not close winsock: (%d) (%s).",
			err,
			CErrorStringWSA::ErrorString(err));
	}
}




/*
Returns the NAME of _this_ computer.
*/
void CLANDiscovery::Computer(
	char* &sz
	)
{
#ifdef _DEBUG
	printf("\nCLANDiscovery::Computer sz=%p\n",sz);
#endif

	//
	delete[] sz;
	sz=NULL;

	//
	char szcomputername[MAX_COMPUTERNAME_LENGTH + 1];
	unsigned long cnlength=sizeof(szcomputername);

	//
#ifdef _UNICODE
	wchar_t wszcomputername[MAX_COMPUTERNAME_LENGTH + 1];
	GetComputerName(wszcomputername,&cnlength);
	wcstombs(szcomputername,wszcomputername,MAX_COMPUTERNAME_LENGTH);
#else
	GetComputerName(szcomputername,&cnlength);
#endif

#ifdef _DEBUG
	printf("computer=%s\n",szcomputername);
#endif

	//
	sz=new char[cnlength+1];
	if(sz==NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::Computer",
			L"Memory allocation of %d bytes failed.",
			cnlength+1);
		return;
	}

	//
	strcpy(sz,szcomputername);

#ifdef _DEBUG
	printf("sz=%s\n",sz);
#endif
}


/*
Returns the IP or NAME of _this_ computer.
*/
void CLANDiscovery::ComputerIP(
	char* &sz
	)
{
#ifdef _DEBUG
	printf("\nCLANDiscovery::Computer sz=%p\n",sz);
#endif

	//
	delete[] sz;
	sz=NULL;

	//
	char szcomputername[MAX_COMPUTERNAME_LENGTH + 1];
	unsigned long cnlength=sizeof(szcomputername);

	//
	struct hostent* host;
	struct in_addr* ptr;

	//
	int const ret=gethostname(szcomputername,MAX_COMPUTERNAME_LENGTH); //strlen(szcomputername));
	if(ret==SOCKET_ERROR)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::Computer",
			L"gethostname failed. (%d) (%s).",
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		return;
	}

	//
	host=gethostbyname(szcomputername);
	if(host)
	{
		//
		ptr= (struct in_addr*)host->h_addr_list[0];

		//
		const int a=ptr->S_un.S_un_b.s_b1;
		const int b=ptr->S_un.S_un_b.s_b2;
		const int c=ptr->S_un.S_un_b.s_b3;
		const int d=ptr->S_un.S_un_b.s_b4;

		sz=new char[16+1];
		_snprintf(sz,16,"%d.%d.%d.%d",a,b,c,d);
		sz[16]='\0'; //buffer overrun protected (we hope)

#ifdef _DEBUG
		printf("%d.%d.%d.%d\n",a,b,c,d);
#endif
	}

#ifdef _DEBUG
	printf("sz=%s\n",sz);
#endif
}


/*
Returns the NAME of all computers networks connected to this computer.
*/
int CLANDiscovery::NetworkComputers(
	char* &sz
	)
{
#ifdef _DEBUG
	printf("\nCLANDiscovery::NetworkComputers sz=%p\n",sz);
#endif

	//
	delete[] sz;
	sz=NULL;

	//
	int computers=0;

	//
	NETRESOURCE* NetResource=NULL;
	HANDLE hEnum;
	WNetOpenEnum(RESOURCE_CONTEXT,RESOURCETYPE_ANY,NULL,NULL,&hEnum);
	if(hEnum==NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::NetworkComputers",
			L"Could not enumerate computer resources. NETBIOS may disabled, protocol blocked by firewall or Network disabled.");
		return 0;
	}
	else
	{
		//
		DWORD ResourceCount=0xFFFFFFFF;
		DWORD BufferSize=2048;
		LPVOID Buffer=new char[2048];
		WNetEnumResource(hEnum,&ResourceCount,Buffer,&BufferSize);
		NetResource= (NETRESOURCE*)Buffer;

		//
		if(ResourceCount<=0)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CLANDiscovery::NetworkComputers",
				L"Resource discovery returns %d computers. NETBIOS may disabled or protocol blocked by firewall.",
				ResourceCount);
			return 0;
		}

		//
		int const szlength=(32 + 1) * ResourceCount + 1;
		sz=new char[szlength+1];
		if(sz==NULL)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CLANDiscovery::NetworkComputers",
				L"Memory allocation of %d bytes failed.",
				szlength+1);
			return 0;
		}

		//
		sz[0]='\0';

		//
#ifdef _DEBUG
		printf("BufferSize=%d\n",BufferSize);
		printf("sizeof(NETRESOURCE)=%d\n",sizeof(NETRESOURCE));
		printf("ResourceCount=%d\n",ResourceCount);
#endif
		for(unsigned int i=0; i < ResourceCount; i++, NetResource++)
		{
#ifdef _DEBUG
			printf("%d] dwUsage=%d dwType=%d dwDisplayType=%d lpRemoteName=%p lpLocalName=%p %s\n",
				i,
				NetResource->dwUsage,
				NetResource->dwType,
				NetResource->dwDisplayType,
				NetResource->lpRemoteName,
				NetResource->lpLocalName,
				NetResource->lpLocalName);
#endif
			if(
				NetResource->dwUsage == RESOURCEUSAGE_CONTAINER &&
				NetResource->dwType == RESOURCETYPE_ANY
				)
			{
				if(NetResource->lpRemoteName)
				{
					//
					computers++;

					//
					char szRemoteName[256 + 1];
#ifdef _UNICODE
					size_t lenRemoteName=wcslen(NetResource->lpRemoteName);
					if(lenRemoteName>256) lenRemoteName=256;
					wcstombs(szRemoteName,NetResource->lpRemoteName,lenRemoteName);
#else
					int lenRemoteName=strlen(NetResource->lpRemoteName);
					if(lenRemoteName>256) lenRemoteName=256;
					strncpy(szRemoteName,NetResource->lpRemoteName,lenRemoteName);
#endif
					szRemoteName[lenRemoteName]='\0';

					char szFullName[256 + 1];
					if(strncmp(szRemoteName,"\\\\",2) == 0)
						strncpy(szFullName,(szRemoteName) + 2,lenRemoteName - 2 + 1);
					else
						strncpy(szFullName,szRemoteName,lenRemoteName + 1);
#ifdef _DEBUG
					printf(" lpRemoteName=%s\n",szRemoteName);
					printf(" szFullName=%s\n",szFullName);
#endif
					//
					strcat(sz,szFullName);
					if(i < ResourceCount - 1) strcat(sz,",");
				}
			}
		}

		//
		delete[] Buffer;
		Buffer=NULL;

		//
		WNetCloseEnum(hEnum);
	}

	return computers;
}



/*
Returns the IP of all computers networks connected to this computer.
*/
int CLANDiscovery::NetworkComputersIP(
	char* &sz
	)
{
#ifdef _DEBUG
	printf("\nCLANDiscovery::NetworkComputers sz=%p\n",sz);
#endif

	//
	delete[] sz;
	sz=NULL;

	//
	int computers=0;

	//
	NETRESOURCE* NetResource=NULL;
	HANDLE hEnum;
	WNetOpenEnum(RESOURCE_CONTEXT,RESOURCETYPE_ANY,NULL,NULL,&hEnum);
	if(hEnum==NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::NetworkComputersIP",
			L"Could not enumerate computer resources. NETBIOS may disabled, protocol blocked by firewall or Network disabled.");
		return 0;
	}
	else
	{
		//
		DWORD ResourceCount=0xFFFFFFFF;
		DWORD BufferSize=2048;
		LPVOID Buffer=new char[2048];
		WNetEnumResource(hEnum,&ResourceCount,Buffer,&BufferSize);
		NetResource= (NETRESOURCE*)Buffer;

		//
		if(ResourceCount<=0)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CLANDiscovery::NetworkComputersIP",
				L"Resource discovery returns %d computers.  NETBIOS may disabled or protocol blocked by firewall.",
				ResourceCount);
			return 0;
		}

		//
		int const szlength=(32 + 1) * ResourceCount + 1;
		sz=new char[szlength+1];
		if(sz==NULL)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CLANDiscovery::NetworkComputers",
				L"Memory allocation of %d bytes failed.",
				szlength+1);
			return 0;
		}

		//
		sz[0]='\0';

		//
		char szHostName[64 + 1];

		//
#ifdef _DEBUG
		printf("BufferSize=%d\n",BufferSize);
		printf("sizeof(NETRESOURCE)=%d\n",sizeof(NETRESOURCE));
		printf("ResourceCount=%d\n",ResourceCount);
#endif
		for(unsigned int i=0; i < ResourceCount; i++, NetResource++)
		{
			if(ResourceCount==1 && NetResource->dwDisplayType==7)
			{
				log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CLANDiscovery::NetworkComputersIP",
				L"There may to be a network configuration problem preventing network discovery. Run the test harness for comparison and/or contact your administrator: dwUsage=%d dwType=%d dwDisplayType=%d lpRemoteName=%p lpLocalName=%p %s.",
				NetResource->dwUsage,
				NetResource->dwType,
				NetResource->dwDisplayType,
				NetResource->lpRemoteName,
				NetResource->lpLocalName,
				NetResource->lpLocalName);
			}

#ifdef _DEBUG
			printf("%d] dwUsage=%d dwType=%d dwDisplayType=%d lpRemoteName=%p lpLocalName=%p %s\n",
				i,
				NetResource->dwUsage,
				NetResource->dwType,
				NetResource->dwDisplayType,
				NetResource->lpRemoteName,
				NetResource->lpLocalName,
				NetResource->lpLocalName);
#endif
			if(
				NetResource->dwUsage == RESOURCEUSAGE_CONTAINER &&
				NetResource->dwType == RESOURCETYPE_ANY
				)
			{
				if(NetResource->lpRemoteName)
				{
					//
					computers++;

					//
					char szRemoteName[256 + 1];
					//#ifdef _UNICODE
					size_t lenRemoteName=wcslen(NetResource->lpRemoteName);
					if(lenRemoteName>256) lenRemoteName=256;
					wcstombs(szRemoteName,NetResource->lpRemoteName,lenRemoteName);
					//#else
					//					int lenRemoteName=strlen(NetResource->lpRemoteName);
					//					if(lenRemoteName>256) lenRemoteName=256;
					//					strncpy(szRemoteName,NetResource->lpRemoteName,lenRemoteName);
					//#endif
					szRemoteName[lenRemoteName]='\0';

					char szFullName[256 + 1];
					if(strncmp(szRemoteName,"\\\\",2) == 0)
						strncpy(szFullName,(szRemoteName) + 2,lenRemoteName - 2 + 1);
					else
						strncpy(szFullName,szRemoteName,lenRemoteName + 1);
#ifdef _DEBUG
					printf(" lpRemoteName=%s\n",szRemoteName);
					printf(" szFullName=%s\n",szFullName);
#endif
					//
					struct hostent* host;
					struct in_addr* ptr;

					gethostname(szHostName,(int)strlen(szHostName));
#ifdef _DEBUG
					printf(" szHostName=%s\n",szHostName);
#endif
					host=gethostbyname(szFullName);
					if(host)
					{
						//
						ptr= (struct in_addr*)host->h_addr_list[0];

						//
						const int a=ptr->S_un.S_un_b.s_b1;
						const int b=ptr->S_un.S_un_b.s_b2;
						const int c=ptr->S_un.S_un_b.s_b3;
						const int d=ptr->S_un.S_un_b.s_b4;

						char tmp[18 + 1];
						_snprintf(tmp,18,"%d.%d.%d.%d",a,b,c,d);
						strcat(sz,tmp);
						if(i < ResourceCount - 1) strcat(sz,",");

#ifdef _DEBUG
						printf(" %d] %s -->  %d.%d.%d.%d\n",i,szFullName,a,b,c,d);
#endif
					}
				}
			}
		}

		//
		delete[] Buffer;
		Buffer=NULL;

		//
		WNetCloseEnum(hEnum);
	}

	return computers;
}


void CLANDiscovery::get_log(
	char* &sz
	)
{
#ifdef _DEBUG
	printf("\nCLANDiscovery::NetworkComputers sz=%p\n",sz);
#endif

	//
	delete[] sz;
	sz=NULL;

	//
	int const szlength=4096;
	sz=new char[szlength+1];
	if(sz==NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CLANDiscovery::NetworkComputers",
			L"Memory allocation of %d bytes failed.",
			szlength+1);
		return;
	}
	sz[0]='\0';

	//
	sprintf(sz,"%s",log.Logs());
}