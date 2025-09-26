#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    char a;

    while(cin >> a){
        if (a=='+'){
            int k;
            cin>> k;
            dq.push_front(k);
        }
        else if(a=='-'){
            int k;
            cin >> k;
            dq.push_back(k);
        }
        else if (a=='*'){
            if (dq.empty()){
                cout << "error"<< endl;
            }
            else{
                int sum= dq.front()+dq.back();
                cout << sum << endl;
                dq.pop_front();
                if(!dq.empty()){
                    dq.pop_back();
                } 
            }
        }
        else if(a=='!'){
            break;
        }
    }

    
    return 0;
}