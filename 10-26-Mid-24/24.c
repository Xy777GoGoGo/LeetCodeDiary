/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* temp = dummyHead;//代表当前到达的节点,每次要交换后面的两个节点
    while(temp->next != NULL && temp->next->next != NULL){
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead->next;
}

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    //newHead 表示新的链表的头节点，原始链表的第二个节点
    struct ListNode* newhead = head->next;
    head->next = swapPairs(newhead->next);
    newhead->next = head;
    return newhead;
}
