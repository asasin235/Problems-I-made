/*
    Time complexity: O(n/2)
    Space complexity: O(1)

    Where 'n' is the number of elements in the linked list
*/

Node *findMiddle(Node *head) {
    // If head is null just return null
    if (head == NULL) {
        return head;
    }
    // If the Linked List has just 1 element that element is the middle
    if (head->next == NULL) {
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}