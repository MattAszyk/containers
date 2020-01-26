#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <exception>
namespace matt
{
    template <class T>
    class vector
    {
        public:
            vector();
            vector(size_t);
            ~vector();

            // ELEMENT ACCESS
            T& at(size_t);
            T& front();
            T& back();
            T& operator[](const size_t&);

            // ITERATORS
            T* begin();
            T* end();

            //CAPACITY
            bool empty();
            void reserve(size_t);
            void shrink_to_fit(size_t);
            size_t size();
            size_t capacity();

            // MODIFIERS
            void clear();
            void insert_at(size_t, const T&);
            void pop_back();
            void push_back(const T&);
            void swap(size_t,size_t);
        private:
            T* data = nullptr;
            void realloc(size_t _size = 1);
            size_t current_capacity = 0;
            size_t elements = 0;
            size_t next_capacity(size_t = 0);
    };
}


template <class T>
matt::vector<T>::vector()
{
    
}

template <class T>
matt::vector<T>::~vector()
{
    if(current_capacity != 0)
        delete[] data;
}





template <class T>
matt::vector<T>::vector(size_t n)
{
    elements = n;
    realloc(n);
}

template <class T>
size_t matt::vector<T>::next_capacity(size_t req)
{
    size_t _size = 1;
    while (_size < req)
        _size *= 2;
    return _size;
}

template<class T>
void matt::vector<T>::realloc(size_t size)
{
    if(current_capacity != 0)
    {
        T* temporary_array = new T[next_capacity(current_capacity+1)];
        std::copy(data,data+elements,temporary_array);
        delete[] data;
        data = temporary_array;
        current_capacity = next_capacity(current_capacity+1);
    }
    else
    {
        data = new T[next_capacity()];
        current_capacity = next_capacity();
    }
    
}


//ELEMENT ACCESS
template<class T>
T& matt::vector<T>::at(size_t i)
{
    if(i > elements)
    {
        throw  "Out of range."; 
    }

    return data[i];
}

template<class T>
T& matt::vector<T>::operator[](const size_t& i)
{
    return at(i);
}

template<class T>
T& matt::vector<T>::front()
{
    if(elements == 0)
    {
        throw  "Out of range."; 
    }

    return (*(data));
}

template<class T>
T& matt::vector<T>::back()
{
    if(elements == 0)
    {
        throw  "Out of range."; 
    }

    return data[elements-1];
}

//ITERATORS

template<class T>
T* matt::vector<T>::begin()
{
   return data;
}

template<class T>
T* matt::vector<T>::end()
{
   return data+elements+1;
}

//CAPACITY
template<class T>
bool matt::vector<T>::empty()
{
   return elements == 0;
}

template<class T>
void matt::vector<T>::reserve(size_t size)
{
    if(size < current_capacity)
    {
        throw "Cannot reserve less than is reserved now.\n";
    }
    realloc(size);
}

template<class T>
void matt::vector<T>::shrink_to_fit(size_t size)
{
    if(current_capacity == 0) return;
    if(size >= current_capacity)
    {
        throw "Cannot reserve through shrinking";
    }
    T* temporary = new T[size+1];
    std::copy(data,data+elements,temporary);
    delete[] data;
    data = temporary;
    current_capacity = size;
    elements = size;
}



template<class T>
size_t matt::vector<T>::size()
{
    return elements;
}

template<class T>
size_t matt::vector<T>::capacity()
{
    return current_capacity;
}

//MODIFIERS
template<class T>
void matt::vector<T>::clear()
{
    if(current_capacity != 0)
        delete[] data;
    elements = 0;
    current_capacity = 0;
}

template<class T>
void matt::vector<T>::insert_at(size_t at, const T& item)
{
    if(at >= current_capacity || elements+1 >= current_capacity)
    {
        realloc(next_capacity(at+1));
    }
    for(size_t i = 0, j = 0; i < elements+1;j++, ++i)
    {
        if(i == at)
        {
            i++;
            continue;
        }
        data[i] = T(data[j]);
    }
    data[at] = T(item);
}



template<class T>
void matt::vector<T>::pop_back()
{
    if(elements)
    {
        elements--;
    }
    else
    {
        throw "matt::vector is empty.";
    }
}


template<class T>
void matt::vector<T>::push_back(const T& item)
{
    if(elements == current_capacity)
    {
        realloc(elements+1);
    }
    data[elements] = T(item);
    elements++;
}


template<class T>
void matt::vector<T>::swap(size_t f, size_t s)
{
    T temp(data[f]);
    data[f] = T(data[s]);
    data[s] = T(temp);
}


#endif
