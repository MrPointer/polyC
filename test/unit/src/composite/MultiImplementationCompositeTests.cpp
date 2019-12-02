//
// Created by Timor Gruber on 11/28/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//
#include <catch2/catch.hpp>
#include <fff.h>

#include "composite/MultiImplementationCompositeTests.h"

//region Fakes

// Fake declared functions to enable call statistics
FAKE_VOID_FUNC(compositeActionNoArgsImpl1)

FAKE_VOID_FUNC(compositeActionNoArgsImpl2)

FAKE_VALUE_FUNC(int, compositeFuncNoArgsImpl1)

FAKE_VALUE_FUNC(int, compositeFuncNoArgsImpl2)

FAKE_VOID_FUNC(compositeActionSingleArgImpl1, int)

FAKE_VOID_FUNC(compositeActionSingleArgImpl2, int)

FAKE_VALUE_FUNC(int, compositeFuncSingleArgImpl1, int)

FAKE_VALUE_FUNC(int, compositeFuncSingleArgImpl2, int)

//endregion

//region No Args

DEFINE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl1, compositeActionNoArgs, compositeActionNoArgsImpl1,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl1)

DEFINE_IMPLEMENTATION(NoArgsCompositeInterfaceImpl2, compositeActionNoArgs, compositeActionNoArgsImpl2,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl2)

SCENARIO("Multiple implementations of no-args action and func interface "
         "call different methods")
{
    RESET_FAKE(compositeActionNoArgsImpl1)
    RESET_FAKE(compositeFuncNoArgsImpl1)
    RESET_FAKE(compositeActionNoArgsImpl2)
    RESET_FAKE(compositeFuncNoArgsImpl2)

    GIVEN("Implementation 1")
    {
        NoArgsCompositeInterface noArgsCompositeInterface{};
        initNoArgsCompositeInterfaceImpl1(&noArgsCompositeInterface);

        WHEN("Interface action is called")
        {
            noArgsCompositeInterface.compositeActionNoArgs();

            THEN("Action implementation 1 is called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            noArgsCompositeInterface.compositeFuncNoArgs();

            THEN("Func implementation 1 is called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 0);
            }
        }
    }

    GIVEN("Implementation 2")
    {
        NoArgsCompositeInterface noArgsCompositeInterface{};
        initNoArgsCompositeInterfaceImpl2(&noArgsCompositeInterface);

        WHEN("Interface action is called")
        {
            noArgsCompositeInterface.compositeActionNoArgs();

            THEN("Action implementation 2 is called")
            {
                REQUIRE(compositeActionNoArgsImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            noArgsCompositeInterface.compositeFuncNoArgs();

            THEN("Func implementation 2 is called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 0);
            }
        }
    }
}

//endregion

//region Varied Args

DEFINE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl1,
                      compositeActionNoArgs, compositeActionNoArgsImpl1,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl1)

DEFINE_IMPLEMENTATION(NoArgsActionVariedCompositeInterfaceImpl2,
                      compositeActionNoArgs, compositeActionNoArgsImpl2,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl2)

SCENARIO("Multiple implementations of no-args action and single-arg func interface "
         "call different methods")
{
    RESET_FAKE(compositeActionNoArgsImpl1)
    RESET_FAKE(compositeFuncSingleArgImpl1)
    RESET_FAKE(compositeActionNoArgsImpl2)
    RESET_FAKE(compositeFuncSingleArgImpl2)

    GIVEN("Implementation 1")
    {
        NoArgsActionVariedCompositeInterface variedCompositeInterface{};
        initNoArgsActionVariedCompositeInterfaceImpl1(&variedCompositeInterface);

        WHEN("Interface action is called")
        {
            variedCompositeInterface.compositeActionNoArgs();

            THEN("Action implementation 1 is called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            variedCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation 1 is called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 0);
            }
        }
    }

    GIVEN("Implementation 2")
    {
        NoArgsActionVariedCompositeInterface variedCompositeInterface{};
        initNoArgsActionVariedCompositeInterfaceImpl2(&variedCompositeInterface);

        WHEN("Interface action is called")
        {
            variedCompositeInterface.compositeActionNoArgs();

            THEN("Action implementation 2 is called")
            {
                REQUIRE(compositeActionNoArgsImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            variedCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation 2 is called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionNoArgsImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 0);
            }
        }
    }
}

DEFINE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl1,
                      compositeActionSingleArg, compositeActionSingleArgImpl1,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl1)

DEFINE_IMPLEMENTATION(NoArgsFuncVariedCompositeInterfaceImpl2,
                      compositeActionSingleArg, compositeActionSingleArgImpl2,
                      compositeFuncNoArgs, compositeFuncNoArgsImpl2)

SCENARIO("Multiple implementations of no-args func and single-arg action interface "
         "call different methods")
{
    RESET_FAKE(compositeActionSingleArgImpl1)
    RESET_FAKE(compositeFuncNoArgsImpl1)
    RESET_FAKE(compositeActionSingleArgImpl2)
    RESET_FAKE(compositeFuncNoArgsImpl2)

    GIVEN("Implementation 1")
    {
        NoArgsFuncVariedCompositeInterface variedCompositeInterface{};
        initNoArgsFuncVariedCompositeInterfaceImpl1(&variedCompositeInterface);

        WHEN("Interface action is called")
        {
            variedCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation 1 is called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            variedCompositeInterface.compositeFuncNoArgs();

            THEN("Func implementation 1 is called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 0);
            }
        }
    }

    GIVEN("Implementation 2")
    {
        NoArgsFuncVariedCompositeInterface variedCompositeInterface{};
        initNoArgsFuncVariedCompositeInterfaceImpl2(&variedCompositeInterface);

        WHEN("Interface action is called")
        {
            variedCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation 2 is called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            variedCompositeInterface.compositeFuncNoArgs();

            THEN("Func implementation 2 is called")
            {
                REQUIRE(compositeFuncNoArgsImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncNoArgsImpl1_fake.call_count == 0);
            }
        }
    }
}

//endregion

//region Single Arg

DEFINE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl1,
                      compositeActionSingleArg, compositeActionSingleArgImpl1,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl1)

