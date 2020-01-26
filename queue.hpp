#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "container.hpp"
namespace matt{
    template<class T>
    class queue : private container<T>{
        public:
            inline void push(const T& _item) {  container<T>::push_back(_item); }
            inline void pop() {  container<T>::pop_front(); }
            using container<T>::front;
            using container<T>::back;
            using container<T>::empty;
            using container<T>::size;
    };
}
#endif