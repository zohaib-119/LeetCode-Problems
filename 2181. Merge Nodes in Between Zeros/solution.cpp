struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *p = head;
        while (p->next)
        {
            while (p->next && p->next->val != 0)
            {
                p->val += p->next->val;
                p->next = p->next->next;
            }
            if (!p->next->next)
            {
                p->next = nullptr;
            }
            else
                p = p->next;
        }
        return head;
    }
};