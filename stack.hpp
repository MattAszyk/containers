#ifndef STACK_HPP
#define STACK_HPP
#include "container.hpp"
namespace matt{
    template<class T>
    class stack : private container<T>{
        public:
            inline void push(const T& _item) { container<T>::push_back(_item); }
            inline void pop() {  container<T>::pop_back(); }
            const T& top() {return  container<T>::back();}
            using container<T>::empty;
            using container<T>::size;
    };
}
#endif