// Code Review by Nathan Devlin for Nvidia, 09/05/2020

// Part 1 - Code Review


// N: including iostream is necessary in either the
// header or cpp file, not both
#include <iostream>

#include "test.h"

using namespace Number;

int main()
{
    Shelf normalShelf;
    Shelf smallShelf(2);
    Shelf bigShelf(8);

    Container smallValue(0.3f);

    // N: The IntegerContainer takes an int, not a float,
    // is there a reason you're giving it a float?
    IntegerContainer integerValue(2.5);
    Container bigValue(0.7f);

    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    smallShelf.AddContainer(bigValue);
    smallShelf.AddContainer(integerValue);
    smallShelf.AddContainer(smallValue);

    // N: smallShelf has been set to contain 2 elements;
    // adding 3 will cause a memory access violation
    smallValue.SetContents(1.1f);
    integerValue.SetContents(6.5);
    bigValue.SetContents(8.9f);

    normalShelf.AddContainer(bigValue);
    normalShelf.AddContainer(integerValue);
    normalShelf.AddContainer(smallValue);

    std::cout << "Big shelf contains: " << bigShelf.CalculateContainedSum() << std::endl;
    std::cout << "Small shelf contains: " << smallShelf.CalculateContainedSum() << std::endl;
    std::cout << "Normal shelf contains: " << normalShelf.CalculateContainedSum() << std::endl;
}


