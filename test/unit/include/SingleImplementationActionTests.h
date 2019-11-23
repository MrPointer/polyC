//
// Created by Timor Gruber on 11/22/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_SINGLEIMPLEMENTATIONACTIONTESTS_H
#define POLYC_SINGLEIMPLEMENTATIONACTIONTESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Interface.h>

void actionNoArgsImpl();

DECLARE_ACTION(actionNoArgs)

DECLARE_INTERFACE(NoArgActionInterface, actionNoArgs)

DECLARE_IMPLEMENTATION(NoArgActionInterfaceImpl, NoArgActionInterface)

void actionSingleArgImpl(int arg);

DECLARE_ACTION(actionSingleArg, int)

DECLARE_INTERFACE(SingleArgActionInterface, actionSingleArg)

DECLARE_IMPLEMENTATION(SingleArgActionInterfaceImpl, SingleArgActionInterface)

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONACTIONTESTS_H