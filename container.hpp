#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include<exception>
namespace matt{
    template<class T>
    class container
    {
    protected:
        struct item
        {
            item(const T& _value, item* _prev, item* _next) : value(_value), prev(_prev), next(_next){}
            T value;
            item* prev = nullptr;
            item* next = nullptr;
        };     
        item* head = nullptr;
        item* tail = nullptr;
        size_t amount = 0;
        container();
        container(const container<T>&);
        ~container();
        //ELEMENT ACCESS
        T& front();
        T& back();
        
        //ITERATORS
        class iterator;
        iterator begin() { return iterator(head);}
        iterator end() { return iterator(nullptr); };
        class iterator
        {
        private:
            const item* current;
        public:
            iterator() noexcept: current(head){}
            iterator(const item* _item) noexcept: current(_item){}
            iterator& operator=(item* _item)
            {
                this->current = _item;
                return *this;
            }

            iterator& operator++()
            {
                if(current == nullptr)
                    throw "Out of range.";
                current = current->next;
                return *this;
            }

            iterator& operator++(int)
            {
                iterator iter = *this;
                ++*this;
                return iter;
            }

            const T& operator*()
            {
                if(current ==nullptr)
                    throw "Element doesnt exist";
                return current->value;
            }

            bool operator!=(const iterator& it)
            {
                return it.current != current;
            }

        };
        

        //CAPACITY
        bool empty();
        size_t size();
        
        //MODIFIERS
        void clear();
        void insert(int ind, T& value);
        void push_back(const T&);
        void pop_back();
        void push_front(const T&);
        void pop_front();
        

    };
}


template<class T>
matt::container<T>::container(/* args */)
{
}

template<class T>
matt::container<T>::container(const container<T>& item)
{
    for(auto it = item.begin(); it != item.end(); it++)
        push_back(*it);
}


template<class T>
matt::container<T>::~container()
{
    clear();
}

template<class T>
size_t matt::container<T>::size()
{
    return amount;
}


template<class T>
bool matt::container<T>::empty()
{
    return amount == 0;
}


template<class T>
T& matt::container<T>::front()
{
    if(amount == 0)
    {
        throw "Container is empty";
    }
    return head->value;
}



template<class T>
T& matt::container<T>::back()
{
    if(amount == 0)
    {
        throw "Container is empty";
    }
    return tail->value;
}

template<class T>
void matt::container<T>::clear()
{
    switch (amount)
    {
    case 0:
        break;
    case 1:
        delete head;
        head = nullptr;
        tail = nullptr;
        amount--;
        return;
        break;
    default:
        tail->prev->next = nullptr;
        item *temp = tail->prev;
        delete tail;
        tail = temp;
        amount--;
        clear();
        break;
    }
}

template<class T>
void matt::container<T>::push_back(const T& val)
{
    if(amount == 0)
    {
        head = new item(val,nullptr,nullptr);
        tail = head;
    }
    else
    {
        item* temp = new item(val,tail,nullptr);
        tail->next = temp;
        tail = temp;
    }
    amount++;
}

template<class T>
void matt::container<T>::push_front(const T& val)
{
    if(amount == 0)
    {
        head = new item(val,nullptr,nullptr);
        tail = head;
    }
    else
    {
        item* temp = new item(val,nullptr,head);
        head->prev = temp;
        head = temp;
    }
    amount++;
}

template<class T>
void matt::container<T>::pop_back()
{
    switch (amount)
    {
    case 0:
        throw "Container is empty!";
        break;
    case 1:
        delete head;
        head = nullptr;
        tail = nullptr;
        amount--;
        break;
    default:
        tail->prev->next = nullptr;
        item *temp = tail->prev;
        delete tail;
        tail = temp;
        amount--;
        break;
    }
}

template<class T>
void matt::container<T>::pop_front()
{
    switch (amount)
    {
    case 0:
        throw "Container is empty!";
        break;
    case 1:
        delete head;
        head = nullptr;
        tail = nullptr;
        amount--;
        break;
    default:
        head->next->prev = nullptr;
        item *temp = head->next;
        delete head;
        head = temp;
        amount--;
        break;
    }
}


#endif