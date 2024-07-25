//首先排序
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
bool containsDuplicate(int* nums, int numsSize) {
    //排序
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    for (int i = 0; i < numsSize - 1; i++){
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}
//hash表
//struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}
