//
// Created by Timor Gruber on 11/27/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_SINGLEIMPLEMENTATIONCOMPOSITETESTS_H
#define POLYC_SINGLEIMPLEMENTATIONCOMPOSITETESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Implementation.h>
#include "CompositeInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl, NoArgsCompositeInterface)

void compositeActionNoArgsImpl();
int compositeFuncNoArgsImpl();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl, SingleArgCompositeInterface)

void compositeActionSingleArgImpl(int);
int compositeFuncSingleArgImpl(int);

//endregion

//region Varied Arg

DECLARE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl, NoArgsActionVariedCompositeInterface)

DECLARE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl, NoArgsFuncVariedCompositeInterface)

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_SINGLEIMPLEMENTATIONCOMPOSITETESTS_H