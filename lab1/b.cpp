#include <iostream>

using namespace std;

int main(){
    
    int n, a[100005];
    
    cin >> n;
    
    bool ok = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
        
    for(int i = 1; i <= n; i++){
        ok = 0;
        for(int j = i - 1; j >= 1; j--){
            if(a[j] <= a[i]){
                ok = 1;
                cout << a[j] << ' ';
                break;
            }
        }
        if(!ok) cout << -1 << ' ';
    }
    
    
    
    return 0;
}