#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    for(string str : goal)
    {
        //bool found=false;
        if(str==cards1[0])
        {
            cards1.erase(cards1.begin()+0);
            //found=true;
            continue;
        }else if(str==cards2[0])
        {
            cards2.erase(cards2.begin()+0);
            //found=true;
            continue;
        }
        else
        {
            answer+="No";
            return answer;
        }
    }
    answer+="Yes";
    return answer;
}
