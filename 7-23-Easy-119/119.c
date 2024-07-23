/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * (rowIndex + 1));
    ans[0] = 1;
    ans[rowIndex] = 1;
    *returnSize = rowIndex + 1;
    for (int i = 1; i <= rowIndex; i++)
        ans[i] = 1LL *ans[i - 1] * (rowIndex - i + 1) / i;//1LL会在运算时把后面的临时数据扩容成long long类型，再在赋值给左边时转回int类型。
    return ans;
    //第 n 行的第 m 个数（从 0 开始编号）可表示为可以被表示为组合数 C(n,m)，记作 C 即为从 n 个不同元素中取 m 个元素的组合数。我们可以用公式来表示它
    //由组合数公式可以得到同一行的相邻组合数的关系
}
