#include<stdio.h>
#include"uthash.h"
#include<stdlib.h>
typedef struct hash{
    int key;  // 键
    int index;  // 索引值
    UT_hash_handle hh; // 让结构体哈希柄
} *hash_ptr;

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    hash_ptr p=NULL, tables=NULL;
    for(int i=0;i<numsSize;i++){
        if(tables) HASH_FIND_INT(tables, &(nums[i]), p);
        if(p&&(i-p->index)<=k) return true;
        p=(hash_ptr)malloc(sizeof(*p));
        p->key=nums[i];
        p->index=i;
        HASH_ADD_INT(tables, key, p);
    }
    return false;
}
//借鉴他人的代码
