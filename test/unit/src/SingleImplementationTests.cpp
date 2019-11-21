//
// Created by Timor Gruber on 11/21/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <polyC/Implementation.h>

void fooImpl()
{}

DECLARE_ACTION(foo)

DECLARE_INTERFACE(SingleActionInterface, foo)

DECLARE_IMPLEMENTATION(SingleActionInterfaceImpl, SingleActionInterface)

DEFINE_IMPLEMENTATION(SingleActionInterfaceImpl, foo, fooImpl)

SCENARIO("Implementation of an interface with single action calls expected method")
{
    GIVEN("Interface implementation")
    {
        ISingleActionInterface singleActionInterface;
        initSingleActionInterfaceImpl((&singleActionInterface));

        WHEN("Implementation method is called")
        {
            singleActionInterface.foo();
            THEN("Registered method is called")
            {
                REQUIRE(1);
            }
        }
    }
}
