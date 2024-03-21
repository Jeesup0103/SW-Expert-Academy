#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
	for(int i = 0; i < m ;i++){
		int place;
		cin >> place;
		cnt = k;

		bomb.insert(place);

		vector<int>space;
		space.push_back(bomb[0]-start-1);
		space.push_back(end-bomb[bomb.size()-1]);

        int l = space[0];
        int r = space[1];
		for(int j = 0; j < bomb.size(); j++){
			if(j == bomb.size()-1 || bomb[j+1] - bomb[j] - 1 < a)
				continue;
			space.push_back(bomb[j+1] - bomb[j] - 1);
		}

		for(int j = 0; j < space.size(); j++){
			int tmp = space[j];
			while(tmp >= a){
				cnt--;
				tmp -= a;
				if(tmp>0)
					tmp--;
			}
			if(cnt < 0)
				break;
		}

		if(cnt > 0){
			cout << i+1;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}