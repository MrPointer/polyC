//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_ACTION_H
#define POLYC_ACTION_H

#include "utility/MacroUtils.h"
#include "Method.h"

#define DECLARE_ACTION(...) VFUNC(DECLARE_ACTION, __VA_ARGS__)

#define DECLARE_ACTION1(name) typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();
#define DECLARE_ACTION2(name, arg1) \
        typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(arg1 a1);
#define DECLARE_ACTION3(name, arg1, arg2) \
        typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(arg1 a1, arg2 a2);

#endif //POLYC_ACTION_H
