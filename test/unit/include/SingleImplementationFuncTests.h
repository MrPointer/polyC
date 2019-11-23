//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_SINGLEIMPLEMENTATIONFUNCTESTS_H
#define POLYC_SINGLEIMPLEMENTATIONFUNCTESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Interface.h>

int funcNoArgsImpl();

DECLARE_FUNC(funcNoArgs, int)

DECLARE_INTERFACE(NoArgsFuncInterface, funcNoArgs)

DECLARE_IMPLEMENTATION(NoArgsFuncInterfaceImpl, NoArgsFuncInterface)

int funcSingleArgImpl(int arg);

DECLARE_FUNC(funcSingleArg, int, int)

DECLARE_INTERFACE(SingleArgFuncInterface, funcSingleArg)

DECLARE_IMPLEMENTATION(SingleArgFuncInterfaceImpl, SingleArgFuncInterface)

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONFUNCTESTS_H