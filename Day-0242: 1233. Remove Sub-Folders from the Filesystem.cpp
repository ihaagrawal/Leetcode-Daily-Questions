// 1233. Remove Sub-Folders from the Filesystem (MEDIUM)
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);

        for(int i=1;i<folder.size();i++){
            string last = result.back();
            last.push_back('/');

            if(folder[i].compare(0, last.size(), last) != 0) result.push_back(folder[i]);
        }

        return result;
    }
};
