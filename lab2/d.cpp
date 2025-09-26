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
    int n,k;
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
   
    int pos=-1,cnt;
    while(cur!=NULL){
        for(int i=1; i <=n ; i++){
            
        }
    }
    cout << pos ;
    return 0;
}
