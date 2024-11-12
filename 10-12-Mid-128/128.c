typedef struct Node{
    int val;
    struct Node* next;
}HashNode;
bool contain(HashNode *hashmap, int val, int size){
    HashNode *node = &hashmap[hashnum(val, size)];
    HashNode *tail = node->next;
    //数组里面不放东西
    while(tail){
        if(tail->val == val)
            return true;
        tail = tail->next;
    }
    return false;
}
void add(HashNode *hashmap, int val, int size){
    //去重
    if(contain(hashmap, val, size))     return;

    HashNode *head = &hashmap[hashnum(val, size)];
    HashNode *q = malloc(sizeof(HashNode));
    q->val = val;
    q->next = head->next;
    head->next = q;
}
int hashnum(int val, int size){
    return abs(val) % size;
}
int longestConsecutive(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    int ans = 1;
    HashNode *hashmap = malloc(sizeof(HashNode) * numsSize);
    //初始化
    memset(hashmap, 0, sizeof(HashNode) * numsSize);
    for(int i = 0; i < numsSize; i++)
        add(hashmap, nums[i], numsSize);
    //此时nums全部放入hashmap

    //下面枚举每个x，不断匹配x + 1，x + 2...
    //如果x - 1存在跳过
    for(int i = 0; i < numsSize; i++){
        int ans1 = 1;
        //查找x - 1是否存在
        int mid = nums[i] + 1;
        if(contain(hashmap, nums[i] - 1, numsSize))
            continue;
        while(contain(hashmap, mid, numsSize)){
            mid++;
            ans1++;
        }
        if(ans1 > ans)
            ans = ans1;
    }
    return ans;
}
