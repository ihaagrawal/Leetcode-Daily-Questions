// 525. Contiguous Array (MEDIUM)
// https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

int max(int a, int b) {
    return a > b ? a : b;
}

int findMaxLength(int* nums, int numsSize) {
    int i, j, length=0, count=0;
    int* sum=(int *)malloc(sizeof(int)*(2*numsSize+1));
    
    for(i=0;i<=2*numsSize;i++) {
        sum[i]=-2; 
    }
    sum[numsSize] = -1;
    
    for(i=0;i<numsSize;i++)
        {
            if(nums[i]==1)
                count++;
            else
                count--;
            
            if(sum[count+numsSize]!=-2)
                length=max(length, i-sum[count+numsSize]);
            else
                sum[count+numsSize]=i;
        }
    return length;
}
