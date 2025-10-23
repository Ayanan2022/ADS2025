#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
public:
    vector<int> a;

    int parent (int i) { return (i-1)/2; }
    int left(int i) {return 2*i+1; }
    int right(int i) {return 2*i+2; }

    int getMin() { return a[0]; }

    void insert(int k){
        a.push_back(k);
        int ind=a.size()-1;

        while ( ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
    }

    void heapify(int i){
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < a.size() && a[l] < a[smallest]) smallest = l;
        if (r < a.size() && a[r] < a[smallest]) smallest = r;

        if (smallest != i) {
            swap(a[i], a[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
        int root_value=getMin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if ( a.size() > 0 ){
            heapify(0);
        }

        return root_value;
    }

    long long experiment(long long m){
        int cnt = 0;

        while (a.size() > 1 && a[0] < m) {
            long long x = extractMin();       
            long long y = extractMin();       
            long long d_new = x + 2 * y;      
            insert(d_new);
            cnt++;
        }

        if (a[0] < m) return -1; 
        return cnt;
    }

};

int main() {
    int n;
    long long m;
    cin >> n >> m;

    MinHeap heap;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap.insert(x);
    }

    cout << heap.experiment(m);
    return 0;
}