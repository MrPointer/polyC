//
// Created by Timor Gruber on 11/21/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>
#include <polyC/Implementation.h>

#include "SingleImplementationTests.h"

DEFINE_IMPLEMENTATION(SingleNoArgActionInterfaceImpl, action, actionImpl)
FAKE_VOID_FUNC(actionImpl) // Fake the declared function to enable call statistics

SCENARIO("Single no-arg action interface calls implementation method")
{
    GIVEN("Interface implementation")
    {
        ISingleNoArgActionInterface singleActionInterface;
        initSingleNoArgActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleActionInterface.action();
            THEN("Registered method is called")
            {
                REQUIRE(actionImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
        {
            SingleNoArgActionInterfaceImpl
                    interfaceImplementation = (SingleNoArgActionInterfaceImpl) singleActionInterface;
            interfaceImplementation.action();
            THEN("Registered method is called")
            {
                REQUIRE(actionImpl_fake.call_count == 2);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(SingleNoArgFuncInterfaceImpl, func, funcImpl)
FAKE_VALUE_FUNC(int, funcImpl) // Fake the declared function to enable call statistics

SCENARIO("Single no-arg func interface calls implementation method")
{
    GIVEN("Interface implementation")
    {
        ISingleNoArgFuncInterface singleNoArgFuncInterface;
        initSingleNoArgFuncInterfaceImpl((&singleNoArgFuncInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleNoArgFuncInterface.func();
            THEN("Registered method is called")
            {
                REQUIRE(funcImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
        {
            SingleNoArgFuncInterfaceImpl
                    interfaceImplementation = (SingleNoArgFuncInterfaceImpl) singleNoArgFuncInterface;
            interfaceImplementation.func();
            THEN("Registered method is called")
            {
                REQUIRE(funcImpl_fake.call_count == 2);
            }
        }
    }
}
