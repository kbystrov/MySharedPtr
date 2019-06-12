#include "ProxyPtr.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

template<typename DataT>
ProxyPtr<DataT>::ProxyPtr(DataT * ptr) {

    resource_ = ptr;

    if(ptr) {
        refCount_ = 1;
    #ifdef PROJ_DEBUG
    } else {
        errno = ERR_PROXYPTR_CTR_RES;
    }
    #endif // !PROJ_DEBUG

}

template<typename DataT>
ProxyPtr<DataT>::~ProxyPtr() {
    delete resource_;
    resource_ = nullptr;
    refCount_ = 0;
}