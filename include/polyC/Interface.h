//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_INTERFACE_H
#define POLYC_INTERFACE_H

#include "utility/MacroUtils.h"
#include "Action.h"
#include "Func.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_INTERFACE(name, ...) VFUNC1(DECLARE_INTERFACE, name, __VA_ARGS__);

#define DECLARE_INTERFACE1(name, method1) \
        typedef struct name##_t \
        { \
            CONCAT_TOKENS(method1, POLYC_INTERFACE_METHOD_SUFFIX) (method1); \
        } name;
#define DECLARE_INTERFACE2(name, method1, method2) \
        typedef struct name##_t \
        { \
            CONCAT_TOKENS(method1, POLYC_INTERFACE_METHOD_SUFFIX) (method1); \
            CONCAT_TOKENS(method2, POLYC_INTERFACE_METHOD_SUFFIX) (method2); \
        } name;

#ifdef __cplusplus
}
#endif

#endif