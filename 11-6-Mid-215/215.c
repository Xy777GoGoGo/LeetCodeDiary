int top;
void sink(int *heap){
    int k = 1;
    while(2 * k + 1 <= top){
        int j = 2 * k;
        if(j + 1 < top && heap[j] < heap[j + 1])//说明有左右结点
            j++;
        if(heap[k] >= heap[j])//说明头比叶子大，不用交换
            break;
        int mid = heap[j];
        heap[j] = heap[k];
        heap[k] = mid;
        k = j;
    }
}
void deletemax(int *heap){
    //先交换首结点和尾节点，再将顶点一直下沉
    //将最后一个结点置为null，top - 1
    heap[1] = heap[top - 1];
    heap[top - 1] = NULL;
    top--;
    sink(heap);
    //首结点下沉
}
void swim(int *heap, int number){
    //该节点大于父亲结点
    while(number > 1 && heap[number] > heap[number / 2]){
        int mid = heap[number];
        heap[number] = heap[number / 2];
        heap[number / 2] = mid;
        number = number / 2;
    }
}
void insertheap(int *heap, int *nums, int number){
    heap[top++] = nums[number];
    //和父亲结点比较
    if(top - 1 > 1 && nums[number] > heap[(top - 1) / 2])
        swim(heap, top - 1);
    //此时大于父亲结点 ，需要向上
}
int findKthLargest(int* nums, int numsSize, int k) {
    //优先队列
    //很快找出最小元，则最小元应该在根上，任意节点都小于它的后裔，这就是小顶堆（Min-Heap）；
    //如果是查找最大元，则最大元应该在根上，任意节点都要大于它的后裔，这就是大顶堆(Max-heap)；
    //利用数组存储大堆根
    int *heap = malloc(sizeof(int) * (numsSize + 1));
    heap[0] = -1;
    //从下标1开始插入
    top = 1;
    for(int i = 0; i < numsSize; i++)
        insertheap(heap, nums, i);
    for(int i = 1; i < k; i++)
        deletemax(heap);
    return heap[1];
    
}
