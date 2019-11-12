//
// Created by Timor Gruber on 11/11/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <polyC/Interface.h>
#include <polyC/InterfaceImplementation.h>

void dog_makeSound()
{ printf("Bark\n"); }

bool dog_isFriendly(){ return true;}

void cat_makeSound()
{ printf("Meow\n"); }

bool cat_isFriendly(){ return false;}

DECLARE_ACTION(makeSound)
DECLARE_FUNC(isFriendly, bool)

DECLARE_MULTI_INTERFACE(Animal, makeSound, isFriendly)

DECLARE_INTERFACE_IMPL(Dog, Animal)

DEFINE_MULTI_INTERFACE_IMPL(Dog, makeSound, dog_makeSound, isFriendly, dog_isFriendly)

DECLARE_INTERFACE_IMPL(Cat, Animal)

DEFINE_MULTI_INTERFACE_IMPL(Cat, makeSound, cat_makeSound, isFriendly, cat_isFriendly)

void makeSomeSound(IAnimal *animal)
{
    animal->makeSound();
}

int main(int argc, char **argv)
{
    IAnimal doggo, catto;

    initDog(&doggo);
    makeSomeSound(&doggo);

    initCat(&catto);
    makeSomeSound(&catto);

    doggo.makeSound();

    if (doggo.isFriendly())
        printf("I'm friendly!\n");
    if (catto.isFriendly())
        printf("Surprise!\n");

    return 0;
}
