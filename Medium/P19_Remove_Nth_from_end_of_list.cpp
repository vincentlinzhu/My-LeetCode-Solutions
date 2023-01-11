// Reverse Method
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* tempHead = reverseList(head);
    ListNode* tracker = tempHead;
    ListNode* remove = tempHead;

    if (!tempHead->next) {
        return NULL;
    }
    if (n == 1) {
        ListNode* newHead = tempHead->next;
        tempHead->next = NULL;
        head = reverseList(newHead);
        return head;
    }

    int counter = 1;
    while (counter < n - 1) {
        tracker = tracker->next;
        remove = tracker;
        counter++;
    }
    if (tracker->next) {
        remove = tracker->next;
    }
    if (remove) {
        tracker->next = remove->next;
        remove->next = NULL;
    }

    head = reverseList(tempHead);
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Forward Method
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = 1;
    ListNode* tracker = head;

    while (tracker->next) {
        tracker = tracker->next;
        length++;
    }

    if (n == 1) {
        if (length == 1) {
            return NULL;
        }

        tracker = head;
        while (tracker->next->next){
            tracker = tracker->next;
        }
        tracker->next = NULL;
        return head;
    }

    tracker = head;
    if (n == length) {
        tracker = tracker->next;
        head = tracker;
        return head;
    }

    for (int i = 0; i < length - n - 1; i ++) {
        tracker = tracker->next;
    }

    if (tracker->next) {   
        tracker->next = tracker->next->next;
    }
    return head;
}