/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int max(int a,int b){
    return (a>b) ? a : b;
}
int cmp(const void* a,const void* b){
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p1[0]-p2[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return 0;
    }

    qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);

    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));
   
    int currentrow=0;
    result[currentrow] = malloc(2 * sizeof(int));
    result[currentrow][0]=intervals[0][0];
    result[currentrow][1]=intervals[0][1];
    (*returnColumnSizes)[currentrow] = 2;

    for(int i=1;i<intervalsSize;i++){

        if(intervals[i][0]<=result[currentrow][1]){
            // overlap
            result[currentrow][1]=max(intervals[i][1],result[currentrow][1]);
        }
        else{
            // no overlap, add both intervls as it is
            currentrow++;
            result[currentrow] = malloc(2*sizeof(int));
            result[currentrow][0]=intervals[i][0];
            result[currentrow][1]=intervals[i][1];
            (*returnColumnSizes)[currentrow] = 2;
        }
    }
    *returnSize = currentrow+1;
    return result;
}