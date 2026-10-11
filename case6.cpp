#include <iostream>
using namespace std;
#define SIZE 10
int table[SIZE];

void init(){
    for(int i=0;i<SIZE;i++) table[i]=-1;
}
void insert(int x){
    int index = x % SIZE;
    int original = index;
    while(table[index]!=-1){
        cout<<"Collision at "<<index<<" for "<<x<<", probing..."<<endl;
        index = (index+1)%SIZE;
        if(index==original){ cout<<"Table Full!\n"; return; }
    }
    table[index]=x;
    cout<<x<<" inserted at index "<<index<<endl;
}
void search(int x){
    int index = x % SIZE;
    int original = index;
    while(table[index]!=-1){
        if(table[index]==x){ cout<<x<<" found at index "<<index<<endl; return; }
        index=(index+1)%SIZE;
        if(index==original) break;
    }
    cout<<x<<" not found!\n";
}
void display(){
    cout<<"\nHash Table:\nIndex -> Account No\n";
    for(int i=0;i<SIZE;i++){
        cout<<i<<" -> ";
        if(table[i]==-1) cout<<"EMPTY";
        else cout<<table[i];
        cout<<endl;
    }
}
int main(){
    init();
    int ch, x;
    while(true){
        cout<<"\n1.INSERT x 2.SEARCH x 3.DISPLAY 4.EXIT\nChoice: ";
        cin>>ch;
        if(ch==4) break;
        if(ch==1){ cout<<"Enter account no: "; cin>>x; insert(x); }
        else if(ch==2){ cout<<"Enter account no: "; cin>>x; search(x); }
        else if(ch==3) display();
    }
    return 0;
}