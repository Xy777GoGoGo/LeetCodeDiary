int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int timesum = 0;
    for(int i = 0; i < timeSeriesSize - 1; i++){
        if (timeSeries[i] + duration - 1 < timeSeries[i + 1])
            timesum = timesum + duration;
        else if (timeSeries[i] + duration - 1 >= timeSeries[i + 1])
            timesum = timesum + timeSeries[i + 1] - timeSeries[i];
    }
    return timesum + duration;
}
