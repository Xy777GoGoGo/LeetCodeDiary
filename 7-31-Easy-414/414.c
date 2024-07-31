//排序就不写了
//下面是一次遍历
/*int thirdMax(int* nums, int numsSize){
    long long  max =LONG_MIN, se = LONG_MIN, th = LONG_MIN ,mid;
    for(int i = 0; i < numsSize; i++){
        if (nums[i] > max){
            mid = max;
            max = nums[i];
            th = se;
            se = mid;
        }
        else if (nums[i] < max && nums[i] > se){
            th = se ;
            se = nums[i];
        }
        else if (nums[i] < se && nums[i] > th)
            th = nums[i];
    }
    if ( th == LONG_MIN )
        return max;
    else 
        return th;    
}*/

//下面是维持有序集合
//我们可以遍历数组，同时用一个有序集合来维护数组中前三大的数。具体做法是每遍历一个数，就将其插入有序集合，若有序集合的大小超过 3，就删除集合中的最小元素。这样可以保证有序集合的大小至多为 3，且遍历结束后，若有序集合的大小为 3，其最小值就是数组中第三大的数；若有序集合的大小不足 3，那么就返回有序集合中的最大值。
//感觉还是依次遍历的思想，我就不实现了
