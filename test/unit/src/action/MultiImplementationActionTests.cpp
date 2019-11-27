//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#include <catch2/catch.hpp>
#include <fff.h>

#include "action/MultiImplementationActionTests.h"

//region No-Args

DEFINE_IMPLEMENTATION(NoArgsActionInterfaceImpl1, actionNoArgs, actionNoArgsImpl1)

DEFINE_IMPLEMENTATION(NoArgsActionInterfaceImpl2, actionNoArgs, actionNoArgsImpl2)

DEFINE_IMPLEMENTATION(NoArgsActionInterfaceImpl3, actionNoArgs, actionNoArgsImpl3)

// Fake declared functions to enable call statistics
FAKE_VOID_FUNC(actionNoArgsImpl1)

FAKE_VOID_FUNC(actionNoArgsImpl2)

FAKE_VOID_FUNC(actionNoArgsImpl3)

SCENARIO("Interface with no-args action calls referenced implementation's method")
{
    GIVEN("Interface with no-args action")
    {
        NoArgsActionInterface noArgActionInterface{};

        AND_GIVEN("Implementation 1")
        {
            initNoArgsActionInterfaceImpl1(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(actionNoArgsImpl1_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 2")
        {
            initNoArgsActionInterfaceImpl2(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(actionNoArgsImpl2_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 3")
        {
            initNoArgsActionInterfaceImpl3(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(actionNoArgsImpl3_fake.call_count == 1);
                }
            }
        }
    }
}

//endregion

//region Single-Arg

DEFINE_IMPLEMENTATION(SingleArgActionInterfaceImpl1, actionSingleArg, actionSingleArgImpl1)

DEFINE_IMPLEMENTATION(SingleArgActionInterfaceImpl2, actionSingleArg, actionSingleArgImpl2)

DEFINE_IMPLEMENTATION(SingleArgActionInterfaceImpl3, actionSingleArg, actionSingleArgImpl3)

// Fake declared functions to enable call statistics
FAKE_VOID_FUNC(actionSingleArgImpl1, int)

FAKE_VOID_FUNC(actionSingleArgImpl2, int)

FAKE_VOID_FUNC(actionSingleArgImpl3, int)

SCENARIO("Interface with single-arg action calls referenced implementation's method")
{
    GIVEN("Interface with no-args action")
    {
        SingleArgActionInterface noArgActionInterface{};

        AND_GIVEN("Implementation 1")
        {
            initSingleArgActionInterfaceImpl1(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(actionSingleArgImpl1_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 2")
        {
            initSingleArgActionInterfaceImpl2(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(actionSingleArgImpl2_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 3")
        {
            initSingleArgActionInterfaceImpl3(&noArgActionInterface);

            WHEN("Interface method is called")
            {
                noArgActionInterface.actionSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(actionSingleArgImpl3_fake.call_count == 1);
                }
            }
        }
    }
}

//endregion
