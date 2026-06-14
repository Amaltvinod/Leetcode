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
    int pairSum(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *prev=nullptr,*cur=slow;
        while(cur){
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        ListNode *p1=head,*p2=prev;
        int ans=0;
        while(p1 && p2){
            ans=max(ans,p1->val+p2->val);
            p1=p1->next;
            p2=p2->next;
        }
        return ans;
    }
};