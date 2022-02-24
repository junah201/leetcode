// 206. Reverse Linked List
// 02/24/2022 21:37	Accepted	19 ms	8.3 MB	cpp

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *saveNode = head;
        ListNode *preNode = nullptr;
        ListNode *nextNode;
        while (saveNode != nullptr)
        {
            nextNode = saveNode->next;
            saveNode->next = preNode;
            preNode = saveNode;
            saveNode = nextNode;
        }
        return preNode;
    }
};