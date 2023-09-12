#include<iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;

        int ans = 0;

        vector<int> b;

        for(int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            b.push_back(n);
        }

        for(int i = 2; i < N-2; i++)
        {
            int val = max(max(b[i-2], b[i-1]), max(b[i+1], b[i+2]));
            if(b[i] > val)
            {
                ans += b[i] - val;
            }
        }
        cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}