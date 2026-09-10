class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string word: strs) {
            ans += to_string(word.size());
            ans += '#';
            ans += word;
        }

        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;
        string word;

        int i = 0;

        while(i < s.size()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));

            word = s.substr(j + 1, length);

            ans.push_back(word);

            i = j + 1 + length;
        }

        return ans;
    }
};
