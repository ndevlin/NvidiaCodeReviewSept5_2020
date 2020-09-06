// Written by Nathan Devlin for Nvidia, 09/05/2020
// Modified from code provided by David Gould

// Part 2 - Code Refactoring

#include "test.h"
#include "test.cpp"

using namespace Number;

int main()
{
    Shelf normalShelf;
    Shelf smallShelf(2);
    Shelf bigShelf(8);

    Container smallValue(0.3f);

     //IntegerContainer should take an int, not a float
    IntegerContainer integerValue(int(2.5));

    Container bigValue(0.7f);

    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);

    // smallShelf can only hold 2 values: remove one of these
    smallShelf.AddContainer(bigValue);
    smallShelf.AddContainer(integerValue);
    //smallShelf.AddContainer(smallValue);

    smallValue.SetContents(1.1f);

    //IntegerContainer should take an int, not a float or double
    integerValue.SetContents(int(6.5));

    bigValue.SetContents(8.9f);

    normalShelf.AddContainer(bigValue);
    normalShelf.AddContainer(integerValue);
    normalShelf.AddContainer(smallValue);

    std::cout << "Big shelf contains: " << bigShelf.CalculateContainedSum() << std::endl;
    std::cout << "Small shelf contains: " << smallShelf.CalculateContainedSum() << std::endl;
    std::cout << "Normal shelf contains: " << normalShelf.CalculateContainedSum() << std::endl;

    std::cout << "Done." << std::endl;
}

