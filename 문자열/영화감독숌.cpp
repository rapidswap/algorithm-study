#include<iostream>
#include<vector>
#include<string>

using namespace std;

int factorial(int num)
{
	if (num == 1 || num == 0) return 1;
	else
		return factorial(num - 1) * num;
}

int main()
{
	int n;
	cin >> n;

	vector<int> title;
	title.push_back(666);
	int i = 1666;
	int cnt = 1;
	
	while (cnt != n)
	{
		string t = to_string(i);
		if (t.find("666") != string::npos)
		{
			title.push_back(i);
			cnt++;
		}
		i++;
	}
	//cout << title[0]<<'\n';
	cout << title[n-1];

}
