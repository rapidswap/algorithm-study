#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size()-1; i++)
    {
        int back = i + 1;
        if (phone_book[back].find(phone_book[i]) == 0) {
            answer = false;
        }
            
    }
    return answer;
}
