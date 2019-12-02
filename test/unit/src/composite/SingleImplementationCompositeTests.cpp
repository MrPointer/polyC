//
// Created by Timor Gruber on 11/27/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#include <catch2/catch.hpp>
#include <fff.h>

#include "composite/SingleImplementationCompositeTests.h"

// Fake declared functions to enable call statistics
FAKE_VOID_FUNC(compositeActionNoArgsImpl)

FAKE_VALUE_FUNC(int, compositeFuncNoArgsImpl)

FAKE_VOID_FUNC(compositeActionSingleArgImpl, int)

FAKE_VALUE_FUNC(int, compositeFuncSingleArgImpl, int)

DEFINE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl, compositeActionNoArgs, compositeActionNoArgsImpl,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl)

SCENARIO("Interface with no-args action and func calls correct implementation methods")
{
    GIVEN("Interface implementation")
    {
        NoArgsCompositeInterface noArgsFullInterface{};
        initNoArgsCompositeInterfaceImpl(&noArgsFullInterface);

        WHEN("Interface calls action")
        {
            RESET_FAKE(compositeActionNoArgsImpl)
            RESET_FAKE(compositeFuncNoArgsImpl)

            noArgsFullInterface.compositeActionNoArgs();

            THEN("Action implementation is called")
            {
                REQUIRE(compositeActionNoArgsImpl_fake.call_count == 1);
            }
            THEN("Func implementation is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl_fake.call_count == 0);
            }
        }
        WHEN("Interface calls func")
        {
            RESET_FAKE(compositeActionNoArgsImpl)
            RESET_FAKE(compositeFuncNoArgsImpl)

            noArgsFullInterface.compositeFuncNoArgs();

            THEN("Func implementation is called")
            {
                REQUIRE(compositeFuncNoArgsImpl_fake.call_count == 1);
            }
            THEN("Action implementation is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl_fake.call_count == 0);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl,
                      compositeActionNoArgs, compositeActionNoArgsImpl,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl)

SCENARIO("Interface with no-args action and single-arg func calls correct implementation methods")
{
    RESET_FAKE(compositeActionNoArgsImpl)
    RESET_FAKE(compositeFuncSingleArgImpl)

    GIVEN("Interface implementation")
    {
        NoArgsActionVariedCompositeInterface variedCompositeInterface{};
        initNoArgsActionVariedCompositeInterfaceImpl(&variedCompositeInterface);

        WHEN("Interface calls action")
        {
            variedCompositeInterface.compositeActionNoArgs();

            THEN("Action implementation is called")
            {
                REQUIRE(compositeActionNoArgsImpl_fake.call_count == 1);
            }
            THEN("Func implementation is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl_fake.call_count == 0);
            }
        }
        WHEN("Interface calls func")
        {
            variedCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation is called")
            {
                REQUIRE(compositeFuncSingleArgImpl_fake.call_count == 1);
            }
            THEN("Action implementation is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl_fake.call_count == 0);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl,
                      compositeActionSingleArg, compositeActionSingleArgImpl,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl)

SCENARIO("Interface with no-args func and single-arg action calls correct implementation methods")
{
    RESET_FAKE(compositeActionSingleArgImpl)
    RESET_FAKE(compositeFuncNoArgsImpl)

    GIVEN("Interface implementation")
    {
        NoArgsFuncVariedCompositeInterface variedCompositeInterface{};
        initNoArgsFuncVariedCompositeInterfaceImpl(&variedCompositeInterface);

        WHEN("Interface calls action")
        {
            variedCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation is called")
            {
                REQUIRE(compositeActionSingleArgImpl_fake.call_count == 1);
            }
            THEN("Func implementation is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl_fake.call_count == 0);
            }
        }
        WHEN("Interface calls func")
        {
            variedCompositeInterface.compositeFuncNoArgs();

            THEN("Func implementation is called")
            {
                REQUIRE(compositeFuncNoArgsImpl_fake.call_count == 1);
            }
            THEN("Action implementation is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl_fake.call_count == 0);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl,
                      compositeActionSingleArg, compositeActionSingleArgImpl,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl)

SCENARIO("Interface with single-arg action and funs calls correct implementation methods")
{
    RESET_FAKE(compositeActionSingleArgImpl)
    RESET_FAKE(compositeFuncSingleArgImpl)

    GIVEN("Interface implementation")
    {
        SingleArgCompositeInterface singleArgCompositeInterface{};
        initSingleArgCompositeInterfaceImpl(&singleArgCompositeInterface);

        WHEN("Interface calls action")
        {
            singleArgCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation is called")
            {
                REQUIRE(compositeActionSingleArgImpl_fake.call_count == 1);
            }
            THEN("Func implementation is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl_fake.call_count == 0);
            }
        }
        WHEN("Interface calls func")
        {
            singleArgCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation is called")
            {
                REQUIRE(compositeFuncSingleArgImpl_fake.call_count == 1);
            }
            THEN("Action implementation is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl_fake.call_count == 0);
            }
        }
    }
}
