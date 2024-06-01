// 2485. Find the Pivot Integer (EASY)
// https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13

int pivotInteger(int n){
    int i, left=0, right=0;
    for(i=1;i<=n;i++)
        {
            left=i*(i+1)/2;
            right=n*(n+1)/2 - left+i;
            if(left==right)
                return i;
        }
    return -1;
}
