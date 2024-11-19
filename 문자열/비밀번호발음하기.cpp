#include<iostream>
#include<vector>
#include<string>

#include<algorithm>

using namespace std;

bool Mcheck(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
   }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    

    while (1)
    {
        bool aeiou = true;
        bool triple = false;
        bool dbwrd = false;
        string password;
        getline(cin, password);
        if (password == "end")
            break;
        int M = 0;
        int J = 0;
        for (int i = 0; i < password.size(); i++)
        {
            if (Mcheck(password[i]))
            {
                J = 0;
                aeiou = false;

                if (password[i] == 'o')
                {
                    if (i < password.size())
                    {
                        if (password[i + 1] == 'o')
                            continue;
                    }
                }
                if (password[i] == 'e')
                {
                    if (i < password.size())
                    {
                        if (password[i + 1] == 'e')
                            continue;
                    }
                }
                if (i < password.size())
                {
                    if (password[i] == password[i + 1])
                    {
                        dbwrd = true;
                        break;
                    }
                }
                M++;
                if (M > 2)
                {
                    triple = true;
                    break;
                }
            }
            else
            {
                M = 0;
                J++;
                if (J > 2)
                {
                    triple = true;
                    break;
                }
                if (i < password.size())
                {
                    if (password[i] == password[i + 1])
                    {
                        dbwrd = true;
                        break;
                    }
                }
            }
        }
        if (aeiou || triple || dbwrd)
            cout << "<" << password << ">" << " is not acceptable.\n";
        else if (!aeiou && !triple && !dbwrd)
            cout << "<" << password << ">" << " is acceptable.\n";
    }
    return 0;
}
