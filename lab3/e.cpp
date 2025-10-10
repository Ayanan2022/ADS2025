#include <iostream>
#include <vector> 
#include <cmath> 
#include <algorithm> 

using  namespace std; 
int main() {
    int n, k; cin >> n >> k; 
    vector<int> pos; 
    int L = 0, res; 

    while(n--){
        int x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4; 

        pos.push_back(max(x3, x4)); 
    }
    sort(pos.begin(), pos.end());

    for(auto &l : pos){
        if(L < k){
            L++;
            res = l; 
        }
        else { 
            break; 
        }

    }

    cout << res; 
}
