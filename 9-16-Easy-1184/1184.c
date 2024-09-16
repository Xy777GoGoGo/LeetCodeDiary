int min(int a, int b){
    if(a < b)
        return a;
    return b;
}
int max(int a, int b){
    if(a < b)
        return b;
    return a;
}
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int left, right, sum = 0;
    int ans = 0;
    for(int i = 0; i < distanceSize; i++)
        sum = sum + distance[i];
    left = min(start, destination);
    right = max(start, destination);
    for(int i = left; i < right; i++)
        ans = ans + distance[i]; 
    if(ans * 2 < sum)
        return ans;
    else
        return sum - ans;
}
