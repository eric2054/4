ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->link;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->link;
        }

        carry = sum / 10;
        current->link = new ListNode(sum % 10);
        current = current->link;
    }
    return dummyHead->link;
}
