// 564. Find the Closest Palindrome (HARD)
// https://leetcode.com/problems/find-the-closest-palindrome/description/?envType=daily-question&envId=2024-08-24


class Solution {
public:
    string nearestPalindromic(string inputNumber) {
        int numLength = inputNumber.size();
        set<string> possiblePalindromes;

        if (inputNumber == "1") return "0";

        string prefixPart = inputNumber.substr(0, (numLength + 1) / 2);
        long long prefixValue = stoll(prefixPart);

        for (long long offset : {-1, 0, 1}) {
            string modifiedPrefix = to_string(prefixValue + offset);
            string palindromeCandidate;
            if (numLength % 2 == 0) {
                palindromeCandidate = modifiedPrefix + string(modifiedPrefix.rbegin(), modifiedPrefix.rend());
            } else {
                palindromeCandidate = modifiedPrefix + string(modifiedPrefix.rbegin() + 1, modifiedPrefix.rend());
            }
            possiblePalindromes.insert(palindromeCandidate);
        }

        possiblePalindromes.insert(to_string(static_cast<long long>(pow(10, numLength - 1)) - 1));
        possiblePalindromes.insert(to_string(static_cast<long long>(pow(10, numLength)) + 1));

        possiblePalindromes.erase(inputNumber);

        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long originalNumber = stoll(inputNumber);
        for (const string& palindrome : possiblePalindromes) {
            long long palindromeValue = stoll(palindrome);
            long long difference = abs(palindromeValue - originalNumber);
            if (difference < minDifference || (difference == minDifference && palindromeValue < stoll(closestPalindrome))) {
                minDifference = difference;
                closestPalindrome = palindrome;
            }
        }

        return closestPalindrome;
    }
};
