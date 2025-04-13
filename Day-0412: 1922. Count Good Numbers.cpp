// 1922. Count Good Numbers (MEDIUM)
// https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13

class Solution {
public:
    long long mod = 1000000007;

    long long power(long long x, long long n){
        if(n==0) return 1;
        long long half = power(x, n/2);
        if(n%2==0) return (half * half)%mod;
        return (half * half * x)%mod;
    }

    int countGoodNumbers(long long n) {
        long long odd = (n+1)/2;
        long long even = n/2;
        long long first = power(5, odd) % mod;
        long long second = power(4, even) % mod;
        return (int)((first*second)%mod);
    }
};



































// class Solution {
// public:

//     long long mod = 1000000007;

//     long long power(long long x, long long n) {
//         if (n == 0) return 1;
//         long long half = power(x, n / 2);
//         if (n % 2 == 0) return (half*half) % mod;
//         return (half*half*x)%mod;
//     }

//     int countGoodNumbers(long long n) {
//         long long odd = (n + 1) / 2;
//         long long even = n / 2;
//         long long first = (power(5, odd)) % mod;
//         long long second = (power(4, even)) % mod;
//         return (int)((first * second) % mod);
//     }

// };
