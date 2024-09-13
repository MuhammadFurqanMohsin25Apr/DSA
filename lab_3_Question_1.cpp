#include <iostream>
using namespace std;
class Furqan_lab3{
    private:
    int *ptr;
    int csize;
    int top;

    void resize() {
        int newSize = csize * 2; 
        int* newPtr = new int[newSize];
        
        for (int i = 0; i < csize; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr; 
        ptr = newPtr;
        csize = newSize;
        cout << "Stack resized to " << newSize << endl;
    }
    public:
    Furqan_lab3(int c){
        csize=c;
        ptr=new int[csize];
        top=-1;
    }
    ~Furqan_lab3(){
        delete []ptr;
    }
    bool isempty(){
        return top==-1;
    }
    int peek(){
        if(top==-1){
        cout<<"stack is empty"<<endl;
        return -1;
        }
        return ptr[top];
    }
    void push(int x){
        if(top==csize-1){
            cout<<"stack overflow then change the size dynamiclly"<<endl;
            resize();
        }
        else{
            ptr[++top]=x;
            cout<<x<<" is added to stack"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack is underflow"<<endl;
            
        }else{
        cout<<ptr[top--]<<" is removed from the stack."<<endl;}
    }
    int size(){
        return top+1;
    }


    void display(){
        if(top==-1){
            cout<<"stack is empty";
        }else{
            for(int i=0;i<=top;i++){
                cout<<ptr[i]<<" ";
            }
        }
    }

};
int main(){
    Furqan_lab3 a(5);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    
    cout<<"Top Element "<<a.peek()<<endl;
    cout<<"Stack size "<<a.size()<<endl;
    cout<<"after pop "<<endl;
    a.pop();
    cout<<"Top element after pop is "<<a.peek()<<endl;
    cout<<"Stack size after pop "<<a.size()<<endl;
    a.display();
    return 0;
}