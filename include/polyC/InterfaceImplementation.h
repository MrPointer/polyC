//
// Created by timor.g on 11/12/19.
//

#ifndef POLYC_INTERFACEIMPLEMENTATION_H
#define POLYC_INTERFACEIMPLEMENTATION_H

#include "polyInterface.h"

#define DECLARE_INTERFACE_IMPL(name, baseInterface) \
        typedef I##baseInterface name; \
        void init##name((name) *instance);

#define DEFINE_INTERFACE_IMPL(name, methodName, actualMethod) \
        void init##name((name) *instance) { \
            instance->methodName = actualMethod; \
        }

#define DEFINE_MULTI_INTERFACE_IMPL(name, methodName1, method1, methodName2, method2) \
        void init##name((name) *instance) { \
            instance->methodName1 = method1; \
            instance->methodName2 = method2; \
        }

#endif //POLYC_INTERFACEIMPLEMENTATION_H
