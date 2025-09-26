#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x): data(x),next(NULL){}
};

int main(){
    int n,k,a,min=INT_MAX;
    cin >> n ;

    Node *head=NULL , *tail=NULL;
// заполняем
    for(int i=1;i<=n;i++){
        cin >> k ;
        Node* node=new Node(k);
        if (head==NULL) head=tail=node;
        else{
            tail-> next=node;
            tail=node;
        }
    }
// выводит
    Node* cur=head;
    cin >> a;
    int pos=-1,cnt=0;
    while(cur!=NULL){
        if(abs(cur->data - a) < min){
            min=abs(cur->data - a);
            pos=cnt;
        }
        cur=cur->next;
        cnt++;
    }
    cout << pos ;
    return 0;
}
