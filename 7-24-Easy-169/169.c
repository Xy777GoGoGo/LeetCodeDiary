//暴力求解超时
//1.hash表法
////hh是内部使用的hash处理句柄，在使用过程中，只需要在结构体中定义一个UT_hash_handle类型的变量即可，不需要为该句柄变量赋值，但必须在该结构体中定义该变量
struct hashTable{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable = NULL;
int ans = 0;

struct hashTable* find(int ikey) {
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}
//第一个参数就是最开始让定义的那个空白指针。
//第二个参数是你要查找的key值（注意是指针类型，这里的nums是个数组，本来就是地址，如果要查一个int类型的数记得前面加“&”取地址）。
//第三个参数是如果找到的话就存在第三个参数里面，所以新建了一个指针作为容器（找不到就不给tmp赋值）。

int insert(int ikey, int ival, int numsSize) {
    struct hashTable* it = find(ikey);
    if (NULL == it) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
//HASH_ADD_INT()；

//第一个参数还是开头那个空白指针
//第二个参数是结构体中对应的成员名称（结构体中定义的是int key；如果定义int key1；这里就填key1）
//第三个参数是要插入的数据，已经提前放在结构体里面了
        if(tmp->val > (numsSize / 2)){
                ans = tmp->key;
                return ans;
        }
    }else{
        it->val = it->val + 1;
    }
    return -1;
}

int majorityElement(int* nums, int numsSize) {
    hashtable = NULL;
    for(int i = 0; i < numsSize; ++i){
        struct hashTable* it = find(nums[i]);
        if(NULL == it){
            insert(nums[i], 1, numsSize);//为空时插入节点
        }else{
            it->val += 1;
            if(it->val > (numsSize / 2)){
                ans = it->key;
                break;
            }
        }
    }
    return ans;
}

//2.排序
//int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize / 2];
}

//3.随机化
//int majorityElement(int* nums, int numsSize) {
    int sj;
    while(true){
        int nb = 0;
        sj = rand () % numsSize;
        for(int i = 0; i < numsSize; i++){
            if (nums[i] == nums[sj]){
            nb++;
            }
         }
        if ( nb > numsSize / 2)
            return nums[sj];
    }
    return -1;
}

//4.Boyer-Moore算法
//如果我们把众数记为 +1，把其他数记为 −1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。
//我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；

/*我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：

如果 x 与 candidate 相等，那么计数器 count 的值增加 1；

如果 x 与 candidate 不等，那么计数器 count 的值减少 1。

遍历完成后，candidate 即为整个数组的众数。
int majorityElement(int* nums, int numsSize) {
    int count ,cand;
    count = 0;
    for (int i ; i < numsSize; i++ ){
        if (count == 0)
            cand = nums[i];
        if (nums[i] == cand)
            count++;
        else 
            count--;
    }
    return cand;
}
