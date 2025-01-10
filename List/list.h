#ifndef LIST_H
#define LIST_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != NULL && head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        // 删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode *removeElements2(ListNode *head, int val) // 设置虚拟节点
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
    // 递归思想
    ListNode *removeElements3(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;

        if (head->val == val)
        {
            ListNode *newhead = removeElements3(head->next, val);
            delete head;
            return newhead;
        }
        else
        {
            head->next = removeElements3(head->next, val);
            return head;
        }
    }
};
class MylinkedList
{
private:
    int _size;
    ListNode *_head;

public:
    // 获取链表中的第index个节点的值，如果索引无效，则返回-1
    MylinkedList()
    {
        _head = new ListNode(0); // 虚拟节点
        _size = 0;
    }
    // 获取链表中的第index个节点的值，如果索引无效，则返回-1
    int get(int index)
    {
        int n = index;
        ListNode *cur;
        cur = _head;
        if (index >= _size)
            return -1;
        while (n--)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }
    // 在链表的第一个元素之前添加一个值为val的节点，插入后新节点
    // 成为链表的第一个节点
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = _head->next;
        _head->next = newNode;
        _size++;
    }
    // 将值为val的节点追加到链表的最后一个元素
    void addAtTail(int val)
    {
        ListNode *cur;
        cur = _head; //*
        while (cur->next)
        {
            cur = cur->next;
        }
        ListNode *newNode = new ListNode(val);
        cur->next = newNode;
        _size++;
    }
    // 在链表中的第index个节点之前添加值为 val的节点。
    // 如果index等于链表的长度，则该节点将附加到链表的末尾。
    // 如果index大于链表长度，则不会插入节点。
    // 如果index小于0，则在头部插入节点。
    void addAtIndex(int index, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (index < 0)
        {
            newNode->next = _head->next;
            _head->next = newNode;
            _size++;
        }
        else if (index > _size)
            return;
        else
        {
            int n = index;
            ListNode *cur;
            cur = _head; //*
            while (n--)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }
    }
    // 如果索引index有效，删除第index个节点
    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0)
        {
            return;
        }
        ListNode *cur = _head;
        // if (index > _size)
        //     return;
        // else if (index < 0)
        //     return;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *temp = cur->next;
        cur->next = cur->next->next;
        _size--;
        delete temp;
        temp = nullptr;
    }
    // 打印链表
    void printLinkNode()
    {
        ListNode *cur = _head;
        while (cur->next)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
// 翻转链表
class FlipList
{
public:
    ListNode *Flip(ListNode *head)
    {
        ListNode *temp;
        ListNode *prev, *cur;
        cur = head;
        prev = NULL;
        while (cur)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            // ListNode *temp = prev;  //错误的解法，指针会修改cur->next
            // prev = cur;
            // prev->next = temp;
            // cur = cur->next;
        }
        return prev;
    }
};
class Swap2
{
public:
    ListNode *swap2(ListNode *head)
    {
        ListNode *temp1, *temp2;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur != NULL && cur->next->next != NULL)
        {
            temp1 = cur->next;
            temp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;
            cur = cur->next->next;
        }
        // 需要删除添加的虚拟节点；
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};
// 删除倒数第n个节点
class deleteIndex
{
public:
    ListNode *deleteElement(ListNode *head, int index)
    {

        ListNode *fast, *slow;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        fast = dummy;
        slow = dummy;
        index++;
        while (index-- && fast != NULL) // 需要考虑index 超过链表长度
        {
            fast = fast->next;
        }
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
class ListCross
{
public:
    ListNode *Cross(ListNode *head1, ListNode *head2)
    {
        ListNode *cur1, *cur2;
        cur1 = head1;
        cur2 = head2;
        int len1 = 0;
        int len2 = 0;
        while (cur1)
        {
            cur1 = cur1->next;
            len1++;
        }

        while (cur2)
        {
            cur2 = cur2->next;
            len2++;
        }
        cur1 = head1;
        cur2 = head2; // 不能直接修改头结点的值
        if (len1 < len2)
        {
            // int temp = len2;
            // len1 = len2;
            // len2 = temp;
            // ListNode *tempNode = head2;
            // head1 = head2;
            // head2 = tempNode;
            swap(len1, len2);
            swap(cur1, cur2);
        }
        int n = len1 - len2;
        while (n--)
        {
            // head1 = head1->next;
            cur1 = cur1->next;
        }
        // ListNode *crossNode = new ListNode(0);
        // while (head1 == head2 && head1 && head2)
        // {
        //     head1 = head1->next;
        //     head2 = head2->next;
        // }
        // if (crossNode == NULL)
        //     return NULL;
        // return crossNode;   //逻辑出问题
        while (cur1 != nullptr)
        {
            if (cur1 == cur2)
            {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
};
// class CircleNode
// {
// public:
//     ListNode *index(ListNode *head)
//     {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         int step = 0;
//         while (fast != slow && fast->next != NULL)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//             step++;
//         }
//         if (fast->next == NULL)
//             return NULL;
//         ListNode *idx = head;
//         while (step--)
//         {
//             idx = idx->next;
//         }
//         return idx;
//     }
// };
// Floyd 判圈算法
class CircleNode
{
public:
    ListNode *index(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL; // 空链表或只有一个节点，不可能有环

        ListNode *fast = head;
        ListNode *slow = head;

        // 检测环
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                // 检测到环，寻找环入口
                ListNode *idx = head;
                while (idx != slow)
                {
                    idx = idx->next;
                    slow = slow->next;
                }
                return idx; // 返回环的入口节点
            }
        }

        return NULL; // 无环
    }
};

#endif