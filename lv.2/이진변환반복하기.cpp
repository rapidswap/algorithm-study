#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int cnt = 0;
    int sumzeros = 0;

    while (s.length() != 1) {
        cnt++;
        int zeros = 0;
        
        for (auto ch : s) {
            if (ch == '0') {
                zeros++;
            }
        }
        
        sumzeros += zeros;
        s = s.substr(0, s.size() - zeros);
        
        int length = s.length();
        s = "";
        while (length > 0) {
            s = to_string(length % 2) + s;
            length /= 2;
        }
    }

    answer[0] = cnt;
    answer[1] = sumzeros;
    
    return answer;
}
