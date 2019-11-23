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
#include "FuncInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgsFuncInterfaceImpl, NoArgsFuncInterface)

int funcNoArgsImpl();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgFuncInterfaceImpl, SingleArgFuncInterface)

int funcSingleArgImpl(int arg);

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONFUNCTESTS_H