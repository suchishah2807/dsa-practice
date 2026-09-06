int cmp(const void*a,const void*b){
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    if (ia[1] < ib[1]) {
        return -1; // ia comes before ib
    } else if (ia[1] > ib[1]) {
        return 1;  // ia comes after ib
    }
    return 0;      // they are equal
    // ascending order by end points
    // because to maximise number of ballons sht by 1 arrow we prefer to hit at edge of previous balloon. thats why sort by end poits it helps comapring that does edge point of previous balloon in range of this balloon?
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize==0){
        return 0;
    }
    int cnt = 1;
    qsort(points,pointsSize,sizeof(points[0]),cmp);
    long long last_edge = points[0][1];
    for(int i=1;i<pointsSize;i++){
        if(points[i][0]<=last_edge){
            continue;
        }
        else{
            cnt++;
            last_edge=points[i][1];
        }
    }
    return cnt;
}