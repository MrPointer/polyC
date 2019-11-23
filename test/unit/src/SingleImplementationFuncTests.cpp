//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>
#include <polyC/Implementation.h>

#include "SingleImplementationFuncTests.h"

DEFINE_IMPLEMENTATION(NoArgsFuncInterfaceImpl, funcNoArgs, funcNoArgsImpl)
FAKE_VALUE_FUNC(int, funcNoArgsImpl) // Fake the declared function to enable call statistics

SCENARIO("Interface with no-arg func calls implementation method")
{
    GIVEN("Interface implementation")
    {
        NoArgsFuncInterface singleNoArgFuncInterface{};
        initNoArgsFuncInterfaceImpl((&singleNoArgFuncInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleNoArgFuncInterface.funcNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(funcNoArgsImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
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
FAKE_VALUE_FUNC(int, funcSingleArgImpl, int) // Fake the declared function to enable call statistics

SCENARIO("Interface with single-arg func calls implementation method")
{
    GIVEN("Interface implementation")
    {
        SingleArgFuncInterface singleNoArgFuncInterface{};
        initSingleArgFuncInterfaceImpl((&singleNoArgFuncInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleNoArgFuncInterface.funcSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(funcSingleArgImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
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
