#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> arr(100);
        int dump;
        cin >> dump;
        for(int i = 0; i < arr.size(); i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < dump; i++)
        {
            auto minmax = minmax_element(arr.begin(), arr.end());
            if (*minmax.second - *minmax.first <= 1)
                break;
            
            arr[minmax.first - arr.begin()]++;
            arr[minmax.second - arr.begin()]--;

        }
        auto minmax = minmax_element(arr.begin(), arr.end());
        cout << "#" << test_case << " " << *minmax.second - *minmax.first << "\n";
	}
	return 0;
}