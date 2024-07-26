#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void parseFormula(const string& formula, map<string, int>& atomCounts) {
    stack<map<string, int>> stk;
    stk.push({});
    int n = formula.size();
    
    for (int i = 0; i < n;) {
        if (isupper(formula[i])) {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i])) {
                atom += formula[i++];
            }
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + (formula[i++] - '0');
            }
            if (count == 0) count = 1;
            stk.top()[atom] += count;
        } else if (formula[i] == '(') {
            stk.push({});
            i++;
        } else if (formula[i] == ')') {
            map<string, int> top = stk.top();
            stk.pop();
            i++;
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + (formula[i++] - '0');
            }
            if (count == 0) count = 1;
            for (auto& [atom, cnt] : top) {
                stk.top()[atom] += cnt * count;
            }
        }
    }
    
    for (auto& [atom, cnt] : stk.top()) {
        atomCounts[atom] += cnt;
    }
}

string countOfAtoms(const string& formula) {
    map<string, int> atomCounts;
    parseFormula(formula, atomCounts);
    string result;
    for (auto& [atom, count] : atomCounts) {
        result += atom;
        if (count > 1) {
            result += to_string(count);
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string formula;
        cin >> formula;
        cout << countOfAtoms(formula) << endl;
    }
    return 0;
}