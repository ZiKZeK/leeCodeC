#include <iostream>
using namespace std;
#include "list.h"

int main()
{
    ListNode *head = new ListNode(5); // 自定义构造函数
    ListNode *second = new ListNode(4);
    ListNode *third = new ListNode(3);
    head->next = second;
    second->next = third;
    cout << head->val << endl;
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << endl;
    FlipList a;
    ListNode *flipHead = a.Flip(head);
    cur = flipHead;
    while (cur)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << endl;
    Swap2 b;
    ListNode *swapHead = b.swap2(flipHead);
    cur = swapHead;
    while (cur)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << endl;

    deleteIndex c;
    ListNode *removeElement = c.deleteElement(swapHead, 4);
    removeElement = c.deleteElement(swapHead, 2);
    cur = swapHead;
    while (cur)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << endl;

    MylinkedList *linkedlist = new MylinkedList();
    linkedlist->addAtHead(1);
    linkedlist->addAtTail(3);
    linkedlist->addAtIndex(1, 2);
    cout << linkedlist->get(1) << endl;
    linkedlist->deleteAtIndex(1);
    cout << linkedlist->get(1) << endl;
    linkedlist->printLinkNode();
    return 0;
}
