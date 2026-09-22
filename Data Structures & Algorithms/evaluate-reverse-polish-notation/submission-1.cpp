class Solution {
public:

    int check(string op, int val1, int val2) {
        if(op == "*") {
            return val1 * val2;
        }
        else if(op == "/") {
            return val1 / val2;
        }
        else if(op == "+") {
            return val1 + val2;
        }
        else {
            return val1 - val2;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string w: tokens) {
            if(w != "*" && w != "/" && w != "+" && w != "-") {
                s.push(stoi(w));
            }
            else {
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();

                int res = check(w, val1, val2);
                s.push(res);
            }
        }

        return s.top();
    }
};
