#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    int cnt = 0;
    bool isHead = false;
    bool isRightHand = false;
    bool isLeftHand = false;
    int lefthand = 0;
    int righthand = 0;
    int leftleg = 0;
    int rightleg = 0;
    vector<int>heart;
    int head = 0;
    int tw = 0;

    while (n--)
    {
        cnt++;
        string cookie;

        getline(cin, cookie);
        
        for (int i = 0; i < cookie.size(); i++)
        {
            if (cookie[i] == '*')
            {
                
                if (!isHead)
                {
                    isHead = true;
                    head = i;
                    continue;
                }
                else
                {
                    if (i <= head)
                    {
                        if (i == head)
                        {
                            tw++;
                        }
                        if (!isLeftHand)
                        {
                            if (i == head)
                            {
                                isLeftHand = true;
                                heart.push_back(cnt);
                                heart.push_back(i + 1);
                              
                                continue;
                            }
                            else
                                lefthand++;
                        }
                        else
                        {
                            if (i == head)
                                continue;
                            else
                                leftleg++;
                        }
                    }



                    if (i > head)
                    {
                        if (!isRightHand)
                        {
                            righthand++;

                        }
                        else
                        {
                            rightleg++;
                        }
                        
                    }
                    
                }
            }
            if (isLeftHand && i == cookie.size() - 1)
            {
                isRightHand = true;
            }
        }
    }
    
    for (int nn : heart)
    {
        cout << nn << " ";
    }
    cout << '\n';
    cout << lefthand << " " << righthand << " "<<tw-1<<" " << leftleg << " " << rightleg;
    return 0;
}
