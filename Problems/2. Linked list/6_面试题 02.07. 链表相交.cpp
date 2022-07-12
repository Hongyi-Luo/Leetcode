/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;

        int sizeA = 0;
        int sizeB = 0;
        while(curA!=NULL){
            sizeA++;
            curA = curA->next;
        }

        while(curB!=NULL){
            sizeB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        int gap = sizeA - sizeB;
        if(gap < 0){
            while(gap<0){
                curB = curB->next;
                gap++;
            }
        }
        else{
            while(gap>0){
                curA = curA->next;
                gap--;
            }
        }

        while(curA!=NULL && curB!= NULL){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};