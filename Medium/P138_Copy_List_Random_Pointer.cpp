Node* copyRandomList(Node* head) {
    // 2 passes of the list
    unordered_map<Node*, Node*> m;
    // Pass 1:
    Node* curr = head;
    while (curr != NULL) {
        m[curr] = new Node(curr->val);
        curr = curr->next;
    }
    // Pass 2:
    curr = head;
    Node* cy;
    while (curr != NULL) {
        cy = m[curr];
        cy->next = m[curr->next];
        cy->random = m[curr->random];
        curr = curr->next;
    }

    curr = head;
    return m[curr];
}