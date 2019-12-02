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

#include <polyC/Implementation.h>
#include "ActionInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgActionInterfaceImpl, NoArgsActionInterface)

void actionNoArgsImpl();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgActionInterfaceImpl, SingleArgActionInterface)

void actionSingleArgImpl(int);

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONACTIONTESTS_H