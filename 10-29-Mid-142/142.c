/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct hashTable{
    struct ListNode* key;
    UT_hash_handle hh;
};
struct hashTable* hashtable;

struct hashTable* find(struct ListNode* ikey){
    struct hashTable* tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}
void insert(struct ListNode* ikey) {
    struct hashTable* tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashtable, key, tmp);
}

struct ListNode *detectCycle(struct ListNode *head) {
    //第一个可以连续跟踪 next 指针再次到达的节点
    hashtable = NULL;
    while(head != NULL){
        if(find(head) == NULL){
            insert(head);
            head = head->next;
        }
        else
            return head;
        
    }
    return NULL;
}







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)
        return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* ans = head;
    while(fast != NULL){
        slow = slow->next;
        if(fast->next == NULL)
            return NULL;
        fast = fast->next->next;
        if(slow == fast){
            while(true){
                if(slow == ans)
                    return ans;
                slow = slow->next;
                ans = ans->next;
            }
        }
    }
    return NULL;
}
