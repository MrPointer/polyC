//
// Created by Timor Gruber on 11/28/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_MULTIIMPLEMENTATIONCOMPOSITETESTS_H
#define POLYC_MULTIIMPLEMENTATIONCOMPOSITETESTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Implementation.h>
#include "CompositeInterfaces.h"

//region No Args

DECLARE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl1, NoArgsCompositeInterface)
DECLARE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl2, NoArgsCompositeInterface)

void compositeActionNoArgsImpl1();
void compositeActionNoArgsImpl2();
int compositeFuncNoArgsImpl1();
int compositeFuncNoArgsImpl2();

//endregion

//region Single Arg

DECLARE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl1, SingleArgCompositeInterface)
DECLARE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl2, SingleArgCompositeInterface)

void compositeActionSingleArgImpl1(int);
void compositeActionSingleArgImpl2(int);
int compositeFuncSingleArgImpl1(int);
int compositeFuncSingleArgImpl2(int);

//endregion

//region Varied Arg

DECLARE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl1, NoArgsActionVariedCompositeInterface)
DECLARE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl2, NoArgsActionVariedCompositeInterface)

DECLARE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl1, NoArgsFuncVariedCompositeInterface)
DECLARE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl2, NoArgsFuncVariedCompositeInterface)

//endregion

#ifdef __cplusplus
}
#endif
#endif //POLYC_MULTIIMPLEMENTATIONCOMPOSITETESTS_H