//
// Created by Timor Gruber on 11/21/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>
#include <polyC/Implementation.h>

#include "SingleImplementationActionTests.h"

DEFINE_IMPLEMENTATION(NoArgActionInterfaceImpl, actionNoArgs, actionNoArgsImpl)
FAKE_VOID_FUNC(actionNoArgsImpl) // Fake the declared function to enable call statistics

SCENARIO("Interface with no-arg action calls implementation method")
{
    GIVEN("Interface implementation")
    {
        NoArgActionInterface singleActionInterface{};
        initNoArgActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleActionInterface.actionNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(actionNoArgsImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
        {
            NoArgActionInterfaceImpl
                    interfaceImplementation = (NoArgActionInterfaceImpl) singleActionInterface;
            interfaceImplementation.actionNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(actionNoArgsImpl_fake.call_count == 2);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(SingleArgActionInterfaceImpl, actionSingleArg, actionSingleArgImpl)
FAKE_VOID_FUNC(actionSingleArgImpl, int) // Fake the declared function to enable call statistics

SCENARIO("Interface with single-arg action calls implementation method")
{
    GIVEN("Interface implementation")
    {
        SingleArgActionInterface singleActionInterface{};
        initSingleArgActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleActionInterface.actionSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(actionSingleArgImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
        {
            SingleArgActionInterfaceImpl
                    interfaceImplementation = (SingleArgActionInterfaceImpl) singleActionInterface;
            interfaceImplementation.actionSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(actionSingleArgImpl_fake.call_count == 2);
            }
        }
    }
}
