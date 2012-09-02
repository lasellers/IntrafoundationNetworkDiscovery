// NetworkDiscovery.cpp : Implementation of CNetworkDiscoveryCOMApp and DLL registration.

#include "stdafx.h"
#include "NetworkDiscoveryCOM.h"
#include "NetworkDiscovery.h"

//
#include "LANDiscovery.h"

//
const char *description="Intrafoundation.NetworkDiscovery.1";
const char *copyright="Copyright (c) 2004, 2012 by Lewis Sellers. <a href=\"http://www.intrafoundation.com\">http://www.intrafoundation.com</a>";
const char *version="1.3a, August 30th 2012";

//
int CNetworkDiscovery::m_last_instance=0;

/////////////////////////////////////////////////////////////////////////////
//
//
CNetworkDiscovery::CNetworkDiscovery()
{
	m_instance=++m_last_instance;
}


CNetworkDiscovery::~CNetworkDiscovery()
{
}


/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CNetworkDiscovery::get_description(BSTR* pstr)
{
	CComBSTR bstrtmp(description);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_copyright(BSTR* pstr)
{
	CComBSTR bstrtmp(copyright);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_version(BSTR* pstr)
{
	CComBSTR bstrtmp(version);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_thread(long* pVal)
{
	DWORD tid=GetCurrentThreadId();
	*pVal=(long)tid;
	
	return S_OK;
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_instance(long* pVal)
{
	*pVal=(long)m_instance;
	return S_OK;
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_instances(long* pVal)
{
	*pVal=(long)m_last_instance;
	return S_OK;
}

/*
*/
STDMETHODIMP CNetworkDiscovery::get_Log(BSTR* pstr)
{
	CComBSTR bstrtmp(log.Logs());
	if(!bstrtmp)
		return E_OUTOFMEMORY;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::ClearLog()
{
	log.Clear();
	
	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CNetworkDiscovery::Computer(BSTR* pstr)
{
	CLANDiscovery u;
	char *szcomputer=NULL;
	u.Computer(szcomputer);
	if(!szcomputer)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CNetworkDiscovery::Computer",
			L"Memory allocation for computer name failed.");
		*pstr=SysAllocString(L"");
		return E_OUTOFMEMORY;
	}
	else
	{
		CComBSTR bstrtmp(szcomputer);
		if(!bstrtmp)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CNetworkDiscovery::Computer",
				L"Memory allocation for conversion of computer name to BSTR failed.");
			*pstr=SysAllocString(L"");
			return E_OUTOFMEMORY;
		}
		else
		{
			*pstr=bstrtmp.Detach();
			return S_OK;
		}
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::ComputerIP(BSTR* pstr)
{
	CLANDiscovery u;
	char *szcomputer=NULL;
	u.ComputerIP(szcomputer);
	if(!szcomputer)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CNetworkDiscovery::ComputerIP",
			L"Memory allocation for computer name failed.");
		*pstr=SysAllocString(L"<EMPTY1>");
		return E_OUTOFMEMORY;
	}
	else
	{
		CComBSTR bstrtmp(szcomputer);
		if(!bstrtmp)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CNetworkDiscovery::ComputerIP",
				L"Memory allocation for conversion of computer name to BSTR failed.");
			*pstr=SysAllocString(L"<EMPTY2>");
			return E_OUTOFMEMORY;
		}
		else
		{
			*pstr=bstrtmp.Detach();
			return S_OK;
		}
	}
}

/*
*/
STDMETHODIMP CNetworkDiscovery::NetworkComputers(BSTR* pstr)
{
	CLANDiscovery u;
	char *szcomputers=NULL;
	int count=u.NetworkComputers(szcomputers);



	wchar_t szw1[202];
	_snwprintf(szw1,200,L"count=%d",count);
	CA2W  szw2(szcomputers);
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			szw1,
			szw2);


	if(!szcomputers)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CNetworkDiscovery::NetworkComputers",
			L"Memory allocation for network computer name failed.");
		*pstr=SysAllocString(L"");
		return E_OUTOFMEMORY;
	}
	else
	{
		CComBSTR bstrtmp(szcomputers);
		if(!bstrtmp)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CNetworkDiscovery::NetworkComputers",
				L"Memory allocation for conversion of network computer names to BSTR failed.");
			*pstr=SysAllocString(L"");
			return E_OUTOFMEMORY;
		}
		else
		{
			*pstr=bstrtmp.Detach();
			return S_OK;
		}
	}
}


/*
*/
STDMETHODIMP CNetworkDiscovery::NetworkComputersIP(BSTR* pstr)
{
	CLANDiscovery u;
	char *szcomputers=NULL;
	u.NetworkComputersIP(szcomputers);
	if(!szcomputers)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CNetworkDiscovery::NetworkComputersIP",
			L"Memory allocation for network computer name failed.");
		*pstr=SysAllocString(L"");
		return E_OUTOFMEMORY;
	}
	else
	{
		CComBSTR bstrtmp(szcomputers);
		if(!bstrtmp)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CNetworkDiscovery::NetworkComputersIP",
				L"Memory allocation for conversion of network computer names to BSTR failed.");
			*pstr=SysAllocString(L"");
			return E_OUTOFMEMORY;
		}
		else
		{
			*pstr=bstrtmp.Detach();
			return S_OK;
		}
	}
}
