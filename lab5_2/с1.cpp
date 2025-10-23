#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
public:
    vector <int> a;

    int parent (int i) { return (i-1)/2; }
    int left (int i) { return 2*i+1; }
    int right (int i) {return 2*i+2; }

    int getMax() { return a[0]; }

    void insert(int k){
        a.push_back(k);
        int ind=a.size()-1;

        while(ind > 0 && a[ind] > a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
    }

    void heapify(int i){
        int n = a.size();
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    } 

    int extractMax(){
        int root_value=getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if (a.size() > 0 ){
            heapify(0);
        }

        return root_value;
    }

    long long soccer(int k) {
        long long sum = 0;
        while (k-- > 0 && !a.empty()) {
            int mx = extractMax();
            sum += mx;
            if (mx - 1 > 0) insert(mx - 1);
        }
        return sum;
    }
};

int main(){
    int n,k;
    cin >> n >> k;

    MaxHeap heap;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        heap.insert(x);
    }

    cout << heap.soccer(k);
    return 0;
}