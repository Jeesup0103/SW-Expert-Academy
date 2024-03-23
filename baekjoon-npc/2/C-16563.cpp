#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define MAX 5000001
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	arr[0] = -1;
	arr[1] = -1;
	for(int i = 2; i < MAX; i++){
		arr[i] = i;
	}
	for(int i = 2; i < sqrt(MAX); i++){
		for(int j = i*i; j < MAX; j=j+i){
			if(arr[j] == j)
				arr[j] = i;
		}
	}

	for(int i = 0; i < n; i++){
		int k;
		cin >> k;

		while(k>1){
			cout << arr[k] << " ";
			k = k / arr[k];
		}
		cout << "\n";
	}
	return 0;
}
