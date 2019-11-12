//
// Created by timor.g on 11/12/19.
//

#ifndef POLYC_FUNC_H
#define POLYC_FUNC_H

#include "utility/MacroUtils.h"

#define DECLARE_FUNC(name, returnType) \
typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();

#endif //POLYC_FUNC_H
