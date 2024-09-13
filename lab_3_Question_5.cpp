#include<iostream>
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
    int pop() {
        if (top != -1) {
            return ptr[top--];
        }
        return -1;  
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

void generateFibonacci(int terms) {
    Furqan_lab3 s(terms);

    int a = 0, b = 1;

    s.push(a);
    if (terms > 1) {
        s.push(b);
    }

    for (int i = 2; i < terms; i++) {
        int next = a + b;
        s.push(next);
        a = b;
        b = next;
    }
    cout << "Fibonacci series in reverse order: ";
    while (!s.isempty()) {
        cout << s.pop()<< " ";
    }
    cout << endl;
}

int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
    generateFibonacci(terms);
    return 0;
}