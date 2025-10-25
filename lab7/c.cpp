#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int left,int mid,int right){
    int n1=mid - left + 1;
    int n2=right - mid;

    vector <int> l(n1),r(n2);

    for ( int i = 0;i < n1;i++){
        l[i] = arr[left + i];
    }
    for( int j = 0; j < n2; j++){
        r[j]=arr[mid + 1 + j];
    }

    int i=0,j=0,k=left;

    while ( i < n1 && j < n2){
        if ( l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }

    while( j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr,int left,int right){
    if (left < right ) {
        int mid=left + (right-left)/2; 

        mergesort(arr,left,mid) ; 
        mergesort (arr,mid+1,right) ;
         
        merge ( arr,left,mid,right);
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    mergesort(a,0,a.size()-1);
    mergesort(b,0,b.size()-1);

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            cout << a[i] << " ";
            i++; j++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    return 0;
}
