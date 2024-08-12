//被overflow搞疯了，不知道问题出在哪，贴个别人的代码
//注意剪枝
 int compareFunc(void* a, void* b)
{
    if (*(int*)a >= *(int*)b)
    {
        return 1;
    }
    return -1;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{

    //4数之和转为三数之和的问题。
    //使用双指针
    *returnSize = 0;
    if (numsSize < 4)
        return NULL;

    int **returnNums     = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes   = (int*)malloc(sizeof(int) * numsSize * numsSize);
    qsort(nums, numsSize, sizeof(int), compareFunc);
    int a , b, c, d;
    long long sum;
    int indexLeft = 0;
    int indexRight = 0;
    for (a = 0; a < numsSize - 3; a++)
    {
        if ((nums[a] > 0) && (nums[a] > target))
        {
            //剪枝 因为存在负数 会越加 越小，所以这里需要判断nums[a] > 0
            //因为是快排的结果，所以如果出现大target的
            //后面的值都是大于target的
            break;
        }
        if (a > 0 && nums[a] == nums[a - 1])
        {
            continue; //去重
        }
        for (b = a + 1; b < numsSize; b++)
        {
            if (( b > a + 1) && (nums[b] == nums[b - 1]) )
            {
                continue; //去重
            }

            if (((nums[a] + nums[b]) > target)  && (nums[b] > 0) )
            {
                //因为是快排的结果，所以如果出现a + b 大于零的
                //后面的b值都是大于target的
                //剪枝
                break;
            }

            //双指针 移动
            indexLeft   =  b + 1;
            indexRight  = numsSize - 1;
            while (indexLeft < indexRight)
            {
                sum = (long)nums[a] + nums[b] + nums[indexLeft] + nums[indexRight];
                if (sum == target)
                {
                    //找到目标
                    (*returnColumnSizes)[*returnSize] = 4;
                    returnNums[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    returnNums[*returnSize][0] = nums[a];
                    returnNums[*returnSize][1] = nums[b];
                    returnNums[*returnSize][2] = nums[indexLeft];
                    returnNums[*returnSize][3] = nums[indexRight];
                    *returnSize = *returnSize + 1;
                    //跳过相同的值
                    while ((indexLeft < indexRight) && nums[indexLeft] == nums[indexLeft + 1])
                    {
                        indexLeft++;
                    }

                    while ((indexLeft < indexRight) && nums[indexRight] == nums[indexRight - 1])
                    {
                        indexRight--;
                    }

                    indexLeft++;
                    indexRight--;
                }
                else if (sum < target)
                {
                    indexLeft++;
                }
                else if (sum > target)
                {
                    indexRight--;
                }
            }

        }
    }
    return returnNums;
}
