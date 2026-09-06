int max(int a,int b){
    return (a>b) ? a : b;
}
int cmp(const void*a,const void*b){
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    return pa[1]-pb[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if(intervalsSize==0){
        return 0;
    }
    qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);

    int** result = malloc(intervalsSize*sizeof(int*));
    int currentrow=0;
    result[currentrow] = malloc(2*sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    int ans = 0;
    for(int i=1;i<intervalsSize;i++){
        if(result[currentrow][1]<=intervals[i][0]){
            currentrow++;
            result[currentrow] = malloc(2*sizeof(int));
            result[currentrow][0]=intervals[i][0];
            result[currentrow][1]=intervals[i][1];
        }
        else{
            ans++;
        }
    }
    return ans;
}