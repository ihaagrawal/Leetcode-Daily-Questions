// Split the Array (EASY)
// https://www.geeksforgeeks.org/problems/split-the-array0238/1


class Solution {
  public:
    const long long int c = 1e9+7;
    int countgroup(vector<int>& arr) {
       int xors = 0;
       int n = arr.size();
       for(auto &val:arr){
           xors^=val;
       }
       if(xors != 0){
           return 0;
       }
       else{
           return (((1ll<<n) - 2)/2)%c;
       }
    }
};
