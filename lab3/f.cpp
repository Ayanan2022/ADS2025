#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> com(n);
    for(int i = 0; i < n; i++) cin >> com[i];

    int r;
    cin >> r;

    for(int i = 0; i < r; i++) {
        int markPower;
        cin >> markPower;

        int w = 0;
        long long sp = 0; 

        for(int power : com) {
            if(power <= markPower) {
                w++;
                sp += power;
            }
        }

        cout << w << " " << sp << endl;
    }

    return 0;
}
