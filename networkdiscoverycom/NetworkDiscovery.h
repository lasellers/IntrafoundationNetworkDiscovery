// NetworkDiscovery.h: Definition of the CNetworkDiscovery class
//
//////////////////////////////////////////////////////////////////////

#if !defined(NETWORKDISCOVERY_H)
#define NETWORKDISCOVERY_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

//
#include "Log.h"

/////////////////////////////////////////////////////////////////////////////
// CNetworkDiscovery

class CNetworkDiscovery : 
	public IDispatchImpl<INetworkDiscovery, &IID_INetworkDiscovery, &LIBID_NETWORKDISCOVERYCOMLib>, 
	public CComObjectRoot,
	public CComCoClass<CNetworkDiscovery,&CLSID_NetworkDiscovery>
{
public:
	CNetworkDiscovery();
	virtual ~CNetworkDiscovery();

	BEGIN_COM_MAP(CNetworkDiscovery)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(INetworkDiscovery)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_NetworkDiscovery)

// INetworkDiscovery
public:
	STDMETHOD(get_thread)(long* pVal);
	STDMETHOD(get_version)(BSTR* pstr);
	STDMETHOD(get_copyright)(BSTR* pstr);
	STDMETHOD(get_description)(BSTR* pstr);
	STDMETHODIMP get_instance(long* pVal);
	STDMETHODIMP get_instances(long* pVal);
	STDMETHODIMP get_Log(BSTR* pstrText);
	STDMETHOD(ClearLog)();

	STDMETHODIMP Computer(BSTR* pstr);
	STDMETHODIMP NetworkComputers(BSTR* pstr);
	STDMETHODIMP ComputerIP(BSTR* pstr);
	STDMETHODIMP NetworkComputersIP(BSTR* pstr);

public:
	CLog log;

private:
	int m_instance;
	static int m_last_instance;
};

#endif
