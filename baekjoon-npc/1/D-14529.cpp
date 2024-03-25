#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int calcShip(int a, int space){
    int cnt = 0;
    while(space >= a){
        cnt++;
        space -= a;
        if(space>0)
            space--;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, k, a, m;
	cin >> n >> k >> a;
	cin >> m;
	int start = 0;
	int end = n;
	int cnt = k;

	set<int> bomb;
    bomb.insert(0);
    bomb.insert(n+1);
    int tmp = n;
    int ogNumShip = 0;

    while(tmp >= a){
        ogNumShip++;
        tmp -= a;
        if(tmp>0)
            tmp--;
    }

	for(int i = 0; i < m ;i++){
		int place;
		cin >> place;
		cnt = k;

        auto it = bomb.insert(place).first;
        auto prev = it, next = it;
        prev--;
        next++;

        int l = *prev;
        int r = *next;
        int prevSpace = r - l -1;
        int prevShip = calcShip(a, prevSpace);
        int lSpace = place - l -1;
        int rSpace = r - place - 1;
        int lShip = calcShip(a, lSpace);
        int rShip = calcShip(a, rSpace);

        ogNumShip = ogNumShip - prevShip + lShip + rShip;

        
        if(ogNumShip < k){
            cout << i+1;
            return 0;
		}
	}
	cout << "-1";
	return 0;
}