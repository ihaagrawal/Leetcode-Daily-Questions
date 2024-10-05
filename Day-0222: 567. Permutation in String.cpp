// 567. Permutation in String (MEDIUM)
// https://leetcode.com/problems/permutation-in-string/description/?envType=daily-question&envId=2024-10-05


class Solution {
public:

    vector<int> count(string& s, int l, int r){
        vector<int> freq(26, 0);
        for(int i=l;i<=r;i++) freq[s[i] - 'a']++;
        return freq;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;

        vector<int> freq1 = count(s1, 0, n-1);
        vector<int> freq2 = count(s2, 0, n-1);
        if(freq1 == freq2) return true;

        for(int i=1, j=n;j<m;i++, j++){
            freq2[s2[i-1] - 'a']--;
            freq2[s2[j] - 'a']++;
            if(freq2 == freq1) return true;
        }

        return false;
    }
};
