// 432. All O`one Data Structure (HARD)
// https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29

#include <unordered_map>
#include <string>
#include <limits.h>

class AllOne {
public:
    unordered_map<string, int> freq;

    AllOne() {}

    // Increment the frequency of a key
    void inc(string key) {
        freq[key]++;
    }

    // Decrement the frequency of a key
    void dec(string key) {
        if (freq.find(key) != freq.end()) {
            freq[key]--;
            // Remove the key if its frequency is zero
            if (freq[key] == 0) {
                freq.erase(key);
            }
        }
    }

    // Get the key with the maximum frequency
    string getMaxKey() {
        int maxFreq = 0;
        string maxKey = "";

        for (const auto& val : freq) {
            if (val.second > maxFreq) {
                maxFreq = val.second;
                maxKey = val.first;
            }
        }

        return maxKey;  // Return an empty string if no key exists
    }

    // Get the key with the minimum frequency
    string getMinKey() {
        int minFreq = INT_MAX;
        string minKey = "";

        for (const auto& val : freq) {
            if (val.second > 0 && val.second < minFreq) {
                minFreq = val.second;
                minKey = val.first;
            }
        }

        return minKey;  // Return an empty string if no key exists
    }
};
