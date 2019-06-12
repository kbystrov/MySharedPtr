#ifndef MYSHAREDPTR_ERR_CODES_H
#define MYSHAREDPTR_ERR_CODES_H

#include <errno.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

//!@enum Enumeration of error codes
enum Errors{
    //! Error code is unknown
    ERR_UNKNOWN = -1,
    //! Error code: ProxyPtr<DataT>::ProxyPtr(DataT * ptr)  -> ptr is nullptr
    ERR_PROXYPTR_CTR_RES = 1,
};

#endif //MYSHAREDPTR_ERR_CODES_H
