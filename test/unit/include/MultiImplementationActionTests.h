//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_MULTIIMPLEMENTATIONACTIONTESTS_H
#define POLYC_MULTIIMPLEMENTATIONACTIONTESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Implementation.h>
#include "ActionInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgsActionInterfaceImpl1, NoArgsActionInterface)
DECLARE_IMPLEMENTATION(NoArgsActionInterfaceImpl2, NoArgsActionInterface)
DECLARE_IMPLEMENTATION(NoArgsActionInterfaceImpl3, NoArgsActionInterface)

void actionNoArgsImpl1();
void actionNoArgsImpl2();
void actionNoArgsImpl3();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgActionInterfaceImpl1, SingleArgActionInterface)
DECLARE_IMPLEMENTATION(SingleArgActionInterfaceImpl2, SingleArgActionInterface)
DECLARE_IMPLEMENTATION(SingleArgActionInterfaceImpl3, SingleArgActionInterface)

void actionSingleArgImpl1(int arg);
void actionSingleArgImpl2(int arg);
void actionSingleArgImpl3(int arg);

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_MULTIIMPLEMENTATIONACTIONTESTS_H