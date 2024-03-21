#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <fstream>

using namespace std;
vector<long long> arr(100001);

long long binsearch1(long long a, long long low, long long high) {
    if (high >= low) {
        long long mid = low + (high - low) / 2;

        if (arr[mid] >= a)
            return binsearch1(a, low, mid - 1);
		else 
            return binsearch1(a, mid + 1, high);
    }
    return low;
}

long long binsearch2( long long a, long long low, long long high) {
    if (high >= low) {
        long long mid = low + (high - low) / 2;

        if (arr[mid] > a)
            return binsearch2(a, low, mid - 1);
		else 
            return binsearch2(a, mid + 1, high);
    }
    return low;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long n, m;
	cin >> n >> m;
	arr.resize(n);

	for(long long i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for(long long i = 0; i < m; i++){
		long long a, b, c;
		cin >> a;
		cin >> b;
		long long ans;
		if(a == 1){
			ans = arr.size() - binsearch1(b, 0, arr.size()-1);
			cout << binsearch1(b, 0, arr.size()-1) << "----";

		}
		else if(a == 2){
			ans = binsearch2(b, 0, arr.size()-1);
			cout << ans << "----";
			if(arr[ans] == b){
				ans =  arr.size() - ans -1;
			}
			else{
				ans = arr.size() - ans;
			}
		}
		else{
			cin >> c;
			long long small = binsearch1(b, 0, arr.size()-1);
			long long big =  binsearch2(c, 0, arr.size()-1);
			ans = big - small;
		}

		cout << ans << "\n";
	}
	return 0;
}
