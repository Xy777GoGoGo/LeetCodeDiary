//瞅了参考思路
//


typedef struct {
 int *val;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = malloc(sizeof(NumArray));
    obj->val = malloc(sizeof(int) * (numsSize + 1));//给数组开辟空间
    obj->val[0] = 0;
    for (int i = 0; i < numsSize; i++){
        obj->val[i + 1] = obj->val[i] + nums[i];//该数组每项存放前n项和
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->val[right + 1] - obj->val[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->val);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
