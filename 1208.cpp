#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> arr(100);
        int dump;
        cin >> dump;
        for(int i = 0; i < 100; i++)
        {
            int n;
            cin >> n;
            arr.push_back(n);
        }

        sort(arr.front(), arr.end());

        int diff = arr.end() - arr.end();
        

	}
	return 0;
}