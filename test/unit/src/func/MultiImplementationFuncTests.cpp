//
// Created by Timor Gruber on 11/23/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#include <catch2/catch.hpp>
#include <fff.h>

#include "func/MultiImplementationFuncTests.h"

//region No-Args

DEFINE_IMPLEMENTATION(NoArgsFuncInterfaceImpl1, funcNoArgs, funcNoArgsImpl1)

DEFINE_IMPLEMENTATION(NoArgsFuncInterfaceImpl2, funcNoArgs, funcNoArgsImpl2)

DEFINE_IMPLEMENTATION(NoArgsFuncInterfaceImpl3, funcNoArgs, funcNoArgsImpl3)

// Fake declared functions to enable call statistics
FAKE_VALUE_FUNC(int, funcNoArgsImpl1)

FAKE_VALUE_FUNC(int, funcNoArgsImpl2)

FAKE_VALUE_FUNC(int, funcNoArgsImpl3)

SCENARIO("Interface with no-args func calls referenced implementation's method")
{
    GIVEN("Interface with no-args func")
    {
        NoArgsFuncInterface noArgFuncInterface{};

        AND_GIVEN("Implementation 1")
        {
            initNoArgsFuncInterfaceImpl1(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(funcNoArgsImpl1_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 2")
        {
            initNoArgsFuncInterfaceImpl2(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(funcNoArgsImpl2_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 3")
        {
            initNoArgsFuncInterfaceImpl3(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcNoArgs();

                THEN("Registered method is called")
                {
                    REQUIRE(funcNoArgsImpl3_fake.call_count == 1);
                }
            }
        }
    }
}

//endregion

//region Single-Arg

DEFINE_IMPLEMENTATION(SingleArgFuncInterfaceImpl1, funcSingleArg, funcSingleArgImpl1)

DEFINE_IMPLEMENTATION(SingleArgFuncInterfaceImpl2, funcSingleArg, funcSingleArgImpl2)

DEFINE_IMPLEMENTATION(SingleArgFuncInterfaceImpl3, funcSingleArg, funcSingleArgImpl3)

// Fake declared functions to enable call statistics
FAKE_VALUE_FUNC(int, funcSingleArgImpl1, int)

FAKE_VALUE_FUNC(int, funcSingleArgImpl2, int)

FAKE_VALUE_FUNC(int, funcSingleArgImpl3, int)

SCENARIO("Interface with single-arg func calls referenced implementation's method")
{
    GIVEN("Interface with no-args func")
    {
        SingleArgFuncInterface noArgFuncInterface{};

        AND_GIVEN("Implementation 1")
        {
            initSingleArgFuncInterfaceImpl1(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(funcSingleArgImpl1_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 2")
        {
            initSingleArgFuncInterfaceImpl2(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(funcSingleArgImpl2_fake.call_count == 1);
                }
            }
        }
        AND_GIVEN("Implementation 3")
        {
            initSingleArgFuncInterfaceImpl3(&noArgFuncInterface);

            WHEN("Interface method is called")
            {
                noArgFuncInterface.funcSingleArg(0);

                THEN("Registered method is called")
                {
                    REQUIRE(funcSingleArgImpl3_fake.call_count == 1);
                }
            }
        }
    }
}

//endregion
