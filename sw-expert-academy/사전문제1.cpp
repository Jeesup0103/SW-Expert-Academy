#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findLevel(int pos) {
    int level = 0;
    while (pos > 0) {
        level++;
        pos -= level;
    }
    return level;
}


int calculateCost(int s, int e) {
    int levelStart = findLevel(s);
    int startOfLevelStart = (levelStart * (levelStart - 1)) / 2 + 1;
    int indexInLevelStart = s - startOfLevelStart + 1;
    
    int levelEnd = findLevel(e);
    int startOfLevelEnd = (levelEnd * (levelEnd - 1)) / 2 + 1;
    int indexInLevelEnd = e - startOfLevelEnd + 1;

    
    // Case 1
    if (levelStart == levelEnd) {
        return abs(indexInLevelEnd - indexInLevelStart);
    }
    
    // Case 2
    int layerDiff = levelEnd - levelStart;
    int indexDiff = abs(indexInLevelEnd - indexInLevelStart);
    if (indexInLevelStart <= indexInLevelEnd) {
        if (indexDiff <= layerDiff) {
            return layerDiff;
        } else {
            return layerDiff + (indexDiff - layerDiff);
        }
    } else {
        return layerDiff + indexDiff;
    }
}


int main() {
    int T, s, e;
    cin >> T; // Number of test cases

    for (int i = 1; i <= T; i++) {
        cin >> s >> e;
        if(e < s)
        {
            int temp = e;
            e = s;
            s = temp;
        }
        cout << "#" << i << " " << calculateCost(s, e) << "\n";
    }
    return 0;
}