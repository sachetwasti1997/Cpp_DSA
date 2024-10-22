#include<bits/stdc++.h>

class Solution {
private:
    bool evaluate(char lhs, char rhs, char exp) {
        if (exp == '|') {
            return (lhs == '0'? false: (lhs == 'f' ? false: true))  |  (rhs == 'f'? false: true);
        }else {
            return (lhs == '0'? true: (lhs == 'f'? false: true))  &  (rhs == 'f'? false: true);
        }
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> charStk, expStk;
        int i = 0;
        unordered_set<char> expr{'!', '|', '&'};
        while (i < expression.size()) {
            if (expression[i] == ',') {
                i++;
                continue;
            }
            if (expr.find(expression[i]) != expr.end()) {
                expStk.push(expression[i]);
            }else {
                if (expression[i] == ')') {
                    char exp = expStk.top();
                    char res = '0';
                    if (exp == '!') {
                        res = charStk.top() == 'f' ? 't': 'f';
                        charStk.pop();
                        charStk.pop();
                        charStk.push(res);
                        expStk.pop();
                        i++;
                        continue;
                    }
                    while (charStk.top() != '(') {
                        char tp = charStk.top();
                        bool eval = evaluate(res, tp, exp);
                        res = !eval ? 'f' : 't';
                        charStk.pop();                    
                    }
                    charStk.pop();
                    expStk.pop();
                    charStk.push(res);
                }else {
                    charStk.push(expression[i]);
                }
            }
            i++;
        }
        return charStk.top() == 'f' ? false: true;
    }
};

int main() {
    Solution s;
    cout<<s.parseBoolExpr("|(&(t,f,t),!(t))")<<endl;
}