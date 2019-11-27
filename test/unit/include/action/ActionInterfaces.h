//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#ifndef POLYC_ACTIONINTERFACES_H
#define POLYC_ACTIONINTERFACES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <polyC/Interface.h>

//========= No Args =========
DECLARE_ACTION(actionNoArgs)

DECLARE_INTERFACE(NoArgsActionInterface, actionNoArgs)

//========= Single Arg =========
DECLARE_ACTION(actionSingleArg, int)

DECLARE_INTERFACE(SingleArgActionInterface, actionSingleArg)

#ifdef __cplusplus
}
#endif
#endif //POLYC_ACTIONINTERFACES_H