// Written by Nathan Devlin for Nvidia, 09/05/2020
// Modified from code provided by David Gould

// Part 2 - Code Refactoring

#pragma once

#include <iostream>
#include "test.h"

using namespace Number;

Container::Container(float value) : m_Contents(value)
{}

float Container::GetContents()
{
    return m_Contents;
}

void Container::SetContents(float value)
{
    m_Contents = value;
}


IntegerContainer::IntegerContainer(int value) : m_IntContents(value)
{}

IntegerContainer::~IntegerContainer()
{
    std::cout << "Destructing IntegerContainer" << std::endl;
}

float IntegerContainer::GetContents()
{
    return static_cast<float>(m_IntContents);
}

void IntegerContainer::SetContents(float value)
{
    m_IntContents = static_cast<int>(value);
}


Shelf::Shelf(int size) :
    m_Size(size), m_ShelfContents(nullptr), m_EndOfListIndex(0)
{
    /* Smart pointers, vectors, or some other strategy should probably
     * be used here instead of an array of raw pointers, but in absence
     * of knowledge about the specific purposes and uses of this code,
     * I've left the original memory allocation strategy intact */
    m_ShelfContents = new Container*[size]; //Array of Container pointers

    // Make sure heap memory in array is set to null
    for(int i = 0; i < size; i++)
    {
        m_ShelfContents[i] = nullptr;
    }
}

// Add destructor to free memory after use
Shelf::~Shelf()
{
    delete m_ShelfContents;
    std::cout << "Destructing Shelf" << std::endl;
}

void Shelf::AddContainer(Container &c)
{
    m_ShelfContents[m_EndOfListIndex] = &c;
    m_EndOfListIndex++;
}

float Shelf::CalculateContainedSum()
{
    float total = 0.0;

    for (int i = 0; i < m_Size; i++)
    {
        if (m_ShelfContents[i] != nullptr)
        {
            total += m_ShelfContents[i]->GetContents();
        }
    }

    return total;
}

