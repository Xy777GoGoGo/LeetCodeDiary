int maxSubArray(int* nums, int numsSize) {
    //当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小
    int ans = INT_MIN;
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum = sum + nums[i];
        if(ans < sum)
            ans = sum;
        if(sum < 0)
            sum = 0;
    }
    return ans;
}


struct Status {
    int lSum, rSum, mSum, iSum;
};

struct Status pushUp(struct Status l, struct Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = fmax(l.lSum, l.iSum + r.lSum);
    int rSum = fmax(r.rSum, r.iSum + l.rSum);
    int mSum = fmax(fmax(l.mSum, r.mSum), l.rSum + r.lSum);
    return (struct Status){lSum, rSum, mSum, iSum};
};

struct Status get(int* a, int l, int r) {
    if (l == r) {
        return (struct Status){a[l], a[l], a[l], a[l]};
    }
    int m = (l + r) >> 1;
    struct Status lSub = get(a, l, m);
    struct Status rSub = get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int maxSubArray(int* nums, int numsSize) {
    //我们可以维护四个量：

//lSum 表示 [l,r] 内以 l 为左端点的最大子段和
//rSum 表示 [l,r] 内以 r 为右端点的最大子段和
//mSum 表示 [l,r] 内的最大子段和
//iSum 表示 [l,r] 的区间和
    return get(nums, 0, numsSize - 1).mSum;

}
