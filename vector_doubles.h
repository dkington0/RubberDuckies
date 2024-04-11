#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm> // std::copy
using std::copy;

namespace myStd
{

template<typename T>
class vector
{
    /*
    vector of type T much like stl vector container

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) Ts after elem[size_v-1]
    */

    int size_v;   // the size
    T *elem;      // pointer to the elements (or nullptr)
    int space;    // number of elements plus number of free slots
public:
    vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s} // alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = T(); // elements are default-initialized
    }

    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    vector &operator=(const vector &src) // copy assignment
    {
        T *p = new T[src.size_v];              // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                           // deallocate old space
        elem = p;                                // now we can reset elem
        size_v = src.size_v;
        return *this;  // return a self-reference
    }

    ~vector() {
        delete[] elem; // destructor
    }

    T &operator[](int n) {
        return elem[n]; // access: return reference
    }

    const T &operator[](int n) const {
        return elem[n];
    }

    int size() const {
        return size_v;
    }

    int capacity() const {
        return space;
    }

    void resize(int newsize) // growth
    // make the vector have newsize elements
    // initialize each new element with the default value of type T
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T(); // initialize new elements with default value
        size_v = newsize;
    }

    void push_back(const T& d)
    // increase vector size by one; initialize the new element with d
    {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    void reserve(int newalloc)
    {
        // never decrease allocation
        if (newalloc <= space) return;

        T* p = new T[newalloc]; // allocate new space
        for (int i = 0; i < size_v; ++i) // copy old elements
            p[i] = elem[i];
        delete[] elem; // deallocate old space
        elem = p; // assign the new space
        space = newalloc; // update the space
    }

    using iterator = T *;
    using const_iterator = const T *;

    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    iterator insert(iterator p, const T &val) // insert a new element val before p
    {
        // Make sure we have space
        if (size_v == space)
            reserve(space == 0 ? 8 : 2 * space);

        iterator temp = end();
        while (temp != p)
        {
            *temp = *(temp - 1); // copy element one position to the right
            --temp;
        }

        *p = val; // insert value
        ++size_v; // increment size
        return p; // return iterator to the inserted element
    }

    iterator erase(iterator p) // remove element pointed to by p
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
        --size_v;
        return p;
    }
};
}

#endif /* VECTOR_H_ */
