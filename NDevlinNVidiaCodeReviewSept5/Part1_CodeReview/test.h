// Code Review by Nathan Devlin for Nvidia, 09/05/2020

// Part 1 - Code Review

#pragma once

#include <iostream>


/*
Nathan: 
I've added a few suggestions that will help your code compile and run
correctly, as well as make it more readable, modular, and reusable.

See specific comments below!

In general, I would recommend splitting your declarations and 
definitions between header files and source files, respectively.
I would also bring the main method to a new driver file.
Further, I would consider giving each class its own header and
source file.

I personally like putting my member variables at the top of my class
definition for quick reference. Be sure here to be careful about
what is public and what is private

I also would try to add more comments to your code to make it clear 
what your code is doing, and why.

Thanks for reviewing my comments!
*/


namespace Number
{

// N: Try using a more concise name here
// Also, may want to consider using const instead of #define
#define NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD 4

    class Container
    {
    public:

        Container(float value = 0) : m_Contents(value) {}

        /* N: I would return a float instead of a float reference;
        the user can use the setter if they want to modify the
        member variable */
        float &GetContents()
        {
            return &m_Contents;
        }

        virtual void SetContents(float value) { m_Contents = value; }

    private:
        float m_Contents;
    };

    class IntegerContainer : public Container
    {
        /* N: Everything in this class will be implicitly considered private
        I assume you only want the member variable to be private, so
        you need to indicate "public" and "private" */

        IntegerContainer(int value) : m_IntContents(value) {}
        ~IntegerContainer() { std::cout << "Destructing IntegerContainer" << std::endl; }

        int GetContents()
        {
            return m_IntContents;
        }

        void SetContents(float value) { m_IntContents = static_cast<int>(value); }

        int m_IntContents;
    };

    class Shelf
    {
    public:

        Shelf(int size = NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD) : m_ContentsSize(size)
        {
            /*N: Are you trying to dynamically allocate an array
            of Container pointers? I would consider if this
            is the best method. If that's what you want to do
            though, use a "*" 
            Also, consider using smart pointers instead of raw */
            m_Contents = new Container[size];


            // N: Also, since the allocated memory comes from
            // the heap, I would set all values to nullptr
        }

        /* N: Since you allocate memory in the Shelf constructor,
        you want to create a Shelf destructor so that you 
        can free that memory when you are done with it */


        void AddContainer(const Container &c)
        {
            //N: I would use a pointer to mark the end of the list instead of iterating
            for (auto i = 0; i < m_ContentsSize;)
            {
                if (!m_Contents[i])
                {

                    /* N: Using const_cast defeats the purpose of using const
                    Either the const or the const_cast has to go;
                    I would remove the const, otherwise there is not 
                    much point of using pointers for your shelf */
                    m_Contents[i] = const_cast<Container*>(&c);
                    break;
                }

                ++i;
            }
        }

        float CalculateContainedSum()
        {
            // May want a .f or .0 for clarity and exactness
            float total = 0;

            // N: I would consider using a traditional for loop with
            // an int instead of using auto, which is unnecceary
            for (auto i = 0; i < m_ContentsSize; ++i)
            {
                if (m_Contents[i])
                {
                    total += m_Contents[i]->GetContents();
                }
            }

            return total;
        }

        // N: m_Size might be a better and more concise name
        int m_ContentsSize;

        // N: You may want to name this differently to disambiguate it
        // from the m_Contents in the Container class
        Container **m_Contents;
    };


}

