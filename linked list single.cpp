#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int x);
void printNode(Node *head);
void addElement(Node *&head, int x);

int showMenu();
void addFront(Node *&head, int x);
void addBack(Node *&head, int x);
void addMiddle(Node *&head, int x, int k);
void popFront(Node *&head);
void popBack(Node *&head);
void popMidlle(Node *&head, int k);

int main(){
    int n,x,k;
    Node *head = NULL;
    cout <<"NHAP N: ";
    cin >> n;
    cout <<"NHAP X: ";
    for(int i = 0; i<n; i++){
        cin >>x;
        addElement(head,x);
    }
    while (true)
    {
        int choose = showMenu();
        switch (choose)
        {
        case 1:
            printNode(head);
            break;
        case 2:
            cout << "NHAP K: ";
            cin >> k;
            cout <<"NHAP X: ";
            cin >>x;
            if(k==0){
                addFront(head,x);
            } else if(k==n){
                addBack(head,x);
            } else{
                addMiddle(head,x,k);
            }
            break;
        case 3:
            cout << "NHAP K: ";
            cin >> k;
            if(k==0){
                popFront(head);
            } else if(k==n){
                popBack(head);
            } else{
                popMidlle(head,k);
            }
            break;  
        case 0:
            cout <<"BYE BYE BYE!!!";
            return 0;  
        default:
            cout <<"KHONG HOP LE.";
        }
        bool is_continue;
        cout <<"BAN CO MUON TIEP TUC KHONG?(1/0)";
        cin >> is_continue;
        if(is_continue==false){
            cout <<"BYE BYE BYE!!!";
            break;
        }
    }
    

}

int showMenu(){
    system("cls");
    int choose;
    cout<<"=====MENU====="<<endl;
    cout <<"1. XEM DANH SACH"<<endl;
    cout<<"2. THEM PHAN TU"<<endl;
    cout<<"3. XOA PHAN TU"<<endl;
    cout <<"0. THOAT."<<endl;
    cout <<"LUA CHON CUA BAN LA: ";
    cin >> choose;
    return choose;
}

Node *createNode(int x){
    Node *newNode = new Node;
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

void addElement(Node *&head, int x){
    Node *temp = head;
    Node *newNode = createNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printNode(Node *head){
    while(head != NULL){
        cout << head->data<<" ";
        head=head->next;
    }
}

void addFront(Node *&head, int x){
    Node *newNode = createNode(x);
    newNode->next = head;
    head = newNode;
}

void addBack(Node *&head, int x){
    Node *newNode = createNode(x);
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp = newNode;
}

void addMiddle(Node *&head, int x, int k){
    Node *newNode = createNode(x);
    Node *temp = head;
    for(int i=1; i<=k-1; i++){
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(Node *&head){
    Node *temp = head;
    if(head == NULL){
        return;
    }
    head = head->next;
    delete temp;
}   

void popBack(Node *&head){
    Node *temp = head;
    if(head == NULL){
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = NULL;
    delete last;
}

void popMidlle(Node *&head, int k){
    Node *temp = head;
    for(int i =1; i<=k-1; i++){
        temp=temp->next;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}
