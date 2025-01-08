struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(0), next(nullptr) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        while (fast != nullptr && n + 1 > 0)
        {
            fast = fast->next;
            n--;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};