#include <iostream>
#include <stack>
using namespace std;

int main(){
    string a;
    cin >> a;
    
    stack<char> st;
    for(int i=0;i < a.size() ; i++){
        if(!st.empty() && st.top()==a[i]){
            st.pop();
        }
        else{
            st.push(a[i]);
        }
    }

    if (st.empty()){
        cout << "YES";
    }
    else{
        cout << "NO" ;
    }
    return 0;
}