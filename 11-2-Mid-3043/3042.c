typedef struct node{
    int val;
    int size;
    struct node* next;
}Node;
bool findnode1(int i, int index, Node *hashmap){
    Node *mubiao = &hashmap[index];
    while(mubiao->next != NULL){
        mubiao = mubiao->next;
        if(mubiao->val == i)
            return true;
    }
    return false;
}
int findindex(int i){
    return i % 50000;
}
void put(int i, int ssize, int index, Node *hashmap){
    if(findnode1(i, index, hashmap))
        return;
    Node *mid = malloc(sizeof(Node));
    mid->val = i;
    mid->size = ssize;
    mid->next = NULL;
    Node *mubiao = &hashmap[index];
    while(mubiao->next != NULL)
        mubiao = mubiao->next;
    mubiao->next = mid;
}
int selectsize(int ar1){
    int k = 0 ;
    while(ar1 != 0){
        k ++;
        ar1 = ar1 / 10;
    }
    return k;
}
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    //首先两个数组中的元素必会两两比较
    //把所有有可能的前缀放到hashset中
    int ans = 0; 
    Node *hashmap = malloc(sizeof(Node) * 50000);
    for(int i = 0; i < 50000; i++){
        hashmap[i].val = -1;
        hashmap[i].size = 0;
        hashmap[i].next = NULL;
    }
    //下面把arr1中可能的前缀放入了
    for(int i = 0; i < arr1Size; i++){
        int ar1 = arr1[i];
        int size1 = selectsize(ar1);
        while(ar1 != 0){
            //放入hashmap
            put(ar1, size1, findindex(ar1), hashmap);
            ar1 = ar1 / 10;
            size1 --;
        }
    }
    //检查所有arr2中可能的前缀
    for(int i = 0; i < arr2Size; i++){
        int ar2 = arr2[i];
        int size2 = selectsize(ar2);
        if(size2 <= ans)
            continue;
        while(ar2 != 0){
            if(findnode1(ar2, findindex(ar2), hashmap)){
                if(ans < size2)
                    ans = size2;
                break;
            }
            ar2 = ar2 / 10;
            size2--;
        }
    }

    return ans;
}
