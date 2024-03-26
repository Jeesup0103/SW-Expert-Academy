#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
		cin >> n; //회문 길이
		vector<string> v;
		for(int i = 0; i < 8; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);

		}
		int cnt = 0;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				//가로
				int flag = 0;
				for(int k = 0; k < n/2; k++)
				{
					if(j+n-k > 8)
						break;
					if(v[i][j+k] == v[i][j+n-1-k])
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					cnt++;
				}
				//세로
				flag = 0;
				for(int k = 0; k < n/2; k++)
				{
					if(i+n-k > 8)
						break;
					if(v[i+k][j] == v[i+n-1-k][j])
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					cnt++;
				}
			}
			
		}
		cout << "#" << test_case << " "<< cnt << "\n";
	}
	return 0;
}