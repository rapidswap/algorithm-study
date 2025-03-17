#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++)
    {
        int num = arr1[i]|arr2[i];
        string str="";
        while(str.length()!=n)
        {
            if(num%2==0)
                str+=" ";
            else
                str+="#";
            num/=2;
        }
        reverse(str.begin(),str.end());
        answer.push_back(str);
    }
    
    
    return answer;
}
