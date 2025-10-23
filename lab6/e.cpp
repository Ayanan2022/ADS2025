#include <iostream>
using namespace std;

int a[10005][10005];

// void quick_sort(int left,int right){
//     int pivot=a[(left+right)/2];
//     int i=left;
//     int j=right;

//     while (i<j){
//         while (a[i]<pivot) i++;
//         while (a[j]>pivot) j--;

//         if(i<=j){
//             swap(a[i],a[j]);
//             i++;
//             j--;
//         }
//     }

//     if (left<j) quick_sort(left,j);
//     if (right>i) quick_sort(i,right);
// }

int main(){
    int c,b;
    cin >> c >> b;

    for (int i=0;i<c;i++){
        for (int j=0;j<b;j++){
            cin >> a[i][j];
        }
    }

    for (int i=0;i<c;i++){
        for (int j=0;j<b;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}