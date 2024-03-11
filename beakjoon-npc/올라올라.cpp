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
    int prev;
    cin >> prev;
    int decrease = 1;
    int M = 1;
    for(int i = 1; i < n; i++){
        int num;
        cin >> num;

        if(num < prev){
            decrease++;
            M = max(M, decrease);
        }
        else{
            prev = num;
            decrease = 1;
        }
    }
    cout << M;
}
