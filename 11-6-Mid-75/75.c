void exch(int *nums,int index, int target){
    while(index != target){
        int j = index + 1;
        if(target == 0)
            j = index - 1;
        int mid = nums[j];
        nums[j] = nums[index];
        nums[index] = mid;
        index = j;
    }

    
}
void sortColors(int* nums, int numsSize) {
    //遍历一遍nums 遇到0，一直交换到头，遇到一直交换到尾
    int i = 0;
    while(i < numsSize){
        if(nums[i] == 0)
            exch(nums, i, 0);
        i++;
    }
    i--;
    while(i >= 0){
     if(nums[i] == 2)
        exch(nums, i, numsSize - 1);
     i--;
    }
}
