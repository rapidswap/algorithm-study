#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size()/2;
    
    int answer = 0;

    set<int> a;
    for (int i = 0; i < nums.size(); i++)
    {
        a.insert(nums[i]);
    }
    if (a.size() <= n)
    {
        answer = a.size();
    }
    else
    {
        answer = n;
    }
    return answer;
}
//https://velog.io/@woga1999/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%8F%B0%EC%BC%93%EB%AA%ACC
