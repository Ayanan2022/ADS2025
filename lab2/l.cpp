#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* next;
     Node(int x): data(x),next(NULL){}
};


int main(){
    int n,k;
    cin >> n;
    Node *head=NULL, *tail=NULL;

    for(int i=1;i<=n;++i){
        cin >> k;
        Node* node=new Node(k);
        if (head==NULL) head=tail=node;
        else{
            tail-> next=node;
            tail=node;
        }
    }

    int max_sum = INT_MIN;
    int curr_sum = 0;
    Node* curr = head;

    while (curr) {
        curr_sum = max(curr->data, curr_sum + curr->data);
        max_sum = max(max_sum, curr_sum);
        curr = curr->next;
    }

    cout << max_sum << endl;

    

    return 0;
}