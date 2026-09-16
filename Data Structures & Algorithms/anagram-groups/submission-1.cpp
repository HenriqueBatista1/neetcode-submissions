class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        string key;

        for(string s: strs) {

            int count[26] = {0};
            
            for(char c: s) {
                count[c - 'a']++;
            }

            key = "";
            for(int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }


            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(move(it->second));
        }

        return ans;
    }
};
