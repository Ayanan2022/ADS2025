#include <iostream>
using namespace std;

void quick_sort(string &s,int l,int r){
    int pivot=s[(l+r)/2];
    int i=l;
    int j=r;

    while (i<=j){
        while (s[i] < pivot) i++;
        while (s[j] > pivot) j--;
        
        if(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    if (l < j) quick_sort(s,l,j);
    if (r > i) quick_sort(s,i,r);
}

int main(){
    int n;
    cin >> n;


    string s="";
    for (int i=0;i < n; i++){
        string temp;
        cin >> temp;
        s+=temp;
    }

    quick_sort(s,0,s.size()-1);

    char letter;
    cin >> letter;

    char balanced=s[0];

    for (int i=0;i<s.size();i++){
        if (s[i]>letter){
            balanced =s[i];
            break;
        }
    }

    cout << balanced << endl;

    return 0;
}