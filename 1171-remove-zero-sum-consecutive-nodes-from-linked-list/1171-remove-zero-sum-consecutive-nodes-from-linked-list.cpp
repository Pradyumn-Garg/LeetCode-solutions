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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // This answer is valid for any integer sum K.
        int K=0;
        struct ListNode* ans= new ListNode(0);
        ans->next=head;
        map <int,ListNode*> m;
        m[0]=ans;
        int sum=0;
        
        
        while(head!=NULL){
            sum+=head->val;
            
            if(m.find(sum-K)!=m.end()){
                sum=sum-K;
                int aux=sum;
                struct ListNode* temp=m[sum-K]->next;
                struct ListNode* start=m[sum-K];
                
                while(temp!=head){
                    aux+=temp->val;
                    m.erase(aux);
                    temp=temp->next;
                }
                start->next=head->next;
            }
            
            else if(m.find(sum-K)==m.end()){
                m[sum]=head;
            }
            
            head=head->next;
        }
        return ans->next;
    }
};