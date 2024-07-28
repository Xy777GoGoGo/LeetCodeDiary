void moveZeroes(int* nums, int numsSize) {
    //从后开始找到0 就一直交换到最后一位非零的数
    int mid;
    for(int i = numsSize - 1 ; i >= 0; i--){
        if (nums[i] == 0){
            int j = i;
            while( j < numsSize - 1 ){
                //i + 1和i交换
                mid = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = mid;
                j++;
            }
        }
    }
}
//双指针
//void moveZeroes(int* nums, int numsSize) {
  //  使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

//右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
//如果数组没有0，那么快慢指针始终指向同一个位置，每个位置自己和自己交换；如果数组有0，快指针先走一步，此时慢指针对应的就是0，所以要交换
    int left = 0, right = 0, mid;

    while (right < numsSize){
        if( nums[right]){
  //          mid = nums[left];
    //        nums[left++] = nums[right];
      //      nums[right] = mid;
            mid = nums[right];
            nums[right] = nums[left];
            nums[left++] = mid;
        }
            right++;
    }

}
