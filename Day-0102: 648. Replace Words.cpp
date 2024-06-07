// 648. Replace Words (MEDIUM)
// https://leetcode.com/problems/replace-words/?envType=daily-question&envId=2024-06-07


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size(), m = sentence.size();

        set<string> dict(dictionary.begin(), dictionary.end());

        istringstream iss(sentence);
        string word;
        vector<string> result;
        
        while(iss >> word){
            string prefix;
            for(int i=1;i<=word.size();i++){
                prefix = word.substr(0, i);
                if(dict.find(prefix) != dict.end()) break;
            }
            result.push_back(prefix);
        }

        string output;
        for(const auto& w : result){
            if(!output.empty()) output += " ";
            output += w;
        }

        return output;    
    }
};
