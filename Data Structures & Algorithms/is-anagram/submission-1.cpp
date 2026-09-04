class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;

        int n = s.size();
        int m = t.size();

        for (int i = 0; i < n; i++) {
            mp_s[s[i]]++;
        }

        for (int i = 0; i < m; i++) {
            mp_t[t[i]]++;
        }

        if (mp_s.size() != mp_t.size()) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if(mp_s[s[i]] != mp_t[s[i]]) {
                return false;
            }
        }

        return true;

    }
};
