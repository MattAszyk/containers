#ifndef LIST_HPP
#define LIST_HPP
#include "container.hpp"

namespace matt
{
    template<class T>
    class list : private container<T>
    {
        public:
            using container<T>::front;
            using container<T>::back;
            using container<T>::iterator;
            using container<T>::begin;
            using container<T>::end;
            using container<T>::empty;
            using container<T>::size;
            using container<T>::clear;
            using container<T>::push_back;
            using container<T>::pop_back;
            using container<T>::push_front;
            using container<T>::pop_front;
    };
} // namespace matt


#endif