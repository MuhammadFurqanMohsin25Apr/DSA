#include <iostream>
#include <string>
using namespace std;
class Furqan_lab3{
    private:
    char *ptr;
    int csize;
    int top;
    public:
    Furqan_lab3(int c){
        csize=c;
        ptr=new char[csize];
        top=-1;
    }
    ~Furqan_lab3(){
        delete []ptr;
    }
    void resize() {
        int newSize = csize * 2; 
        char* newPtr = new char[newSize];
        
        for (int i = 0; i < csize; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr; 
        ptr = newPtr;
        csize = newSize;
        cout << "Stack resized to " << newSize << endl;
    }
    bool isempty() {
        return top == -1;
    }
    void push(char x){
        if(top==csize-1){
            resize();
        }
        ptr[++top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is underflow"<<endl;
            
        }else{
        cout<<ptr[top--];}
    }
    void isPalindrome(){
        int i=0;
        int j=top;
        while(i<j){
            if(ptr[i++]!=ptr[j--]){
                cout<<" is not palindrome"<<endl;
                return;
            }
        }
        cout<<" is palindrome"<<endl;
    }
};
int main(){
    string s;
    cout<<"Enter the string ";
    getline(cin,s);
    Furqan_lab3 a(s.length());
    for(auto i:s){
        a.push(i);
    }
    a.isPalindrome();
    return 0;
}