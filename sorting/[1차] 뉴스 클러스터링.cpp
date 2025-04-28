#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    map<string, int> m1, m2;
    
    for (char& c : str1) c = toupper(c);
    for (char& c : str2) c = toupper(c);

    for (int i = 0; i < str1.size() - 1; ++i) {
        if (isalpha(str1[i]) && isalpha(str1[i+1])) {
            string temp = str1.substr(i, 2);
            m1[temp]++;
        }
    }

    for (int i = 0; i < str2.size() - 1; ++i) {
        if (isalpha(str2[i]) && isalpha(str2[i+1])) {
            string temp = str2.substr(i, 2);
            m2[temp]++;
        }
    }

    int inter = 0, uni = 0;
    
    for (auto p : m1) {
        if (m2.count(p.first)) {
            inter += min(p.second, m2[p.first]);
            uni += max(p.second, m2[p.first]);
        }
        else {
            uni += p.second;
        }
    }
    for (auto p : m2) {
        if (!m1.count(p.first)) {
            uni += p.second;
        }
    }
    
    if (uni == 0) return 65536;
    
    return (int)((double)inter / uni * 65536);
}
