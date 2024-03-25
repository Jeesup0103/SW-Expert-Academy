#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define MAX 1000001
using namespace std;

int arr[MAX];
long long sum[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i < MAX; i++){
		for(int j = i; j < MAX; j=j+i){
			arr[j] += i;
		}
	}
	for(int i = 1; i < MAX; i++){
		sum[i] = sum[i-1]+arr[i];
	}

	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		cout << sum[k] << "\n"; 
	}

	return 0;
}