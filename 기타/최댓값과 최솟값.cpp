#include <string>
#include <vector>
#include <algorithm>
#include <sstream> // for stringstream
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    stringstream ss(s);
    string temp;

    
    while (ss >> temp) {
        numbers.push_back(stoi(temp));
    }

    int max_num = *max_element(numbers.begin(), numbers.end());
    int min_num = *min_element(numbers.begin(), numbers.end());
    answer = to_string(min_num) + " " + to_string(max_num); 

    return answer;
}
