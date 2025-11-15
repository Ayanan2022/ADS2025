#include <iostream>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;

    string q=s;
    int k=1;

    while (q.size() < t.size()){
        q=q+s;
        k++;
    }

    if (q.find(t) != string::npos){
        cout << k << '\n';
    }

    q += s;
    k++;
    if (q.find(t) != string::npos) {
        cout << k << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}