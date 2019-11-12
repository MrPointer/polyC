//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_FUNC_H
#define POLYC_FUNC_H

#include "utility/MacroUtils.h"

#define DECLARE_FUNC(name, returnType) \
typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();

#endif //POLYC_FUNC_H
