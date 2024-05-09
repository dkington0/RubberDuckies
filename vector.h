#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm>
using std::copy;

namespace myStd
{

template<typename T>
class vector
{

    int size_v;
    T *elem;
    int space;
public:

    /**
     * @brief : vector default constructor
     *          creates an empty vector container
     */
    vector() : size_v{0}, elem{nullptr}, space{0} {}

    /**
     * @brief : vector alternate constructor
     * @param s : size of the vector to be created
     */
    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = T();
    }

    /**
     * @brief : vector copy constructor
     * @param src : incoming vector to be copied
     */
    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space}
    {
        copy(src.elem, src.elem + size_v, elem);
    }

    /**
     * @brief operator= : overloaded copy operator
     * @param src : incoming vector object for invoking vector to copy
     * @return returns a reference to self
     */
    vector &operator=(const vector &src) // copy assignment
    {
        T *p = new T[src.size_v];
        copy(src.elem, src.elem + src.size_v, p);
        delete[] elem;
        elem = p;
        size_v = src.size_v;
        return *this;
    }

    /**
     * @brief : vector destructor constructor
     */
    ~vector() {
        delete[] elem; // destructor
    }

    /**
     * @brief : overloaded [] operation
     * @param src : index to operate on
     * @return returns reference to element
     */
    T &operator[](int n) {
        return *(elem + n); // access: return reference
    }

    /**
     * @brief : overloaded const [] operation
     * @param src : const index to operate on
     * @return returns element
     */
    const T &operator[](int n) const {
        return elem[n];
    }



    /**
     * @brief size : determines the size of the vector
     * @return : integer of the number of elements within the vector
     */
    int size() const {
        return size_v;
    }

    /**
     * @brief capacity : determines the current maximum capacity of the vector
     * @return : integer of the current amount of space allocated for the vector
     */
    int capacity() const {
        return space;
    }

    /**
     * @brief resize : exapnds or truncates vector to the specified size
     * @param newsize : number of elements specified to be resized to
     */
    void resize(int newsize)
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T();
        size_v = newsize;
    }

    /**
     * @brief push_back : increases vector size by one by appending the incoming element to the end of the vector
     * @param d : element to be appended to the end of the vector
     */
    void push_back(const T& d)
    {
        if (space == 0)
            reserve(8);
        else if (size_v == space)
            reserve(2 * space);
        elem[size_v] = d;
        ++size_v;
    }

    /**
     * @brief reserve : allocates new space in memory for the vector
     * @param newalloc : integer representing the amount of space to be reserved, depending on the size of the data type
     */
    void reserve(int newalloc)
    {
        if (newalloc <= space) return;

        T* p = new T[newalloc];
        for (int i = 0; i < size_v; ++i)
            p[i] = elem[i];
        delete[] elem;
        elem = p;
        space = newalloc;
    }

    using iterator = T *;
    using const_iterator = const T *;

    /**
     * @brief begin : points to the first element
     * @return : returns an iterator pointing to the first element, or nullptr if the vector is empty
     */
    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief begin : points to the first element, read-only
     * @return : returns a const_iterator pointing to the first element, or nullptr if the vector is empty
     */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief end : points to one beyond the last element
     * @return : returns an iterator pointing to one beyond the last element, or nullptr if the vector is empty
     */
    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief end : points to one beyond the last element, read-only
     * @return : returns a const_iterator pointing to one beyond the last element, or nullptr if the vector is empty
     */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief insert : inserts a new element before the specified element
     * @param p : an iterator pointing to the element directly after the position where the new element is to be inserted
     * @param val : element to be inserted
     * @return : returns an iterator pointing to the newly inserted element
     */
    iterator insert(iterator p, const T &val)
    {
        if (size_v == space)
            reserve(space == 0 ? 8 : 2 * space);

        iterator temp = end();
        while (temp != p)
        {
            *temp = *(temp - 1);
            --temp;
        }

        *p = val;
        ++size_v;
        return p;
    }

    /**
     * @brief erase : removes the element pointed to by the given iterator
     * @param p : iterator pointing to the element to be removed
     * @return : returns the given iterator
     */
    iterator erase(iterator p)
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos;
        --size_v;
        return p;
    }
};
}

#endif
