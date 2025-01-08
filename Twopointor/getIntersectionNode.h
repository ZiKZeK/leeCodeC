struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    { // 如果两个链表相交，那么这两个长度会有关联
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 默认A是更加长的
        if (lenA < lenB)
        {
            int temp = lenA;
            lenA = lenB;
            lenB = temp;
            curA = headB;
            curB = headA;
        }
        while (lenA > lenB)
        {
            curA = curA->next;
            lenA--;
        }
        while (curA != nullptr)
        {
            if (curA == curB)
            {
                return curA;
            }
            else
            {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};