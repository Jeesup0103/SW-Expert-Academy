#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string ans, temp;
int flag = 0;

void dfs(string s, int exchanges, int depth)
{
    if(flag == 1) return;
    if(depth == exchanges){
        if(stoi(s) > stoi(ans)){
            ans = s;
        }
        return;
    }
    for(int j = 0; j < s.length()-1; j++)
    {
        for(int k = j+1; k < s.length(); k++){
            swap(s[j], s[k]);
            depth++;
            if(s.compare(temp) == 0){ // found best ans
                flag = 1;
                if( (exchanges - depth )%2 == 1) // left is odd
                {
                    set<char> box;
                    for(int i = 0; i < s.length(); i++){
                        if(box.end() != box.find(s[i])){
                            ans = s;
                            return;
                        }
                        else{
                            box.insert(s[i]);
                            if(i == s.length()-1){
                                swap(s[s.length()-1], s[s.length()-2]);
                                ans = s;
                                return;
                            }
                            else continue;
                        }
                    }
                }
                else{
                    ans = s;
                }
                return;
            }
            dfs(s, exchanges, depth);
            depth--;
            swap(s[k], s[j]);

        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int j = 0; j < T; j++)
    {
        string s;
        int num;

        cin >> s;
        cin >> num;
        temp = s;
        sort(temp.begin(), temp.end(), greater<int>());

        flag = 0;
        ans = "0";

        dfs(s, num, 0);
        cout << "#" << j+1 << " " << ans << "\n";
    }
}