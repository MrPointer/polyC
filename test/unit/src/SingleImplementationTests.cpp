//
// Created by Timor Gruber on 11/21/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <catch2/catch.hpp>
#include <fff.h>
#include <polyC/Implementation.h>

void fooImpl();

FAKE_VOID_FUNC(fooImpl) // Fake the declared function to enable call statistics

DECLARE_ACTION(foo)

DECLARE_INTERFACE(SingleActionInterface, foo)

DECLARE_IMPLEMENTATION(SingleActionInterfaceImpl, SingleActionInterface)

DEFINE_IMPLEMENTATION(SingleActionInterfaceImpl, foo, fooImpl)

SCENARIO("Implemented single-action interface calls registered method")
{
    GIVEN("Interface implementation")
    {
        ISingleActionInterface singleActionInterface;
        initSingleActionInterfaceImpl((&singleActionInterface));

        WHEN("Interface calls method in polymorphic way")
        {
            singleActionInterface.foo();
            THEN("Registered method is called")
            {
                REQUIRE(fooImpl_fake.call_count == 1);
            }
        }
        AND_WHEN("Implementation calls method directly")
        {
            SingleActionInterfaceImpl
                    interfaceImplementation = (SingleActionInterfaceImpl) singleActionInterface;
            interfaceImplementation.foo();
            THEN("Registered method is called")
            {
                REQUIRE(fooImpl_fake.call_count == 2);
            }
        }
    }
}
