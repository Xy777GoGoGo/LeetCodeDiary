int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0,k = 0;
    for(int i =0; i<numsSize; i++){
        if(nums[i])
            k++;
        else if (nums[i] == 0){
            if (k > max)
                max = k;
            k = 0;
        }
    }
    if(k > max)
        max =k;
    return max;
}
//一次遍历就行
//
