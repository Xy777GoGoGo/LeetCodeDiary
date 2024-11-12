/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//建立hash表，以及根据hash来建立堆
struct Node{
    int times;
    int value;
    struct Node *next;
};
typedef struct HeapNode{
    int times;
    int value;
}heapnode;
bool isexist(struct Node *hash, int node, int numsSize){
    struct Node *mid = &hash[abs(node) % numsSize];
    while(mid != NULL){
        if(mid->value == node)
            return true;
        mid = mid->next;
    }
    return false;
}
void CreatHash(struct Node *hash, int node, int numsSize){
    //先判断存不存在
    struct Node *mid = &hash[abs(node) % numsSize];
    if(isexist(hash, node, numsSize)){
        while(mid != NULL){
            if(mid->value == node){
                mid->times++;
                break;
            }
            mid = mid->next;
        }
    }
    else{
        struct Node *newnode = malloc(sizeof(struct Node));
        newnode->value = node;
        newnode->times = 1;
        newnode->next = NULL;
        while(mid->next != NULL)
            mid = mid->next;
        mid->next = newnode;
    }
}

int top;
int returnS;
void sink(heapnode *heap){
    int k = 1;
    while(2 * k + 1 <= top){
        int j = 2 * k;
        if(j + 1 < top && heap[j].times < heap[j + 1].times)//说明有左右结点
            j++;
        if(heap[k].times >= heap[j].times)//说明头比叶子大，不用交换
            break;
        heapnode mid = heap[j];
        heap[j] = heap[k];
        heap[k] = mid;
        k = j;
    }
}
void deletemax(heapnode *heap, int *ans){
    //先交换首结点和尾节点，再将顶点一直下沉
    //将最后一个结点置为null，top - 1
    ans[returnS++] = heap[1].value;
    heap[1] = heap[top - 1];
    //heap[top - 1] = NULL;
    top--;
    sink(heap);
    //首结点下沉
}
void swim(heapnode *heap, int number){
    //该节点大于父亲结点
    while(number > 1 && heap[number].times > heap[number / 2].times){
        heapnode mid = heap[number];
        heap[number] = heap[number / 2];
        heap[number / 2] = mid;
        number = number / 2;
    }
}
void insertheap(heapnode *heap, struct Node* hashnode){
    heapnode* mid = malloc(sizeof(heapnode));
    mid->value = hashnode->value;
    mid->times = hashnode->times;
    heap[top++] = *mid;
    //和父亲结点比较
    if(top - 1 > 1 && mid->times > heap[(top - 1) / 2].times)
        swim(heap, top - 1);
    //此时大于父亲结点 ，需要向上
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 1){
        *returnSize = 1;
        return nums; 
    }
    //先建立hash表
    struct Node *hash = malloc(sizeof(struct Node) * numsSize);
    for(int i = 0; i < numsSize; i++)
        hash[i].next = NULL;
    for(int i = 0; i < numsSize; i++)
        CreatHash(hash, nums[i], numsSize);


    //建立大堆根
    heapnode *heap = malloc(sizeof(heapnode) * (numsSize + 1));
    top = 1;
    for(int i = 0; i < numsSize; i++){
        struct Node *mid = &hash[i];
        while(mid->next != NULL){
            insertheap(heap, mid->next);
            mid = mid->next;
        }
    }
    int* ans = malloc(sizeof(int) * numsSize);
    returnS = 0;
    for(int i = 0; i < k; i++)
        deletemax(heap, ans);
    (*returnSize) = k;
    return ans;
}
