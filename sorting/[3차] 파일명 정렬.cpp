#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct filename{
    int idx;
    string head;
    int num;
};
vector<filename> v;

bool cmp(const filename& a,const filename& b){
    if(a.head == b.head){
        if(a.num == b.num){
            return a.idx<b.idx;
        }
        else return a.num<b.num;
    }
    else return a.head<b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i=0;i<files.size();i++){
        vector<int> index;
        for(int j=0;j<files[i].size();j++){
            if('0'<=files[i][j] && files[i][j]<='9'){
                index.push_back(j);
            }
        }
        string head="";
        for(int j=0;j<index[0];j++){
            head+=tolower(files[i][j]);
        }
        string number=files[i].substr(index[0],index.size());
       
        filename f;
        f.idx=i;
        f.head = head;
        f.num=stoi(number);
        
        v.push_back(f);
    }
    
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        answer.push_back(files[v[i].idx]);
    }
    return answer;
}
