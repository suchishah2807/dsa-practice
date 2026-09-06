int cmp(const void*a,const void*b){
    char ab[24],ba[24];
    // concatenates a and b and places them in array, each element has 1 char
    sprintf(ab,"%d%d",*(int*)a,*(int*)b);
    sprintf(ba,"%d%d",*(int*)b,*(int*)a);
    // is ba>ab returns positive, ba<ab return negative
    // ba>ab -> b needs to placed before a, positve output does that
    // ab>ba -> a needs to placed before b, negative output does that
    return strcmp(ba,ab);
}
char* largestNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    if(nums[0]==0) return "0";

    char* result = malloc(numsSize*12);
    result[0]='\0';
    for(int i=0;i<numsSize;i++){
        char buf[24];
        sprintf(buf,"%d",nums[i]);
        strcat(result,buf);
    }
    return result;
}