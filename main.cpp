#include <iostream>
#include "vector.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include <assert.h>
#include <string>
std::string result(bool quest)
{
    return quest ? " --- SUCCESS.\n" : " --- FAILED.\n";
}

int main() {

    matt::list<int> list;      std::cout << "Init list\n";
    matt::queue<int> queue;    std::cout << "Init queue\n";
    matt::stack<int> stack;    std::cout << "Init stack\n";
    matt::vector<int*> vector;  std::cout << "Init vector\n";

    int vals[1000];
    std::cout << "Pushing 1000 elements into containers.";
    for(int i = 0; i < 1000; ++i)
    {
        vals[i] = i;
        vector.push_back(vals+i);
        stack.push(i);
        list.push_back(i);
        queue.push(i);
    }
    std::cout << result(1);

    std::cout << "Checking size method" << result(list.size() == 1000);
    std::cout << "Checking vector size" << result(list.size() == 1000);
    std::cout << "Checking empty method" << result(!list.empty());
    std::cout << "Checking queue front/back" << result(queue.front() == 0 && queue.back() == 999);
    int i = 0;
    bool ans = true;
    std::cout << "Checking queue pop";
    for(; i < 999; ++i)
    {
        if(queue.front() != i)
        {
            ans = false;
            break;
        }
        queue.pop();
    }
    std::cout << result(ans);
    ans = true;
    std::cout << "Checking stack pop";
    for(; i >= 0; --i)
    {
        if(stack.top() != i)
        {
            ans = false;
            break;
        }
        stack.pop();
    }
    std::cout << result(ans);

    ans = true;
    std::cout << "Checking vector";
    i = 0;
    for(; i < vector.size(); i++)
    {
        if(*vector[i] != i)
        {
            ans = false;
            break;
        }
    }
    std::cout << result(ans);
    i = 0;
    ans = true;
    std::cout << "Checking list iterator";
    for(auto it = list.begin(); it != list.end(); ++it, ++i)
    {
        if(*it != i)
        {
            ans = false;
            break;
        }
    }
    std::cout << result(ans);
    std::cout << "list: front" << result(list.front()==0);
    std::cout << "list: back" << result(list.back()==999);
    std::cout << "list: push_front" << (list.push_front(-1), result(list.front()==-1));
    std::cout << "list: pop_front" << (list.pop_front(),result(list.front()==0));
    std::cout << "list: clearing" << (list.clear(),result(!list.size()));

    std::cout << "vector: []" << result(*vector[0] == 0);
    std::cout << "vector: back" << result(*vector.back()==999);
    std::cout << "vector: empty" << result(vector.empty() == false);
    std::cout << "vector: reserve" << (vector.reserve(2000),result(vector.capacity()>=2000));
    std::cout << "vector: shrink_to_fit" << (vector.shrink_to_fit(1000),result(vector.capacity()<2000));
    std::cout << "vector: swap" << (vector.swap(0,999),result(*vector[0]==999 && *vector[999]==0));
    std::cout << "vector: pop_back" << (vector.pop_back(),result(*vector.back()==998));
    std::cout << "vector: clear" << (vector.clear(),result(vector.empty()));
    

    return 0;




}