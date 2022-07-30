class Solution {
    int findLength(ListNode* head){
        if(head == NULL) return 0;
        return 1 + findLength(head->next);
    }
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int l1 = findLength(head1);
        int l2 = findLength(head2);
        
        if(l1 > l2){
            swap(head1, head2);
        }
        
        int carry = 0, sum = 0;
        ListNode* start = head1;
        ListNode* temp = 0;
        while(head1){
            sum = 0;
            sum += head1->val + head2->val;
            sum += carry;
            head1->val = sum%10;
            carry = sum/10;
            temp = head1;
            head1 = head1->next;
            head2 = head2->next; 
        }
        sum = 0;
        while(head2){
            sum = 0;
            sum += head2->val;
            sum += carry;
            head2->val = sum%10;
            carry = sum/10;
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
        if(carry){
            ListNode *n = new ListNode(carry);
            temp->next = n;
        }
        return start;
    }
};