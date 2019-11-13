//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_IMPLEMENTATION_H
#define POLYC_IMPLEMENTATION_H

#include "Interface.h"

#define DECLARE_IMPLEMENTATION(name, baseInterface) \
        typedef I##baseInterface name; \
        void init##name(name *instance);

#define DEFINE_IMPLEMENTATION(name, ...) VFUNC1(DEFINE_IMPLEMENTATION, name, __VA_ARGS__);

#define DEFINE_IMPLEMENTATION2(name, methodName1, method1) \
        void init##name(name *instance) { \
            instance->methodName1 = (method1); \
        }

#define DEFINE_IMPLEMENTATION4(name, methodName1, method1, methodName2, method2) \
        void init##name(name *instance) { \
            instance->methodName1 = (method1); \
            instance->methodName2 = (method2); \
        }

#endif //POLYC_IMPLEMENTATION_H
