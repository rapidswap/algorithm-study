#include <string>
#include <vector>

using namespace std;
bool vist[50];
int answer = 51;

bool dif_word(string word, string difword)
{
    int dif_cnt = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != difword[i])
            dif_cnt++;
    }
    if (dif_cnt == 1)
        return true;
    else
        return false;
}

void dfs(string begin, string target, vector<string> words, int cnt)
{
    if (answer <= cnt) return;

    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (dif_word(begin, words[i]) && !vist[i])
        {
            vist[i] = true;
            dfs(words[i], target, words, cnt + 1);
            vist[i] = false;
        }    
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if (answer == 51) answer = 0;
    return answer;
}//https://velog.io/@euneun/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%8B%A8%EC%96%B4-%EB%B3%80%ED%99%98BFSDFS-C-v5lnyekn
