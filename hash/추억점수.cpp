#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> grPoint;
    
    int idx=0;
    for(string str: name)
    {
        grPoint[str]=yearning[idx];
        idx++;
    }
    
    for(int i=0;i<photo.size();i++)
    {
        int sum=0;
        for(string str: photo[i])
        {
            sum+=grPoint[str];
        }
        answer.push_back(sum);
    }
    return answer;
}
