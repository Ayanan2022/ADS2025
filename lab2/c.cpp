#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x): data(x),next(NULL){}
};

int main(){
    int n,k;
    cin >> n;

    Node *head=NULL , *tail=NULL;
     
    for(int i=1;i<=n;++i){
        cin >> k;
        Node* node=new Node(k);
        if(head==NULL) head=tail=node;
        else{
            tail->next=node;
            tail=node;
        }
    }

    Node* cur=head;
    int pos=1;
    while(cur!=NULL){
        if(pos%2==1) cout << cur->data << " ";
        cur=cur->next;
        pos++;
    }
    cout << endl;
    return 0;
}
