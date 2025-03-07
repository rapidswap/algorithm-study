#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), 
                   [](auto c) { return tolower(c); });
    
    new_id.erase(remove_if(new_id.begin(), new_id.end(), [](char ch) {
        return !(islower(ch) || std::isdigit(ch) || ch == '-' || ch == '_' || ch == '.');
    }), new_id.end());
    
    new_id.erase(unique(new_id.begin(), new_id.end(), [](char a, char b) {
        return a == '.' && b == '.';
    }), new_id.end());
    
    while (!new_id.empty() && new_id.front() == '.') {
        new_id.erase(0, 1);
    }
    while (!new_id.empty() && new_id.back() == '.') {
        new_id.pop_back();
    }
    
    if(new_id.empty()) new_id+="a";
    
    if (new_id.size()>15) new_id = new_id.substr(0, 15);
    if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.size()-1);
    while(new_id.size()<=2){
        new_id+=new_id.back();
    }
    
    answer=new_id;
    return answer;
}
