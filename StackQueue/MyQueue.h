// 使用栈实现队列的操作：

// push(x): 讲一个元素放入队列中
// pop(): 从队列首部移除元素
// peek(): 返回队列首部的元素
// empty(): 返回队列是否为空
// 使用两个栈，一个栈实现push，一个栈实现pop，但是pop的时候需要从pop栈
// 中弹出数据，但是如果pop栈如果是空的话，需要把另外一个栈的数据全部pop出来
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <stack>
using namespace std;
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {}
    void push(int x)
    {
        stIn.push(x);
    }
    int pop()
    {
        // 如果stOut是空的情况下
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    int peek()
    {
        // 方法一
        //  int result;
        //  if(stOut.empty()){
        //      result = stIn.top();
        //  }
        //  else result = stOut.top();
        //  return result;
        //  方法二 直接调用已有的pop方法（出队），后进队
        int result = this->pop();
        stOut.push(result);
        return result;
    }
    bool empty()
    // {
    //     if (stIn.empty() && stOut.empty())
    //     {
    //         return true;
    //     }
    //     else
    //         return false;
    // }
    {
        return stIn.empty() && stOut.empty();
    }
};
#endif