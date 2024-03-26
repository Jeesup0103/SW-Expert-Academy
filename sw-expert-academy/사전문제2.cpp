#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

struct Agent {
    int first;
    int second;
    int third;
};

const int MAX_AGENTS = 50;
vector<Agent> agents;
int multipleCandidate[3] = 0;


int main(int argc, char** argv)
{
	int T;
    cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int M;
        int ans = 0;
        int loss[3] = INT_MAX;
        bool candA = false;
        bool candB = false;
        bool candC = false;
        cin >> M;
        agents.resize(n);
        for(int i = 0; i < M; i++)
        {
            int a, b, c, sum;
            cin >> a >> b >> c;
            sum = a+b+c;
            agents[i].first = a;
            agents[i].second = b;
            agents[i].third = c;
            int max = 0;
            if(a > b){
                if(a > c){
                    max = a;
                    candA = true;
                }
                else if(c > a){
                    max = c;
                    candC = true;
                }
                else{
                    if(candA == true || candC == true)
                        max = a;
                    else{
                        // both false
                        // two max a, c
                    }
                }
            }
            else if(b > a){
                if(b > c){
                    max = b;
                    candB = true;
                }
                else if(c > b){
                    max = c;
                    candC = true;
                }
                else{
                    if(candB == true || candC == true)
                        max = b;
                    else{
                        // both false
                        // two max b, c

                        if(loss[1] > sum - b){
                            loss[1] sum-b;
                        }
                    }
                }
            }
            else{
                if(c > a){
                    max = c;
                    candC = true;
                }
                else if(c < a){
                    if(candA == true || candB == true)
                        max = a;
                    else{
                        // two max a, b

                    }
                }
                else{
                    if()
                    // three max a, b, c
                }
            }
            ans += sum - max;
        }
	}
	return 0;
}
