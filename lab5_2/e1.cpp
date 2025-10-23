#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
public:
    vector <int> a;

    long long sum;
    MinHeap() { sum = 0; }

    int parent(int i) { return (i-1)/2; }
    int left(int i) {return 2*i+1; }
    int right(int i) {return 2*i+2; }

    int getMin() { return a[0]; }

    void insert(int k){
        a.push_back(k);
        int ind=a.size()-1;

        while(ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
    }

    void heapify(int i){
        int smallest=i;
        int l=left(i);
        int r=right(i);

        if (l<a.size() && a[l] < a[smallest]) smallest=l;
        if (r<a.size() && a[r] < a[smallest]) smallest=r;

        if (smallest!=i){
            swap(a[i],a[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
        int root_value=getMin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if (a.size() > 0){
            heapify(0);
        }
        return root_value;
    }

    void kth(int n, int k) {
        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;

            if (cmd == "print") {
                cout << sum << '\n';
            } 
            else if (cmd == "insert") {
                int x; cin >> x;
                if ((int)a.size() < k) {
                    insert(x);
                    sum += x;
                } 
                else if (x > getMin()) {
                    sum -= extractMin();
                    insert(x);
                    sum += x;
                }
            }
        }
    }
};

int main(){
    int n,k;
    cin >> n >>k;

    MinHeap heap;
    heap.kth(n,k);

    return 0;
}