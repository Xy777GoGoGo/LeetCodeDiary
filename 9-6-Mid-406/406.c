/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *p1, const void *p2) {
    int *pp1 = *(int**)p1;
    int *pp2 = *(int**)p2;
    // 若身高相同，则按照k从小到大排列
    // 若身高不同，按身高从大到小排列
    return pp1[0] == pp2[0] ? pp1[1] - pp2[1] : pp2[0] - pp1[0];
}
void moveBack(int **people, int peopleSize, int start, int end) {
    int i;
    for(i = end; i > start; i--) {
        people[i] = people[i-1];
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int i;
    // 将people按身高从大到小排列（若身高相同，按k从小到大排列）
    qsort(people, peopleSize, sizeof(int*), cmp);

    for(i = 0; i < peopleSize; ++i) {
        // people[i]要插入的位置
        int position = people[i][1];
        int *temp = people[i];
        // 将position到i中间的元素后移一位
        // 注：因为已经排好序，position不会比i大。(举例：排序后people最后一位元素最小，其可能的k最大值为peopleSize-2，小于此时的i)
        moveBack(people, peopleSize, position, i);
        // 将temp放置到position处
        people[position] = temp;

    }
    

    // 设置返回二维数组的大小以及里面每个一维数组的长度
    *returnSize = peopleSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * peopleSize);
    for(i = 0; i < peopleSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return people;
}
