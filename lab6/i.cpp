#include <iostream>
#include <string>
using namespace std;

void quick_sort(string &s,int l,int r){
    int pivot=s[(l+r)/2];
    int i=l;
    int j=r;

    while (i<j){
        while (s[i] < pivot) i++;
        while (s[j] > pivot) j--;

        if (i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    if (l<j) quick_sort(s,l,j);
    if (r>i) quick_sort(s,i,r);
}

int main(){
    string s;
    cin >> s;

    quick_sort(s,0,s.size()-1);

    cout << s << endl ;
    return 0;
}