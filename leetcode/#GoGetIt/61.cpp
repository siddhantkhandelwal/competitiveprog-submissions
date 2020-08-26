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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
        {
            return head;
        }
        ListNode *temp = head;
        int l = 0;
        while (temp)
        {
            temp = temp->next;
            l++;
        }
        k = k % l;
        if (!k)
        {
            return head;
        }
        int toCross = l - k;
        temp = head;
        ListNode *setToNull;
        while (toCross)
        {
            if (toCross == 1)
            {
                setToNull = temp;
            }
            temp = temp->next;
            toCross--;
        }
        setToNull->next = NULL;
        ListNode *oldHead = head;
        head = temp;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = oldHead;
        return head;
    }
};