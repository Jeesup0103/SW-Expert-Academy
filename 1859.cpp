#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int j = 0; j < T; j++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max = arr[arr.size()-1];
        long sum = 0;
        for(int i = arr.size()-1; i >0; i--)
        {
            if(arr[i-1] > max){
                max = arr[i-1];
                continue;
            }
            else if(arr[i-1] < max)
            {
                sum += max - arr[i-1];
            }
        }
        cout << "#" << j+1 << " " << sum << "\n";
    }
}

