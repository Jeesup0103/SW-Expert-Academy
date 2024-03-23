#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> people(n);
    for(int i = 0; i < n ;i++){
        cin >> people[i];
    }

    int lPoint = 0;
    int rPoint = n-1;


    int ans = 0;
    while(lPoint <= rPoint){
        int tmp = (rPoint-lPoint-1) * min(people[rPoint], people[lPoint]);
        ans = max(tmp, ans);

        if(people[rPoint] > people[lPoint]){
            lPoint++;
        }
        else{
            rPoint--;
        }
    }
    cout << ans;
	return 0;
}