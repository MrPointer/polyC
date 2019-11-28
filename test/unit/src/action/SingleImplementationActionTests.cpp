//
// Created by Timor Gruber on 11/21/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>

#include "action/SingleImplementationActionTests.h"

// Fake declared functions to enable call statistics
FAKE_VOID_FUNC(actionNoArgsImpl)

FAKE_VOID_FUNC(actionSingleArgImpl, int)

DEFINE_IMPLEMENTATION(NoArgActionInterfaceImpl, actionNoArgs, actionNoArgsImpl)

SCENARIO("Interface with no-args action calls implementation action")
{
    GIVEN("Interface implementation")
    {
        NoArgsActionInterface singleActionInterface{};
        initNoArgActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls action")
        {
            singleActionInterface.actionNoArgs();
            THEN("Registered method is called")
            {
                REQUIRE(actionNoArgsImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Concrete implementation calls action")
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

SCENARIO("Interface with single-arg action calls implementation action")
{
    GIVEN("Interface implementation")
    {
        SingleArgActionInterface singleActionInterface{};
        initSingleArgActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls action")
        {
            singleActionInterface.actionSingleArg(0);
            THEN("Registered method is called")
            {
                REQUIRE(actionSingleArgImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Concrete implementation calls action")
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
