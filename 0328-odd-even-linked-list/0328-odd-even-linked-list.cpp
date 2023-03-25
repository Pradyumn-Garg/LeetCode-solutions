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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *evenstart=NULL, *oddend=NULL, *evenend=NULL, *oddstart=NULL;
        int index=1;
        while(head){
            if(index%2==0){
                if(!evenstart){
                    evenstart=head;
                    evenend=head;
                }
                else{
                    evenend->next=head;
                    evenend=head;
                }
            }
            else{
                if(!oddend){
                    oddend=head;
                    oddstart=head;
                }
                else{
                    oddend->next=head;
                    oddend=head;
                }
            }
            index++;
            if(!head->next){
                break;
            }
            head=head->next;
        }
        oddend->next=evenstart;
        evenend->next=NULL;
        return oddstart;
    }
};