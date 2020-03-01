#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n)
{
    if (0 == n)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;

    for (int i = 1; i < n; i++)
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }

    return head;
}

void deleteLinkedList(ListNode *head)
{
    while (head)
    {
        ListNode *cur = head;
        head = cur->next;
        delete cur;
    }

    return;
}

void printLinkedList(ListNode *head)
{

    while (head)
    {
        cout << head->val << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}

class Solution
{
public:
    //206
    ListNode *reverseList(ListNode *head)
    {

        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    //203
    ListNode *removeElements(ListNode *head, int val)
    {
        
        while (head && head->val == val)
        {
            ListNode* cur = head;
            head = head->next;
            delete cur;
        }
        
        if(NULL == head)
            return NULL;
        ListNode *cur = head;

        while (cur->next)
        {
            if(cur->next->val == val)
            {
                ListNode* del = cur->next;
                cur->next = cur->next->next;
                delete del;
            }
            else
            {
                cur = cur->next; 
            }
 
        }

        return head;
    }

    //203
    ListNode *removeElements2(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;

        while(cur->next)
        {
            if(cur->next->val == val)
            {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete del;
            }
            else
            {
                cur = cur->next;
            }
            
        }

        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;

    }

    //24
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next =head;
        ListNode* cur = dummyHead;

        while(cur->next && cur->next->next)
        {

                ListNode *temp1 = cur->next;
                ListNode *temp2 = temp1->next;
                ListNode *next = temp2->next;
                temp2->next = temp1;
                temp1->next = next;
                cur->next =temp2;
            
                cur = temp1;       
            
        }

        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;

    }

    //237
    void deleteNode(ListNode* node) 
    {

        node->val = node->next->val;
        ListNode* del = node->next;
        node->next = node->next->next;
        delete del;
        
    }

    //19
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;

        for(int i=0;i<n+1;i++)
        {
            q = q->next; //题目保证有效          
        }

        while(q)
        {
            p= p->next;
            q = q->next;
        }
        ListNode* del = p->next;
        p->next = p->next->next;

        delete del;
        ListNode *ret=dummyHead->next;
        delete dummyHead;
        return ret;

    }
};

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 3};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode *head5=Solution().swapPairs(head);
    printLinkedList(head5);
    head=Solution().swapPairs(head);
    printLinkedList(head);
    ListNode *head2 = Solution().reverseList(head);
    printLinkedList(head2);
    ListNode *head3 = Solution().removeElements2(head2, 3);
    printLinkedList(head3);

     ListNode *head4 = Solution().removeNthFromEnd(head3, 2);
     printLinkedList(head4);
    deleteLinkedList(head4);

    return 0;
}