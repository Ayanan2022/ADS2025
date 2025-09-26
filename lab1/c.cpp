#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b ;
    
    stack<char> st1,st2;
    for(int i=0;i < a.size() ; i++){
        if(a[i]=='#'){
            if(!st1.empty()){
                st1.pop();
            }
        }
        else{
            st1.push(a[i]);
        }
    }

    for(int i=0;i < b.size() ;i++){
        if(b[i]=='#'){
            if(!st2.empty()){
                st2.pop();
            }
        }
        else{
            st2.push(b[i]);
        }
    }

    string rsl1="",rsl2="";
    while(!st1.empty()){
        rsl1=st1.top()+rsl1;
        st1.pop();
    }

    while(!st2.empty()){
        rsl2=st2.top()+rsl2;
        st2.pop();
    }

    if (rsl1==rsl2){
        cout << "Yes";
    }
    else{
        cout << "No" ;
    }

    return 0;

}