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
    ListNode* swapPairs(ListNode* head) {
        ListNode* virtualNode = new ListNode(0);
        ListNode* cur = virtualNode;
        virtualNode->next = head;
        ListNode* tmp, *tmp3;
        while(cur->next != nullptr && cur->next->next != nullptr){
            tmp = cur->next;   //1
            tmp3 = cur->next->next->next;  //3
            
            cur->next = cur->next->next;  
            cur->next->next = tmp;
            cur->next->next->next = tmp3;
            
            cur = cur->next->next;
        }
        return virtualNode->next;
    }    
};