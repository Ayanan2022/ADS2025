#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
public:
    vector <int> a;

    int parent (int i) { return (i-1)/2;}
    int left(int i) {return 2*i+1; }
    int right(int i) { return 2*i+2; }

    int getMin() {return a[0]; }

    void insert(int k){
        a.push_back(k);
        int ind=a.size()-1;

        while ( ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size()-1) return;
        
        int j=left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)] ){
            j=right(i);
        }

        if(a[i] > a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int extractMin(){
        int root_value= getMin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }
        return root_value;
    }

    void build_heap(){
        for (int i = (a.size() - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    long long mergeSum(){
        long long ans = 0;
        while (a.size() > 1) {
            int x = extractMin();
            int y = extractMin();
            ans += x + y;
            insert(x + y);
        }
        return ans;
    }
    
};

int main(){
    int n;
    cin >> n;

    MinHeap h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    cout << h.mergeSum() << endl;

    return 0;
}