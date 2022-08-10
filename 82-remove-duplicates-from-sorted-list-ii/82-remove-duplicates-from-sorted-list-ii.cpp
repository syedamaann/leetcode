class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // check for empty and single node
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* cur = head;
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* pre = fake;
        
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                if(cur->next->next == nullptr){
                    pre->next = nullptr;
                    break;
                }
                else if(cur->next->val != cur->next->next->val){
                    pre->next = cur->next->next;
                    cur = pre->next; 
                }
                else{
                   cur = cur->next; 
                }
            }
            else{
                if(cur->next->next == nullptr) {
                    break;
                }
                else{
                    pre = pre->next;
                    cur = cur->next;
                } 
            }  
        }
        return fake->next;
    }
};