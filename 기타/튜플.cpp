#include <string>
#include <vector>
#include <unordered_set>
#include<map>
#include<algorithm>
using namespace std;
#define pp pair<int,int>

bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
    unordered_set<int> res;
    vector<int> answer;
    string strnum;
    map<int,int> m;
    
    
    for (char c : s) {
        if (isdigit(c)) {
            strnum += c; 
        } else if (c == '}' || c == ',') {
            if (!strnum.empty()) {
                res.insert(stoi(strnum));
                m[stoi(strnum)]++;
                strnum.clear(); 
            }
        }
    }
    
    vector<pair<int,int>> a(m.begin(),m.end());
    sort(a.begin(),a.end(),cmp);
    for(auto n:a)
    {
        answer.push_back(n.first);
    }
    return answer;
}
