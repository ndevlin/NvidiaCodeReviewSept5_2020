// Written by Nathan Devlin for Nvidia, 09/05/2020
// Modified from code provided by David Gould

// Part 2 - Code Refactoring

#pragma once


/* Here's my version of the code! In the spirit of reviewing and
 * not completely rewriting, I have tried to leave the code as
 * unaltered as possible in terms of memory usage, file layout,
 * class structure etc. In the real world, I probably would have
 * gotten more information about the purpose and function fulfilled
 * by the code, (for example, why are we using an array of pointers?)
 * and then re-written the code from scratch to fulfill that purpose,
 * as this code was a little too disorganized to make modification the
 * superior strategy to re-writing.
 *
 * Thank you for taking the time to look this over!
 */


namespace Number
{
#define STANDARD_SHELF_SIZE 4

    // Wrapper class for a number
    class Container
    {
    private:
        float m_Contents;

    public:
        Container(float value = 0);

        virtual float GetContents();

        virtual void SetContents(float value);
    };


    // Wrapper class for an Integer
    class IntegerContainer : public Container
    {
    private:
        int m_IntContents;

    public:
        IntegerContainer(int value);

        ~IntegerContainer();

        float GetContents();

        void SetContents(float value);
    };


    /* A collection of Container objects
    Effectively an array of pointers to number wrappers whose size
    can be dynamically allocated */
    class Shelf
    {      
    private:
        int m_Size;
        Container **m_ShelfContents;
        int m_EndOfListIndex;

    public:
        Shelf(int size = STANDARD_SHELF_SIZE);

        ~Shelf();

        // Append a Container to the back of the array
        void AddContainer(Container &c);

        // Sum all Containers within this Shelf
        float CalculateContainedSum();
    };

}

