#include <iostream>
using namespace std;

string solve(vector<int>& piles) {
    int xorSum = 0;

    for (int stones : piles) {
        xorSum ^= (stones % 4);
    }

    if (xorSum == 0)
        return "Player B";
    else
        return "Player A";
}

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << solve(piles);

    return 0;
}