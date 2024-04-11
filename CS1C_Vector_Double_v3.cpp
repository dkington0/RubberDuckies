//============================================================================
// Name        : CS1C_Vector_Double_v3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "vector_doubles.h"
using namespace myStd;

#include <iostream>
#include <iomanip>   // std::setprecision
#include <algorithm> // std::find, std::sort

using std::cout;
using std::endl;

using std::find;
using std::sort;

template <typename Iterator>
Iterator low(Iterator first, Iterator last);

template <typename Iterator>
void selection_sort(Iterator first, Iterator last);

template <typename T> // Updated to accept a template vector class
void print_vector(const vector<T>& v);

int main()
{
    const int initSize = 5;
    vector<double> myDoubleVector(initSize); // Use the template vector class with the correct type parameter

    // Modify elements 2, 3, 4
    myDoubleVector[1] = -1.0;
    myDoubleVector[2] = -2.0;
    myDoubleVector[3] = -3.0;

    // Print vector
    print_vector(myDoubleVector);

    myDoubleVector.erase(myDoubleVector.begin());

    // Print vector
    print_vector(myDoubleVector);

    // Use fixed notation with precision 1
    cout << std::setprecision(1) << std::fixed;

    // Find lowest value
    auto it = low(myDoubleVector.begin(), myDoubleVector.end());
    cout << "Found vector lowest value: " << *it << endl;

    // Sort vector
    selection_sort(myDoubleVector.begin(), myDoubleVector.end());
    print_vector(myDoubleVector);

    return 0;
}

template <typename Iterator>
Iterator low(Iterator first, Iterator last)
// Return an iterator to the element in [first:last) that has the lowest value
{
    Iterator low = first;
    for (Iterator p = first; p != last; ++p)
        if (*low > *p)
            low = p;
    return low;
}

template <typename Iterator>
void selection_sort(Iterator first, Iterator last)
// Sort container elements from smallest to largest using the selection sort method
{
    int n = last - first;
    for (int x = 0; x < n; x++)
    {
        int index_of_min = x;
        for (int y = x; y < n; y++)
        {
            if (*(first + index_of_min) > *(first + y))
            {
                index_of_min = y;
            }
        }

        auto temp = *(first + x);
        *(first + x) = *(first + index_of_min);
        *(first + index_of_min) = temp;
    }
}

template <typename T>
void print_vector(const vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
