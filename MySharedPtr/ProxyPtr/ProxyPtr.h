#ifndef MYSHAREDPTR_PROXYPTR_H
#define MYSHAREDPTR_PROXYPTR_H

#include <stdint.h>
#include "err_codes.h"
#include "proj_macros.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

//! @def Type of counters for number of pointers to shared resource
typedef uint32_t sizeT;

//! @class Proxy class to get access to shared resources through MySharedPtr(its included into the last)
template <typename DataT>
class ProxyPtr {
public:
    sizeT refCount_ = 0;
    DataT * resource_ = nullptr;

    ProxyPtr(DataT * ptr);
    ~ProxyPtr();
};

#include "ProxyPtr.hpp"

#endif //MYSHAREDPTR_PROXYPTR_H
