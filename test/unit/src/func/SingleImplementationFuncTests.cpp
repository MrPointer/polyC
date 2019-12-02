//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>
#include <polyC/Implementation.h>

#include "func/SingleImplementationFuncTests.h"

// Fake declared functions to enable call statistics
FAKE_VALUE_FUNC(int, funcNoArgsImpl)

FAKE_VALUE_FUNC(int, funcSingleArgImpl, int)

DEFINE_IMPLEMENTATION(NoArgsFuncInterfaceImpl, funcNoArgs, funcNoArgsImpl)

SCENARIO("Interface with no-args func calls implementation func")
{
    GIVEN("Interface implementation")
    {
        NoArgsFuncInterface singleNoArgFuncInterface{};
        initNoArgsFuncInterfaceImpl((&singleNoArgFuncInterface));

        WHEN("Interface calls func")
        {
            singleNoArgFuncInterface.funcNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(funcNoArgsImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Concrete implementation calls func")
        {
            NoArgsFuncInterfaceImpl
                    interfaceImplementation = (NoArgsFuncInterfaceImpl) singleNoArgFuncInterface;
            interfaceImplementation.funcNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(funcNoArgsImpl_fake.call_count == 2);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(SingleArgFuncInterfaceImpl, funcSingleArg, funcSingleArgImpl)

SCENARIO("Interface with single-arg func calls implementation func")
{
    GIVEN("Interface implementation")
    {
        SingleArgFuncInterface singleNoArgFuncInterface{};
        initSingleArgFuncInterfaceImpl((&singleNoArgFuncInterface));

        WHEN("Interface calls func")
        {
            singleNoArgFuncInterface.funcSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(funcSingleArgImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Concrete implementation calls func")
        {
            SingleArgFuncInterfaceImpl
                    interfaceImplementation = (SingleArgFuncInterfaceImpl) singleNoArgFuncInterface;
            interfaceImplementation.funcSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(funcSingleArgImpl_fake.call_count == 2);
            }
        }
    }
}
