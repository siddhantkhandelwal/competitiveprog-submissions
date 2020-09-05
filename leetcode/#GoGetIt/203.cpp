/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *nh = new ListNode(0);
        nh->next = head;
        ListNode *cur = nh;
        while (cur)
        {
            if (cur->next && cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return nh->next;
    }
};