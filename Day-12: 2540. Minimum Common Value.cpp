// 2540. Minimum Common Value (EASY)
// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i=0,j=0;

    while(i<=nums1Size-1 && j<=nums2Size-1)
        {
            if(nums1[i]==nums2[j])
                return nums1[i];
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
    return -1;
}
