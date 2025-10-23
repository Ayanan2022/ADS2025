#include <iostream>
#include <vector>
using namespace std;

int a[100000];

void quick_sort(int l,int r){
    int pivot=a[(l+r)/2];
    int i=l;
    int j=r;

    while(i<=j){
        while (a[i]<pivot) i++;
        while (a[j]>pivot) j--;

        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if (l<j) quick_sort(l,j);
    if (r>i) quick_sort(i,r);
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    quick_sort(0,n-1);

    int temp_min=abs(a[0]-a[1]);
    for (int i=1;i<n-1;i++){
        int mn=abs(a[i]-a[i+1]);
        if (mn<temp_min) temp_min=mn;
    }

    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1]) == temp_min){
            cout << a[i] << " " << a[i+1] << " ";
        }
    }

    return 0;

}