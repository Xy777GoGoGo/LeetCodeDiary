/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3
struct ListNode* reverseList(struct ListNode* head) {
    // struct ListNode* prev = NULL;
    // struct ListNode* curr = head;
    // while(curr){
    //     struct ListNode* nnext = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = nnext;
    // }
    // return prev;
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
