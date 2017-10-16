/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        bool flag=false;
        ListNode* delPtr=NULL;
        ListNode* prevPtr=NULL;
        int delay=1;

        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next){
            if(delay==0){
                prevPtr=head;
            }
            if(count==n){
                cout<<"\nAssigning delPtr to:"<<head->val;
                delPtr=head;
                flag=true;
                prevPtr=NULL;
                
            }
            if(flag){ 
             if(ptr->next==NULL && prevPtr==NULL)
              {
               cout<<"\nDelete when prevPtr is null:"<<delPtr->val;
               ListNode* delNode=head;
               head=delPtr->next;
               delete(delNode);
               return head;
              }
            else if(ptr->next==NULL){
              cout<<"\nDelete when prev isnt null:"<<delPtr->val;
              cout<<"\nprevptr:"<<prevPtr->val<<"\t delPTR: "<<delPtr->val<<"\t ptr: "<<ptr->val;
              ListNode* delNode=delPtr;
              prevPtr->next=delPtr->next;
              delete(delNode);
              return head;
                }
            }
          count++;
            if(flag){
                delay--;
                if(delay<0)
                    prevPtr=prevPtr->next;
          delPtr=delPtr->next;        
           } 
            
   }     
        return head;
    }
};
