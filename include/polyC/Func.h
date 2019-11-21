//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_FUNC_H
#define POLYC_FUNC_H

#include "utility/MacroUtils.h"
#include "Method.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_FUNC(name, ...) VFUNC1(DECLARE_FUNC, name,  __VA_ARGS__)

#define DECLARE_FUNC1(name, returnType) typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();
#define DECLARE_FUNC2(name, returnType, arg1) \
        typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(arg1 a1);
#define DECLARE_FUNC3(name, returnType, arg1, arg2) \
        typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(arg1 a1, arg2 a2);

#ifdef __cplusplus
}
#endif

#endif //POLYC_FUNC_H
