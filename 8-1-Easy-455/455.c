int cmp(int *a, int *b){
    return *a - *b; 
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
 //  双指针，先排序，先大的数值是每个饼干最好都满足一个，先分大的饼干
    int gsign = gSize - 1, ssign = sSize - 1, k=0;
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    while (gsign >= 0 && ssign >= 0){
        if (s[ssign] >= g[gsign]){//代表满足
            k++;
            ssign--;
            gsign--;
        }
        else //代表人的胃口太大,永远无法满足
            gsign--;
    }
    return k;
}
