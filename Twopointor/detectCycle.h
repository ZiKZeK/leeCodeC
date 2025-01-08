struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast, *slow;
        fast = dummy;
        slow = dummy;
        int step = 0;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                fast = dummy;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
            step++;
        }
        return nullptr;
    }
};