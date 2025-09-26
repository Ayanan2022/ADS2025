#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string x): data(x),next(NULL){}
};

int main(){
    int n,k;
    string s;

    cin >> n >> k;

    Node *head=NULL , *tail=NULL;

    for (int i=1;i<=n;i++){
        cin >> s;
        Node* node=new Node(s);
        if (head==NULL) head=tail=node;
        else{
            tail->next=node;
            tail=node;
        }
    }

    int cnt=0;
    Node* cur=head;
    while(cur!=NULL){
        if (cnt>=k) cout << cur->data << " ";
        cur=cur->next;
        cnt++;
    }
    cnt=0,cur=head;

    while (cnt<k){
        cout << cur->data << " ";
        cur=cur->next;
        cnt++;
    }
    return 0;

}