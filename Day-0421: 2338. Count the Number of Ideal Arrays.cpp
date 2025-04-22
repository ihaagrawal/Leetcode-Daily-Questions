// 2338. Count the Number of Ideal Arrays (HARD)
// https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/?envType=daily-question&envId=2025-04-22

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int MAXVAL = maxValue;
        primeFlags.resize(MAXVAL + 1, true);
        for (int i = 2; i <= MAXVAL; ++i) {
            if (!primeFlags[i]) continue;
            primeNumbers.push_back(i);
            for (int j = 2; j * i <= MAXVAL; ++j) {
                primeFlags[j * i] = false;
            }
        }

        factorDivisors.resize(MAXVAL + 1);
        for (int i = 1; i <= MAXVAL; ++i) {
            if (i == 1) factorDivisors[i].push_back(1);
            else {
                auto [prime, exponent] = findPrimeFactor(i);
                int primePow = pow(prime, exponent);
                factorDivisors[i].insert(factorDivisors[i].end(), factorDivisors[i / prime].begin(), factorDivisors[i / prime].end());
                vector<int> primePowDivisors = factorDivisors[i / primePow];
                for (auto &divisor : primePowDivisors) divisor *= primePow;
                factorDivisors[i].insert(factorDivisors[i].end(), primePowDivisors.begin(), primePowDivisors.end());
            }
        }

        vector<long long> dp = vector<long long>(maxValue, 1);
        dp = dirichletConvolutionPower(dp, n);

        long long result = 0;
        for (int i = 0; i < maxValue; ++i) {
            result = (result + dp[i]) % MOD;
        }
        return static_cast<int>(result);
    }

private:
    const int MOD = 1e9 + 7;
    vector<bool> primeFlags; 
    vector<int> primeNumbers;
    vector<vector<int>> factorDivisors;

    pair<int, int> findPrimeFactor(int x) {
        if (primeFlags[x]) return make_pair(x, 1);
        for (int i = 0; primeNumbers[i] * primeNumbers[i] <= x; ++i) {
            if (x % primeNumbers[i] == 0) {
                int exponent = 0;
                while (x % primeNumbers[i] == 0) {
                    x /= primeNumbers[i];
                    exponent += 1;
                }
                return make_pair(primeNumbers[i], exponent);
            }
        }
        throw "findPrimeFactor is not working as expected";
    }

    int pow(int base, int exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;
        int half = pow(base, exp / 2);
        return (exp % 2 == 0) ? half * half : half * half * base;
    }

    vector<long long> dirichletConvolutionPower(const vector<long long> &f, int n) {
        if (n == 0) return vector<long long>(f.size(), 1);
        if (n == 1) return f;
        vector<long long> temp = dirichletConvolutionPower(f, n / 2);
        return ((n % 2 == 0) ? convolution(temp, temp) : convolution(convolution(temp, temp), f));
    }

    vector<long long> convolution(const vector<long long> &left, const vector<long long> &right) {
        vector<long long> result(left.size(), 0);
        for (int i = 1; i <= left.size(); ++i) {
            for (int d : factorDivisors[i]) {
                result[i - 1] = (result[i - 1] + left[d - 1] * right[i / d - 1]) % MOD;
            }
        }
        return result;
    }
};
