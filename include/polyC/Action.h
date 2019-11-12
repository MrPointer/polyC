//
// Created by timor.g on 11/12/19.
//

#ifndef POLYC_ACTION_H
#define POLYC_ACTION_H

#include "utility/MacroUtils.h"

#define DECLARE_ACTION(name) typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();
#define DECLARE_ACTION_ARG(name, argument) \
typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(argument arg);

#endif //POLYC_ACTION_H
