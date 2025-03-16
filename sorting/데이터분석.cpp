#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    if(ext=="code"){
        for(int i=0;i<data.size();i++){
            if(val_ext>data[i][0]){
                answer.push_back(data[i]);
            }
        }
    }
    
    if(ext=="date"){
        for(int i=0;i<data.size();i++){
            if(val_ext>data[i][1]){
                answer.push_back(data[i]);
            }
        }
    }
    
    if(ext=="maximum"){
        for(int i=0;i<data.size();i++){
            if(val_ext>data[i][2]){
                answer.push_back(data[i]);
            }
        }
    }
    
    if(ext=="remain"){
        for(int i=0;i<data.size();i++){
            if(val_ext>data[i][3]){
                answer.push_back(data[i]);
            }
        }
    }
    
    if(sort_by=="code"){
        sort(answer.begin(),answer.end(),[](const vector<int>& a, const vector<int>& b){return a[0]<b[0];});
    }
    if(sort_by=="date"){
        sort(answer.begin(),answer.end(),[](const vector<int>& a, const vector<int>& b){return a[1]<b[1];});
    }
    if(sort_by=="maximum"){
        sort(answer.begin(),answer.end(),[](const vector<int>& a, const vector<int>& b){return a[2]<b[2];});
    }
    if(sort_by=="remain"){
        sort(answer.begin(),answer.end(),[](const vector<int>& a, const vector<int>& b){return a[3]<b[3];});
    }
    
    return answer;
}
