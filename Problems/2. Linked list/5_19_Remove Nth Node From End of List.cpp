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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualNode = new ListNode(0, head);        
        int point = n;
        ListNode* cur , *pre;
        cur = virtualNode;
        pre = virtualNode;
        while(cur!=NULL && point > 0){
            cur = cur->next;
            point--;
                                 
        }
        cur = cur->next;
        while(cur!=NULL){
            cur = cur->next;
            pre = pre->next;
        }  
        
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        
        return virtualNode->next;
    }
};