#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> LRU;

    for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        auto it = find(LRU.begin(), LRU.end(), city);
        
        if (it != LRU.end()) {
            answer++;
            LRU.erase(it);
            LRU.push_back(city);
        }
        else {
            answer += 5;
            LRU.push_back(city);

            if (LRU.size() > cacheSize) {
                LRU.erase(LRU.begin());
            }
        }
    }

    return answer;
}
