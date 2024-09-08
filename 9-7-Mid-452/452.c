int cmp(const void *a,const void *b)
{
    return ((*((int**)a))[0] > (*((int**)b))[0]);
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    //先排序把
    qsort(points, pointsSize, sizeof(int *), cmp);
    int ans = 1;
    int lo, hi;
    for(int i = 0; i < pointsSize; i++){
        if(i < 1){
            hi = points[i][1];
            continue;
        }
        if(points[i][0] > hi){//说明两区间没交集
            ans++;
            hi = points[i][1];
        }
        else if(points[i][0] < hi){
            if(points[i][1] < hi)
                hi = points[i][1];
        }
    }
    return ans;
}


int cmp(const void *a,const void *b)
{
    return ((*((int**)a))[0] > (*((int**)b))[0]);
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    //将points数组作升序排序
    qsort(points, pointsSize, sizeof(points[0]),cmp);

    int arrowNum = 1;
    int i = 1;
    for(i = 1; i < pointsSize; i++) {
        //若前一个气球与当前气球不重叠，证明需要增加箭的数量
        if(points[i][0] > points[i-1][1])
            arrowNum++;
        else
            //若前一个气球与当前气球重叠，判断并更新最小的x_end
            points[i][1] = points[i][1] > points[i-1][1] ? points[i-1][1] : points[i][1];
    }
    return arrowNum;
}
