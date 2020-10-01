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
    pair<ListNode *, ListNode *> reverseln(ListNode *head, int k)
    {
        if (!head || !(head->next))
        {
            return {head, head};
        }
        ListNode *toRet = head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;
        while (curr && k--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {prev, toRet};
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next || k == 1)
        {
            return head;
        }
        ListNode *cur = head;
        int n = 0;
        while (cur)
        {
            cur = cur->next;
            n++;
        }
        int g = n / k;
        int r = n % k;
        int count = 0;
        cur = head;
        ListNode *prevend = NULL;
        ListNode *ne = NULL;
        while (count < k * g)
        {
            auto toRev = cur;
            int skipcount = 0;
            while (skipcount < k)
            {
                cur = cur->next;
                skipcount++;
            }
            auto t = reverseln(toRev, k);
            auto newhead = t.first;
            auto oldhead = t.second;
            if (count < k)
            {
                ne = newhead;
            }
            if (prevend)
            {
                prevend->next = newhead;
            }
            prevend = oldhead;
            count += k;
        }
        if (cur)
        {
            prevend->next = cur;
        }
        return ne;
    }
};