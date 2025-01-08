// 定义链表
struct ListNode
{
    int val; // 代表int类型数据
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 虚拟头结点  这道题目不需要设置虚拟头结点
        //  ListNode * dummy =new ListNode(0);
        //  dummy->next = head;
        // 设置两个指针
        ListNode *fast, *slow;
        fast = head;
        slow = nullptr;
        while (fast != nullptr)
        {
            ListNode *temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
        }
        return slow;
    }
};