#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> sw(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> sw[i];
	}

	int people;
	cin >> people;

	while (people--)
	{
		int gender, no;
		cin >> gender>> no;
		
		if (gender == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (i % no == 0)
				{
					if (sw[i] == 0)
						sw[i] = 1;
					else
						sw[i] = 0;
				}
			}
		}
		if (gender == 2)
		{
			int front = no - 1;
			int back = no + 1;
			bool found = false;
			while (front>=1 && back<=n)
			{
				if (sw[front] == sw[back])
				{
					found = true;
					if (sw[front] == 0)
						sw[front] = 1;
					else
						sw[front] = 0;

					if (sw[back] == 0)
						sw[back] = 1;
					else
						sw[back] = 0;
				}
				else
				{
					break;
				}
				front--;
				back++;
			}

			if (sw[no] == 0)
				sw[no] = 1;
			else
				sw[no] = 0;


		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << sw[i] << " ";
		if(i%20==0)
			cout<<'\n';
	}
	return 0;
}
