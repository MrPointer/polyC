//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_FUNCINTERFACES_H
#define POLYC_FUNCINTERFACES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Interface.h>

//========= No Args =========
DECLARE_FUNC(int, funcNoArgs)

DECLARE_INTERFACE(NoArgsFuncInterface, funcNoArgs)

//========= Single Arg =========
DECLARE_FUNC(int, funcSingleArg, int)

DECLARE_INTERFACE(SingleArgFuncInterface, funcSingleArg)

#ifdef __cplusplus
}
#endif
#endif //POLYC_FUNCINTERFACES_H