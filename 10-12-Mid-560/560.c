typedef struct hash{
    int key;
    int val;//记的次数
    UT_hash_handle hh;
}hash_table;

int subarraySum(int* nums, int numsSize, int k){
    hash_table* hp = NULL;
    hash_table* p = NULL;
    p = malloc(sizeof(hash_table));
    p->key = 0;
    p->val = 1;//存入0的时候节点
    HASH_ADD_INT(hp, key, p);//.插入数据
    int cur = 0;
    int ret = 0;
    for (int i = 0; i < numsSize; ++i){
        cur += nums[i];
        int need = cur - k;//要找的key
        HASH_FIND_INT(hp, &need, p);//传出p
        if (p != NULL){//找到了p（此时cur没存入，避免了二次计算cur）
            ret += p->val;
        }
        HASH_FIND_INT(hp, &cur, p);//看有没有cur
        if (p == NULL){//没有cur
            p = malloc(sizeof(hash_table));
            p->key = cur;
            p->val = 0;
            HASH_ADD_INT(hp, key, p);
        }
        ++p->val;//有的话直接加次数
    }
    return ret;
}

