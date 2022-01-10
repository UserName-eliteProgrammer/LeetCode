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
    // recursive
    struct ListNode* ans = NULL;
    struct ListNode* help(struct ListNode *node)
    {   
        if(node->next == NULL)
        {   
            ans = node;
            return node;
        }

        struct ListNode *nodeNext = node->next;
        node->next = NULL;
        struct ListNode *newNext = help(nodeNext);
        newNext->next = node;
        return node;
    }

    // iterative
    struct ListNode *help2(struct ListNode* head)
    {
        struct ListNode *prev = NULL;
        struct ListNode *currNodeNext;
        while(head != NULL)
        {   
            currNodeNext = head->next;
            head->next = prev;
            prev = head;
            head = currNodeNext;
        }
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) 
    {   
        if(head == NULL) return NULL;
        help(head);
        return ans;
    }
};