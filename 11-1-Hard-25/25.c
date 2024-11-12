/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head == NULL)
        return NULL;
    if(k == 1)
        return head;
    struct ListNode* node = head;
    struct ListNode* pre = malloc(sizeof(struct ListNode));
    pre->val = 0;
    pre->next = head;
    struct ListNode* newhead = pre;
    int number = 1;
    while(node != NULL){
        //先判断能不能到达数量
        struct ListNode* mid = node;
        while(mid->next != NULL){
            number++;
            mid = mid->next;
            if(number == k)
                break;
        }
        if(number == k){
            //到了数量就排序，并且pre指向排好序的头节点，node保存下一个链表的头节点
            //这时node指向组里第一个结点，mid指向组里最后一个节点，pre指向上一组最后一个节点
            //下面就是翻转链表
            struct ListNode* prev = node;
            struct ListNode* mint = node->next;
            while(mint != mid){
                struct ListNode* nextt = mint->next;
                mint->next = prev;
                prev = mint;
                mint = nextt;
            }
            pre->next = mint;
            pre = node;
            node = mint->next;
            mint->next = prev;
            pre->next = node;
            number = 1;
        }
        //没到数量就break
        else if (number < k){
            pre->next = node;
            return newhead->next;
        }
    }
    return newhead->next;
}
