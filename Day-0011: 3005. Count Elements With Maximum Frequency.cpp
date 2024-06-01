// 3005. Count Elements With Maximum Frequency (EASY)
// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

int maxFrequencyElements(int* nums, int numsSize) {
    int count[101]={0};
    int i,j=0;

    for(i=0;i<numsSize;i++)
        count[nums[i]]++;
    
    int max=count[0];
    for(i=0;i<101;i++)
        {
            if(count[i]>max)
                max=count[i];
        }
    for(i=0;i<101;i++)
        {
            if(count[i]==max)
                j+=max;
        }
    return j;
}
