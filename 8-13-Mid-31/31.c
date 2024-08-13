int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void nextPermutation(int* nums, int numsSize) {
    //具体地，我们这样描述该算法，对于长度为 n 的排列 a：
//首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i]<a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
//如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i]<a[j]。这样「较大数」即为 a[j]。
//交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。
    int a = -1, b, mid;
    for(int i = numsSize - 1; i > 0; i--){
        if (nums[i] > nums[i - 1]){
            a = i - 1;//a = 0
            break;
        }
    }
    if(a == -1){
        qsort(nums, numsSize, sizeof(int), cmpfunc);
        return;
    }
    else{
        for(int i = numsSize - 1; i >= 0; i--){
            if (nums[i] > nums[a]){
                b = i;
                break;
            }
        }
        mid = nums[a];
        nums[a] = nums[b];
        nums[b] = mid; 
        //再将a之后的数从小往后排
        qsort(nums + a + 1, numsSize - a - 1, sizeof(int),cmpfunc );
        return;
    }
}
