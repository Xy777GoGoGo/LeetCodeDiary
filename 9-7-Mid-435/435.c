int cmp(const void *a,const void *b)
{   
    return ((*((int**)a))[0] > (*((int**)b))[0]);
} 

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    int ans = 0;
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] < intervals[i - 1][1]){
            ans++;
            if(intervals[i - 1][1] < intervals[i][1])
                intervals[i][1] = intervals[i - 1][1];
        }
    }
    return ans;
}
