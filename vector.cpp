#include "vector.h"
using namespace myStd;

#include <iostream>

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
