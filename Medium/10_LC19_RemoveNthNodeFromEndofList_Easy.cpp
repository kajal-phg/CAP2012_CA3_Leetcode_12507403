class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        int length = 0;
        ListNode* current = head;
   
        while (current != NULL) {
            length++;
            current = current->next;
        } 
        int position = length - n;

        current = &dummy;

        
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        current->next = current->next->next;

        return dummy.next;
    }
};

