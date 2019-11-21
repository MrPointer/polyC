//
// Created by Timor Gruber on 11/22/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_SINGLEIMPLEMENTATIONTESTS_H
#define POLYC_SINGLEIMPLEMENTATIONTESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Interface.h>

void actionImpl();

DECLARE_ACTION(action)

DECLARE_INTERFACE(SingleNoArgActionInterface, action)

DECLARE_IMPLEMENTATION(SingleNoArgActionInterfaceImpl, SingleNoArgActionInterface)

int funcImpl();

DECLARE_FUNC(func, int)

DECLARE_INTERFACE(SingleNoArgFuncInterface, func)

DECLARE_IMPLEMENTATION(SingleNoArgFuncInterfaceImpl, SingleNoArgFuncInterface)

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONTESTS_H