// 670. Maximum Swap (MEDIUM)
// https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17


class Solution {
public:

    vector<int> digits(int num) {
        vector<int> arr;
        while (num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }

    int maximumSwap(int num) {
        if (num < 10) return num;
        
        vector<int> arr = digits(num);
        int n = arr.size();
        
        vector<int> rightMaxIndex(n);
        rightMaxIndex[n - 1] = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[rightMaxIndex[i + 1]]) rightMaxIndex[i] = i;
            else rightMaxIndex[i] = rightMaxIndex[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] < arr[rightMaxIndex[i]]) {
                swap(arr[i], arr[rightMaxIndex[i]]);
                break;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = result * 10 + arr[i];
        }

        return result;
    }
};
