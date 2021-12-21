#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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

ListNode* reverseList2(ListNode* head) {
    if (head == NULL) {
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr->next != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    return curr;
}

ListNode* recursiveReverseList(ListNode* prev, ListNode* head) {
    if (head == NULL) {
        return prev;
    }
    ListNode* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    return recursiveReverseList(prev, head);
}

ListNode* recursiveReverseList2(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* p = recursiveReverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

int main() {
    ListNode * head = NULL ;
    ListNode * tail = NULL ;
    ListNode *p = NULL ;

    head = new ListNode ;
    head -> val = 1;
    head -> next = NULL ;
    tail = head ;

    p = new ListNode ;
    p -> val = 2;
    p -> next = NULL ;
    tail -> next = p;
    tail = p;

    p = new ListNode ;
    p -> val = 3;
    p -> next = NULL ;
    tail -> next = p;
    tail = p;
    
    for (p = head ; p; p = p->next ) {
        cout << p->val << " ";
    }
    cout << endl;
    
    head = reverseList(head);

    for (p = head ; p; p = p->next ) {
        cout << p->val << " ";
    }
    cout << endl;

    head = reverseList2(head);

    for (p = head ; p; p = p->next ) {
        cout << p->val << " ";
    }
    cout << endl;
    
    head = recursiveReverseList(NULL, head);

    for (p = head ; p; p = p->next ) {
        cout << p->val << " ";
    }
    cout << endl;
    
    head = recursiveReverseList2(head);

    for (p = head ; p; p = p->next ) {
        cout << p->val << " ";
    }
    cout << endl;
    
    return 0;
}
