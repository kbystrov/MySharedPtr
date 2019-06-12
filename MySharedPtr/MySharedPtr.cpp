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
MySharedPtr<DataT>::MySharedPtr(const MySharedPtr<DataT>& rhs) { ///< Copy constructor

    if(rhs.proxy_ptr_ && rhs.proxy_ptr_->resource_){
        proxy_ptr_ = rhs.proxy_ptr_;
        proxy_ptr_->refCount_++;
    } else {
        proxy_ptr_ = new ProxyPtr<DataT>(nullptr);
    }

}

template<typename DataT>
MySharedPtr<DataT>& MySharedPtr<DataT>::operator=(const MySharedPtr<DataT>& rhs) { ///< Copy assignment operator

    if(this != &rhs) { ///< Preventing redundant copy in self-assignment operation
        this->~MySharedPtr();
        new(this) MySharedPtr(rhs);
    }

    return *this;
}

template<typename DataT>
MySharedPtr<DataT>::~MySharedPtr() {

    if(proxy_ptr_){
        if(proxy_ptr_->refCount_ <= 1){
            delete proxy_ptr_;
            proxy_ptr_ = nullptr;
        } else {
            proxy_ptr_->refCount_--;
        }
    }

}
