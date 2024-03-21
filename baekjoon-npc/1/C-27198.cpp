#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

vector<int> arr(10001);
vector<int> miss(10001);

int binsearch(int a, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (miss[mid] >= a)
            return binsearch(a, low, mid - 1);
		else 
            return binsearch(a, mid + 1, high);
    }
    return low;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	arr.resize(n);
	miss.resize(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int MM = arr[n-1];

	for(int i = 0; i < n; i++){
		miss[i] = arr[i] - i;
	}
	
	for(int i = 0; i < m; i++){
		int q;
		int sol, val;
		cin >> q;
		if(q <= miss[n-1]){
			val = binsearch(q, -1, n)-1;
			sol = arr[val] + q - miss[val];
			if(val == -1)
				sol = q-1;
		}
		else{
			sol = MM + q-miss[n-1];
		}
		cout << sol << ' ';
	}
	return 0;
}
