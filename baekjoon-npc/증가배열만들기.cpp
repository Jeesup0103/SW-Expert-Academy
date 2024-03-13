#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
    cin >> n;
    int cnt = 0;
    int prev = -1;
    if( n == 1){
        cout << "-1";
        return 0;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i == 0){
            prev = a;
            cnt++;
        }
        else if(i == n-1){
            if(prev != a){
                for(int j = 0; j < cnt; j++){
                    cout << i+1 << " ";
                }
                cout << "-1";
            }
            else{
                cnt++;
                for(int j = 0; j < cnt; j++){
                    cout << "-1 ";
                }
            }
        }
        else{
            if(prev != a){
                prev = a;
                for(int j = 0; j < cnt; j++){
                    cout << i+1 << " ";
                }
                cnt = 1;
            }
            else if(prev == a){
                cnt++;
            }
        }
    }
	return 0;
}
