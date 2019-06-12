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

/*
template<typename DataT>
void ProxyPtr<DataT>::setResource(DataT * resource) {
    resource_ = resource;
}

template<typename DataT>
DataT * ProxyPtr<DataT>::getResource() const {
    return resource_;
}

template<typename DataT>
void ProxyPtr<DataT>::operator++() {
    refCount_++;
}

template<typename DataT>
void ProxyPtr<DataT>::operator--() {
    refCount_--;
}
*/