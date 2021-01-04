/*
    Time complexity: O(n)
    Space complexity: O(1)

    Where 'n' is the number of elements in the linked list
*/

Node *findMiddle(Node *head) {
    Node *p = head;
    int numberOfNodes = 0;
    while (p->next != NULL) {
        numberOfNodes++;
        p = p->next;
    }

    int mid = numberOfNodes / 2;

    Node *ptr = head;
    while (mid--) {
        ptr = ptr->next;
    }
    if (numberOfNodes % 2 == 0) {
        ptr = ptr->next;
    }
    return ptr;
}