DEFINE_IMPLEMENTATION(SingleArgCompositeInterfaceImpl2,
                      compositeActionSingleArg, compositeActionSingleArgImpl2,
                      compositeFuncSingleArg, compositeFuncSingleArgImpl2)

SCENARIO("Multiple implementations of single-arg action and func interface "
         "call different methods")
{
    RESET_FAKE(compositeActionSingleArgImpl1)
    RESET_FAKE(compositeFuncSingleArgImpl1)
    RESET_FAKE(compositeActionSingleArgImpl2)
    RESET_FAKE(compositeFuncSingleArgImpl2)

    GIVEN("Implementation 1")
    {
        SingleArgCompositeInterface singleArgCompositeInterface{};
        initSingleArgCompositeInterfaceImpl1(&singleArgCompositeInterface);

        WHEN("Interface action is called")
        {
            singleArgCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation 1 is called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            singleArgCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation 1 is called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 1);
            }

            THEN("Action implementation 2 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 0);
            }
            THEN("Func implementation 2 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 0);
            }
        }
    }

    GIVEN("Implementation 2")
    {
        SingleArgCompositeInterface singleArgCompositeInterface{};
        initSingleArgCompositeInterfaceImpl2(&singleArgCompositeInterface);

        WHEN("Interface action is called")
        {
            singleArgCompositeInterface.compositeActionSingleArg(0);

            THEN("Action implementation 2 is called")
            {
                REQUIRE(compositeActionSingleArgImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 0);
            }
        }
        AND_WHEN("Interface func is called")
        {
            singleArgCompositeInterface.compositeFuncSingleArg(0);

            THEN("Func implementation 2 is called")
            {
                REQUIRE(compositeFuncSingleArgImpl2_fake.call_count == 1);
            }

            THEN("Action implementation 1 is NOT called")
            {
                REQUIRE(compositeActionSingleArgImpl1_fake.call_count == 0);
            }
            THEN("Func implementation 1 is NOT called")
            {
                REQUIRE(compositeFuncSingleArgImpl1_fake.call_count == 0);
            }
        }
    }
}

//endregion
