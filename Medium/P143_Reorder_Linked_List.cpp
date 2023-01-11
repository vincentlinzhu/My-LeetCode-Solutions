void reorderList(ListNode* head) {
    // Find Middle
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse Second Half
    ListNode* second = slow->next;
    slow->next = NULL;
    ListNode* prev = NULL;
    while (second != nullptr) {
        ListNode* temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    // Merge 2 Lists
    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
    
}