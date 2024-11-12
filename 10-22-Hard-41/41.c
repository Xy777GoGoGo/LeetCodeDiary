int firstMissingPositive(int* nums, int numsSize) {
    //将数组做成为hashmap
    //因为答案最终只在【1 - numsSize + 1】中
    //利用负号标记相应的数字
    //第一步先把数组内的原来的负数标记为numSize + 1
    for(int i = 0; i < numsSize; i++){
        if(nums[i] <= 0)
            nums[i] = numsSize + 1;
    }
    //这时所有元素都为正的了
    //第二步进行映射也就是把1映射到第0位，2映射到第1位
    for(int i = 0; i < numsSize; i++){
        if(abs(nums[i]) > 0 && abs(nums[i]) <= numsSize)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    //上面是用负号标记了元素，代表hash表有值
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0)
            return i + 1;
    }
    return numsSize + 1;
}
