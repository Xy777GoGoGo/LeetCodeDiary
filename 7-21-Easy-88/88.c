#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //归并排序
    int i=0, j=0;
    int a[nums1Size];
    for (int k = 0; k < nums1Size; k++){
        if (i >= m){
            a[k] = nums2[j];
            j++;
        }
        else if (j >= n){
            a[k] =nums1[i];
            i++;
        }
        else if (nums1[i] > nums2[j]){
            a[k] = nums2[j];
            j++;
        }
        else {
            a[k] = nums1[i];
            i++;
        }
    }
    for(int l=0; l < nums1Size;l++){
        nums1[l] = a[l];
    }
}
/* 另一种写法
 *	void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int writePos = m + n - 1; // 合并后数组的最后一个位置
    m--;
	  n--;//直接定位到两个数组的最后一位

    while (m >= 0 && n >= 0) {
        if (nums1[m] > nums2[n]) {//比较大小，大的放后面
            nums1[writePos--] = nums1[m--];
        }
        else {
            nums1[writePos--] = nums2[n--];//小的放前面
        }
    }

    // 如果nums2还有剩余元素，直接拷贝到nums1的前面
    while (n >= 0) {
        nums1[writePos--] = nums2[n--];
    }
}
在我看来非常优美的代码，还不需要额外的空间
