#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){}
};


int main(){
    int n,k;
    cin>> n;

    Node *head=NULL, *tail=NULL;
    for(int i=1;i<=n;i++){
        cin >> k;
        Node* node=new Node(k);
        if (head==NULL) head=tail=node;
        else{
            tail-> next=node;
            tail=node;
        }
    }


    int num, indx;
    cin >> num >> indx; // число и индекс (0-based)

    Node* newNode = new Node(num); // создаём новый узел заранее

    if (indx == 0) {
        // вставка в начало
        newNode->next = head;
        head = newNode;
    } else {
        Node* cur = head;
        int pos = 0;
        while (cur != NULL && pos < indx - 1) {
            cur = cur->next;
            pos++;
        }
        if (cur != NULL) {
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    Node* cur=head;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }

    return 0;
}


