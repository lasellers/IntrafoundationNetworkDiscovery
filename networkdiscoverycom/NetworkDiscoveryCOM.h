

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Sep 01 19:09:42 2012
 */
/* Compiler settings for NetworkDiscoveryCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NetworkDiscoveryCOM_h__
#define __NetworkDiscoveryCOM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INetworkDiscovery_FWD_DEFINED__
#define __INetworkDiscovery_FWD_DEFINED__
typedef interface INetworkDiscovery INetworkDiscovery;
#endif 	/* __INetworkDiscovery_FWD_DEFINED__ */


#ifndef __NetworkDiscovery_FWD_DEFINED__
#define __NetworkDiscovery_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetworkDiscovery NetworkDiscovery;
#else
typedef struct NetworkDiscovery NetworkDiscovery;
#endif /* __cplusplus */

#endif 	/* __NetworkDiscovery_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __INetworkDiscovery_INTERFACE_DEFINED__
#define __INetworkDiscovery_INTERFACE_DEFINED__

/* interface INetworkDiscovery */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INetworkDiscovery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BBFC9F3B-C4EC-4B53-86AA-D44B2CCC3B9E")
    INetworkDiscovery : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_thread( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_copyright( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_description( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instance( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instances( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Log( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearLog( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Computer( 
            /* [retval][out] */ BSTR *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NetworkComputers( 
            /* [retval][out] */ BSTR *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ComputerIP( 
            /* [retval][out] */ BSTR *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NetworkComputersIP( 
            /* [retval][out] */ BSTR *bytes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkDiscoveryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkDiscovery * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkDiscovery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkDiscovery * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetworkDiscovery * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetworkDiscovery * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetworkDiscovery * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetworkDiscovery * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_thread )( 
            INetworkDiscovery * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_copyright )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_description )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instance )( 
            INetworkDiscovery * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instances )( 
            INetworkDiscovery * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Log )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *pstrText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearLog )( 
            INetworkDiscovery * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Computer )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NetworkComputers )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ComputerIP )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NetworkComputersIP )( 
            INetworkDiscovery * This,
            /* [retval][out] */ BSTR *bytes);
        
        END_INTERFACE
    } INetworkDiscoveryVtbl;

    interface INetworkDiscovery
    {
        CONST_VTBL struct INetworkDiscoveryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkDiscovery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkDiscovery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkDiscovery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkDiscovery_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetworkDiscovery_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetworkDiscovery_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetworkDiscovery_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetworkDiscovery_get_thread(This,pVal)	\
    ( (This)->lpVtbl -> get_thread(This,pVal) ) 

#define INetworkDiscovery_get_version(This,pstr)	\
    ( (This)->lpVtbl -> get_version(This,pstr) ) 

#define INetworkDiscovery_get_copyright(This,pstr)	\
    ( (This)->lpVtbl -> get_copyright(This,pstr) ) 

#define INetworkDiscovery_get_description(This,pstr)	\
    ( (This)->lpVtbl -> get_description(This,pstr) ) 

#define INetworkDiscovery_get_instance(This,pVal)	\
    ( (This)->lpVtbl -> get_instance(This,pVal) ) 

#define INetworkDiscovery_get_instances(This,pVal)	\
    ( (This)->lpVtbl -> get_instances(This,pVal) ) 

#define INetworkDiscovery_get_Log(This,pstrText)	\
    ( (This)->lpVtbl -> get_Log(This,pstrText) ) 

#define INetworkDiscovery_ClearLog(This)	\
    ( (This)->lpVtbl -> ClearLog(This) ) 

#define INetworkDiscovery_Computer(This,bytes)	\
    ( (This)->lpVtbl -> Computer(This,bytes) ) 

#define INetworkDiscovery_NetworkComputers(This,bytes)	\
    ( (This)->lpVtbl -> NetworkComputers(This,bytes) ) 

#define INetworkDiscovery_ComputerIP(This,bytes)	\
    ( (This)->lpVtbl -> ComputerIP(This,bytes) ) 

#define INetworkDiscovery_NetworkComputersIP(This,bytes)	\
    ( (This)->lpVtbl -> NetworkComputersIP(This,bytes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkDiscovery_INTERFACE_DEFINED__ */



#ifndef __NETWORKDISCOVERYCOMLib_LIBRARY_DEFINED__
#define __NETWORKDISCOVERYCOMLib_LIBRARY_DEFINED__

/* library NETWORKDISCOVERYCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NETWORKDISCOVERYCOMLib;

EXTERN_C const CLSID CLSID_NetworkDiscovery;

#ifdef __cplusplus

class DECLSPEC_UUID("28E25814-C783-4416-96BF-FFD37F81B2CC")
NetworkDiscovery;
#endif
#endif /* __NETWORKDISCOVERYCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


