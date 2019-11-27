//
// Created by Timor Gruber on 11/11/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <polyC/Interface.h>
#include <polyC/Implementation.h>

void dog_makeSound()
{ printf("Bark\n"); }

bool dog_isFriendly()
{ return true; }

void cat_makeSound()
{ printf("Meow\n"); }

bool cat_isFriendly()
{ return false; }

DECLARE_ACTION(makeSound)

DECLARE_FUNC(bool, isFriendly)

DECLARE_INTERFACE(Animal, makeSound, isFriendly)

DECLARE_IMPLEMENTATION(Dog, Animal)

DEFINE_IMPLEMENTATION(Dog, makeSound, dog_makeSound, isFriendly, dog_isFriendly)

DECLARE_IMPLEMENTATION(Cat, Animal)

DEFINE_IMPLEMENTATION(Cat, makeSound, cat_makeSound, isFriendly, cat_isFriendly)

int main(int argc, char **argv)
{
    IAnimal doggo, catto;
    initDog(&doggo);
    initCat(&catto);

    catto.makeSound();

    if (doggo.isFriendly())
        printf("I'm friendly!\n");
    if (catto.isFriendly())
        printf("Surprise!\n");

    return 0;
}
