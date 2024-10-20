#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map <string, int> music;
    map <string, map<int, int>> musiclist;

    for (int i=0 ; i < genres.size(); i++)
    {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }

    while (music.size() > 0) {
        string genre{};
        int max{ 0 };
        for (auto mu : music)
        {
            if (max < mu.second)
            {
                max = mu.second;
                genre = mu.first;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int idx = -1;
            int val = 0;
            for (auto ml : musiclist[genre])
            {
                if (val < ml.second)
                {
                    val = ml.second;
                    idx = ml.first;
                }
            }
            if (idx == -1)
                break;
            answer.push_back(idx);
            musiclist[genre].erase(idx);
        }
        music.erase(genre);

    }
    
    return answer;
}

//int main()
//{
//    vector <string> genres = {"classic", "pop", "classic", "classic", "pop"};
//    vector <int> plays = { 500, 600, 150, 800, 2500 };
//    vector<int> list = solution(genres, plays);
//    for (int i = 0; i < list.size(); i++)
//    {
//        cout << list[i];
//    } unordered 쓰면 틀림..
//} // https://mungto.tistory.com/196
