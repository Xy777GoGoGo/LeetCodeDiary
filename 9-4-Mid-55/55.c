bool canJump(int* nums, int numsSize) {
    int arr = 0;
    if(numsSize == 1)
        return true;
//问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点
    for(int i = 0; i <= arr; i++){
        if(i + nums[i] > arr)
            arr = i + nums[i];
        if(arr >= (numsSize - 1))
            return true;   
    }
    return false;
}

