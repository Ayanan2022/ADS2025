#include <iostream>
using namespace std;

int a[1005];
int b[1005];

void quick_srt(int l,int r){
    int pivot=a[(l+r)/2];
    int i=l;
    int j=r;

    while (i<j){
        while (a[i]<pivot) i++;
        while (a[j]>pivot) j--;

        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(l<j) quick_srt(l,j);
    if(r>i) quick_srt(i,r);
}

void quick_srt_for_b(int l,int r){
    int pivot=b[(l+r)/2];
    int i=l;
    int j=r;

    while (i<j){
        while (b[i]<pivot) i++;
        while (b[j]>pivot) j--;

        if(i<=j){
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }

    if(l<j) quick_srt_for_b(l,j);
    if(r>i) quick_srt_for_b(i,r);
}

int main(){
    int n,m;
    cin >> n >> m;;

    for (int i=0;i<n;i++) cin >> a[i] ;
    for (int i=0;i<m;i++) cin >> b[i];

    quick_srt(0,n-1);
    quick_srt_for_b(0,m-1);

    int i=0,j=0;
    while (i < n && j < m) {
        if (a[i]==b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return 0;
}