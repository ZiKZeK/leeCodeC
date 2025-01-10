#ifndef MYSTACK_H
#define MYSTACK_H
#include <queue>
using namespace std;
// push(x): 元素进栈
// pop(): 移除栈顶元素
// top(): 获取栈顶元素
// empty(): 返回栈是否为空

// 能使用队列的基本方法：
// push to back, peek/pop from front, size, is empty
class myStack
{
    queue<int> que;

public:
    myStack() {}
    void push(int x)
    {
        que.push(x);
    }
    void pop()
    {
        if (que.empty())
            return;
        int size = que.size() - 1;

        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }
    int top()
    {
        return que.back();
    }
    bool empty()
    {
        return que.empty();
    }
};
#endif
