int* path;
int pathTop;
int** ans;
int ansTop;
int* length;
//将当前path中的内容复制到ans中
void copy() {
    int* tempPath = (int*)malloc(sizeof(int) * pathTop);
    memcpy(tempPath, path, pathTop * sizeof(int));
    length[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

//查找uset中是否存在值为key的元素
int find(int* uset, int usetSize, int key) {
    int i;
    for(i = 0; i < usetSize; i++) {
        if(uset[i] == key)
            return 1;
    }
    return 0;
}

void backTracking(int* nums, int numsSize, int startIndex) {
    //当path中元素大于1个时，将path拷贝到ans中
    if(pathTop > 1) {
        copy();
    }
    int* uset = (int*)malloc(sizeof(int) * numsSize);
    int usetTop = 0;
    int i;
    for(i = startIndex; i < numsSize; i++) {
        //若当前元素小于path中最后一位元素 || 在树的同一层找到了相同的元素，则continue
        if((pathTop > 0 && nums[i] < path[pathTop - 1]) || find(uset, usetTop, nums[i]))
            continue;
        //将当前元素放入uset
        uset[usetTop++] = nums[i];
        //将当前元素放入path
        path[pathTop++] = nums[i];
        backTracking(nums, numsSize, i + 1);
        //回溯
        pathTop--;
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //辅助数组初始化
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 33000);
    length = (int*)malloc(sizeof(int*) * 33000);
    pathTop = ansTop = 0;

    backTracking(nums, numsSize, 0);

    //设置数组中返回元素个数，以及每个一维数组的长度
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int i;
    for(i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}
