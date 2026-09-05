class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s: strs) {
            int freq[26] = {0};
            for(char c: s) {
                freq[c - 'a']++;
            }
            
            string key = "";
            for(int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& pair: mp) {
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};
