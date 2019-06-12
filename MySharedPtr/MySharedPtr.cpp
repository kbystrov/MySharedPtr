#include "MySharedPtr.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

template<typename DataT>
MySharedPtr<DataT>::MySharedPtr(DataT * resource) {
    #ifdef PROJ_DEBUG
    errno = 0;
    #endif // !PROJ_DEBUG

    proxy_ptr_ = new ProxyPtr<DataT>(resource);
}

template<typename DataT>
MySharedPtr<DataT>::MySharedPtr<DataT>(const MySharedPtr<DataT>& rhs) {

}

template<typename DataT>
MySharedPtr<DataT> &MySharedPtr<DataT>::operator=(const MySharedPtr<DataT> &rhs) {
    return <#initializer#>;
}

template<typename DataT>
MySharedPtr<DataT>::~MySharedPtr() {

    if(proxy_ptr_){
        if(proxy_ptr_->refCount_ =< 1){
            delete proxy_ptr_;
            proxy_ptr_ = nullptr;
        } else {
            proxy_ptr_->refCount_--;
        }
    }

}
