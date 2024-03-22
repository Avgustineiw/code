class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0, mid = 0, pos = 0;
        ListNode* old = head;
        
        while (old != NULL) {
            old = old->next;
            len++;    
        }

        if (pos % 2 == 0) {
            mid = len / 2;
        }
        else {
            mid = (len / 2) + 1;
        }
         
        ListNode* curr = head;
        ListNode* prev = NULL;

        if (len == 2 && head->val != head->next->val) {
            return false;
        }


        while (curr->next != NULL) {
            if (pos < mid) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            else if (pos == mid && len % 2 != 0) {
                curr = curr->next;

                if (prev->val != curr->val) {
                    return false;
                }
            }
            else if (pos == mid && len % 2 == 0) {
                if (curr->val != prev->val) {
                    return false;
                }
            }
            else {
                prev = prev->next;
                curr = curr->next;

                if (prev->val != curr->val) {
                    return false;
                }
            }
            std::cout << pos << " " << prev->val << " " << curr->val << '\n';
            pos++;
        }

        return true;
    }
};
