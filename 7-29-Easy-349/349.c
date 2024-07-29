/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int k = 0,max = nums1Size;
    *returnSize = 0;
    if (nums2Size > max)
        max = nums2Size;
    int *ans = malloc(sizeof(int) * max);
    for (int i = 0; i < nums1Size; i++){
        for (int j = 0; j < nums2Size; j++ ){
            if (nums1[i] == nums2[j] ){
                int count = 0;
                for(int l = 0 ; l < k;l ++){
                    if (nums1[i] == ans[l])
                        count++;
                }
                if(count > 0)
                    continue;
                ans[k] = nums1[i];
                k++;
            }
        }
    }
    *returnSize = k ;
    return ans;
}


//hash表
	struct unordered_set {
    int key;
    UT_hash_handle hh;
};

struct unordered_set* find(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp = find(hashtable, ikey);
    if (tmp != NULL) return;
    tmp = malloc(sizeof(struct unordered_set));
    tmp->key = ikey;
    HASH_ADD_INT(*hashtable, key, tmp);
}

int* getIntersection(struct unordered_set** set1, struct unordered_set** set2, int* returnSize) {
    if (HASH_COUNT(*set1) > HASH_COUNT(*set2)) {
        return getIntersection(set2, set1, returnSize);
    }
    int* intersection = malloc(sizeof(int) * (HASH_COUNT(*set1) + HASH_COUNT(*set2)));
    struct unordered_set *s, *tmp;
    HASH_ITER(hh, *set1, s, tmp) {
        if (find(set2, s->key)) {
            intersection[(*returnSize)++] = s->key;
        }
    }
    return intersection;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;
    struct unordered_set *set1 = NULL, *set2 = NULL;
    for (int i = 0; i < nums1Size; i++) {
        insert(&set1, nums1[i]);
    }
    for (int i = 0; i < nums2Size; i++) {
        insert(&set2, nums2[i]);
    }

    return getIntersection(&set1, &set2, returnSize);
}

//排序+双指针
//
int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int index1 = 0, index2 = 0;
    int* intersection = malloc(sizeof(int) * (nums1Size + nums2Size));
    while (index1 < nums1Size && index2 < nums2Size) {
        int num1 = nums1[index1], num2 = nums2[index2];
        if (num1 == num2) {
            // 保证加入元素的唯一性
            if (!(*returnSize) || num1 != intersection[(*returnSize) - 1]) {
                intersection[(*returnSize)++] = num1;
            }
            index1++;
            index2++;
        } else if (num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }
    return intersection;
}

