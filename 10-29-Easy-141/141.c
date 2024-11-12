/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    //快慢指针
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL){
        slow = slow->next;
        if(fast->next == NULL)
            return NULL;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}
