// 349. Intersection of Two Arrays (EASY)
// https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool check(int a[], int n, int key)
{
    int i;
    for(i=0;i<n;i++)
        {
            if(a[i]==key)
                return true;
        }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int len, i, j, index, k=0;
    bool swapped;
    if(nums1Size>=nums2Size)
        len=nums2Size;
    else
        len=nums1Size;
    int* a=(int *)malloc(sizeof(int)*len);
    for(i=0;i<nums1Size;i++)
        {index=0;
        swapped=false;
            for(j=0;j<nums2Size;j++)
                {
                    if(nums1[i]==nums2[j])
                        {
                            index=i;
                            swapped=true;
                        }
                }
            if(swapped && !check(a, len, nums1[index]))
                {
                    a[k]=nums1[index];
                    k++;
                }
        }
    *returnSize=k;
    return a;
}
