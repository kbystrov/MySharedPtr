#ifndef MYSHAREDPTR_MYSHAREDPTR_H
#define MYSHAREDPTR_MYSHAREDPTR_H

#include <ProxyPtr/ProxyPtr.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

//! @class My own implementation of shared_ptr - smart pointer to manages resource may be referenced by many pointers
template <typename DataT>
class MySharedPtr {
private:
    ProxyPtr<DataT> * proxy_ptr_ = nullptr; ///< @param Proxy class which contain control block of shared resource (count of "references" to it and pointer to it)
public:
    explicit MySharedPtr(DataT * resource = nullptr);              ///< Default constructor
    MySharedPtr<DataT>(const MySharedPtr<DataT>& rhs); ///< Copy constructor
    MySharedPtr<DataT>& operator= (const MySharedPtr<DataT>& rhs); ///< Copy assignment operator

    ~MySharedPtr();
};


#endif //MYSHAREDPTR_MYSHAREDPTR_H
