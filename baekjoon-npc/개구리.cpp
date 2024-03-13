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
    
	string cry;
    cin >> cry;
    int ans = 0;
    int k = 0;
    int p = 0;;
    for(int i = 0; i < cry.length(); i++){
        if(cry[i] == 'P'){
            if(k == 0){
                p++;
            }
            else{
                p++;
                k--;
            }
        }
        else if(cry[i] == 'K'){
            if(p == 0){
                k++;
            }
            else{
                k++;
                p--;
            }

        }
        ans = max(ans, max(k, p));
    }
    cout << ans;
	return 0;
}
