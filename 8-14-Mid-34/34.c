/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findn(int * nums, int numsSize,int target){
    int lo = 0, hi = numsSize - 1;
    while (lo <= hi){
        int mid = (hi - lo) / 2 + lo;
        if (nums[mid] < target)
            lo = mid + 1;
        else    
            hi = mid - 1; // 2 2 3 3 4     mid =2 , hi = 1    mid = 0, hi = 0,      hi =-1
                          // 0 0 1 1 2 2    mid = 2, lo = 1    mid = 2, lo = 3   mid = 4, hi =4  
                          // 1 2 2 3 4      mid = 2, hi = 1    
                          //看上面 lo 和 hi 的动作，lo总会定位到第一个target
                          //如果target在整个数组的右边，此时，lo会一直加一，变成了numsize
    }
    return lo;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    //先找等于target，再找大于target
    int *ans = (int *) malloc( 2 * sizeof(int));
    *returnSize = 2;
    int le = findn( nums, numsSize, target);
    int ri = findn( nums, numsSize, target + 1) - 1;
    if (le < numsSize && nums[le] == target){
        ans[0] = le;
        ans[1] = ri;
    }
    else {
        ans[0] = -1;
        ans[1] = -1;
    }
    return ans;
}
