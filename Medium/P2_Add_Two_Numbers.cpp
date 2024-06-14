ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* curr1 = l1;
    ListNode* curr2 = l2;
    ListNode* res;
    if (curr1->val + curr2->val > 9) {
        res = new ListNode(curr1->val + curr2->val + carry - 10);
        carry = 1;
    } else {
        res = new ListNode(curr1->val + curr2->val + carry);
    }
    curr1 = curr1->next;
    curr2 = curr2->next;
    ListNode* prevN = res;

    ListNode* n;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->val + curr2->val + carry > 9) {
            n = new ListNode(curr1->val + curr2->val + carry - 10);
            carry = 1;
        } else {
            n = new ListNode(curr1->val + curr2->val + carry);
            carry = 0;
        }
        prevN->next = n;
        prevN = n;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == NULL) {
        while (curr2 != NULL) {
            if (curr2->val + carry > 9) {
                n = new ListNode(0);
                carry = 1;
            } else {
                n = new ListNode(curr2->val + carry);
                carry = 0;
            }
            prevN->next = n;
            prevN = n;
            curr2 = curr2->next;
        }
    } else {
        while (curr1 != NULL) {
            if (curr1->val + carry > 9) {
                n = new ListNode(0);
                carry = 1;
            } else {
                n = new ListNode(curr1->val + carry);
                carry = 0;
            }
            prevN->next = n;
            prevN = n;
            curr1 = curr1->next;
        }
    }

    if (carry == 1) {
        n = new ListNode(1);
        prevN->next = n;
    }

    return res;
}