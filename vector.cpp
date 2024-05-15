/*

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
*/
