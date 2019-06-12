#ifndef MYSHAREDPTR_MYSHAREDPTR_H
#define MYSHAREDPTR_MYSHAREDPTR_H

#include <utility>
#include <ProxyPtr/ProxyPtr.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

//! @class My own implementation of shared_ptr - smart pointer to manages resource may be referenced by many pointers
template <typename DataT>
class MySharedPtr {
private:
    ProxyPtr<DataT> * proxy_ptr_ = nullptr; ///< @param Proxy class which contain control block of shared resource (count of "references" to it and pointer to it)
public:
    //! Constructors, destructors and copy assignment operators
    explicit MySharedPtr(DataT * resource = nullptr);              ///< Default constructor
    MySharedPtr<DataT>(const MySharedPtr<DataT>& rhs); ///< Copy constructor
    MySharedPtr<DataT>& operator= (const MySharedPtr<DataT>& rhs); ///< Copy assignment operator
    ~MySharedPtr(); ///< Destructor
    //! Observers member functions
    DataT * get() const; ///< Returns the stored pointer
    DataT operator*() const; ///< Dereference operator for the stored pointer
    DataT *operator->() const; ///< Returnes the stored pointer
    sizeT use_count() const; ///< Return number of MySharedPtr owned the same object as by this MySharedPtr
    explicit operator bool() const; ///< Checks if current MySharedPtr referenced to non-nullptr pointer
    //! Modifiers member functions
    void swap(MySharedPtr& rhs); ///< Swaps contents of MySharedPtr
    void reset(DataT * ptr = nullptr); ///< Replaces the managed object with an object pointed by the ptr
};


#endif //MYSHAREDPTR_MYSHAREDPTR_H
