//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_MULTIIMPLEMENTATIONFUNCTESTS_H
#define POLYC_MULTIIMPLEMENTATIONFUNCTESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Implementation.h>
#include "FuncInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgsFuncInterfaceImpl1, NoArgsFuncInterface)
DECLARE_IMPLEMENTATION(NoArgsFuncInterfaceImpl2, NoArgsFuncInterface)
DECLARE_IMPLEMENTATION(NoArgsFuncInterfaceImpl3, NoArgsFuncInterface)

int funcNoArgsImpl1();
int funcNoArgsImpl2();
int funcNoArgsImpl3();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgFuncInterfaceImpl1, SingleArgFuncInterface)
DECLARE_IMPLEMENTATION(SingleArgFuncInterfaceImpl2, SingleArgFuncInterface)
DECLARE_IMPLEMENTATION(SingleArgFuncInterfaceImpl3, SingleArgFuncInterface)

int funcSingleArgImpl1(int arg);
int funcSingleArgImpl2(int arg);
int funcSingleArgImpl3(int arg);

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_MULTIIMPLEMENTATIONFUNCTESTS_H