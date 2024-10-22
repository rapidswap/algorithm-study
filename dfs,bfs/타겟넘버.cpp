#include <string>
#include <vector>

using namespace std;
int answer = 0;
bool board[20] = { 0 };
int sum = 0;

void dfs(int sum, vector<int> numbers, int target, int index)
{
    if (index == numbers.size())
    {
        if (sum == target)
            answer++;

        return;
    }

    dfs(sum - numbers[index], numbers, target, index + 1);
    dfs(sum + numbers[index], numbers, target, index + 1);
    
}
int solution(vector<int> numbers, int target) {
    
    dfs(0, numbers, target, 0);
    return answer;
} //https://velog.io/@euneun/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%83%80%EA%B2%9F%EB%84%98%EB%B2%84C-BFSDFS
