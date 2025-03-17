#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> points;
    int getMin=INT_MAX;
    for(int i=0;i<score.size();i++)
    {
        if(i<k)
        {
            getMin=min(getMin,score[i]);
            answer.push_back(getMin);
            points.push_back(score[i]);
        }
        else
        {
                if(getMin<=score[i])
                {
                    // points.erase(remove(points.begin(),points.end(),getMin),points.end());
                    for(int m=0;m<points.size();m++)
                    {
                        if(points[m]==getMin)
                        {
                            points.erase(points.begin()+m);
                            break;
                        }
                    }
                    points.push_back(score[i]);
                    getMin=*min_element(points.begin(),points.end());

                    answer.push_back(getMin);
                }
            else
                answer.push_back(getMin);
        }
    }
    return answer;
}
