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
    // Time complexity : O(N)
    // Space Complexity : O(1)
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *post = head;
        ListNode *prev = NULL;
        while (curr)
        {
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        return prev;
    }
};