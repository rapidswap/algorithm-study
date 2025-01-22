#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<int, int> yNum;
    vector<int> ans;
    
    for (char c : Y) {
        int a = c - '0';
        yNum[a]++;
    }
    
    for (char c : X) {
        int a = c - '0';
        if (yNum[a] > 0) {
            yNum[a]--;
            ans.push_back(a);
        }
    }
    
    sort(ans.begin(), ans.end(), greater<int>());
    
    if (ans.empty()) {
        return "-1";
    }
    
    for (int n : ans) {
        answer += to_string(n);
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}
