#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int start=section[0];
    
    for(int i=1;i<section.size();i++)
    {
        if(section[i]<start+m) continue;
        else
        {
            start=section[i];
            answer++;
        }
    }
    
    
    
    return answer;
}
