//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_INTERFACE_H
#define POLYC_INTERFACE_H

#include "utility/MacroUtils.h"
#include "Action.h"
#include "Func.h"

#define POLYC_INTERFACE_METHOD_SUFFIX _polyc_method

#define DECLARE_INTERFACE(name, method) \
        typedef struct name \
        { \
            CONCAT_TOKENS(method, POLYC_INTERFACE_METHOD_SUFFIX) (method); \
        } I##name;

#define DECLARE_MULTI_INTERFACE(name, method1, method2) \
        typedef struct name \
        { \
            CONCAT_TOKENS(method1, POLYC_INTERFACE_METHOD_SUFFIX) (method1); \
            CONCAT_TOKENS(method2, POLYC_INTERFACE_METHOD_SUFFIX) (method2); \
        } I##name;

#endif