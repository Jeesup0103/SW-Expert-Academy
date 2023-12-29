#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
		cin >> n;
		vector<string> v;
		for(int i = 0; i < 100; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		int cnt = 0;
        int maximum = -1;
		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 100; j++)
			{
				//가로
				int flag = 0;
				for(int k = j; k < 100; k++)
				{
					string substr = v[i].substr(j, k - j + 1);
                    if (isPalindrome(substr)) {
                        maximum = max(maximum, k - j + 1);
                    }
				}
				//세로
                for (int k = j; k < 100; ++k) {
                    string substr = "";
                    for (int p = j; p <= k; ++p) {
                        substr += v[p][i];
                    }
                    if (isPalindrome(substr)) {
                        maximum = max(maximum, k - j + 1);
                    }
                }
			}
			
		}
		cout << "#" << test_case << " "<< maximum << "\n";
	}
	return 0;
}