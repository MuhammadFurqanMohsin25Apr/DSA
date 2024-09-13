#include <iostream>
using namespace std;

class Furqan_lab3 {
private:
    char* ptr;
    int csize;
    int top;
public:
    Furqan_lab3(int c) {
        csize = c;
        ptr = new char[csize];
        top = -1;
    }
    ~Furqan_lab3() {
        delete[] ptr;
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
    void push(char x) {
        if (top == csize - 1) {
            resize();
        }
        ptr[++top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        } else {
            --top;
        }
    }
    char peek() {
        return (top == -1) ? '\0' : ptr[top];
    }
    string getString() {
        string result = "";
        for (int i = 0; i <= top; i++) {
            result += ptr[i];
        }
        return result;
    }
};

string processString( string str, Furqan_lab3 stack) {
    for (char ch : str) {
        if (ch == '#') {
            if (!stack.isempty()) {
                stack.pop();
            }
        } else {
            stack.push(ch);
        }
    }
    return stack.getString();
}

bool backspaceCompare(string s, string t) {
    Furqan_lab3 stack1(10); 
    Furqan_lab3 stack2(10);

    return processString(s, stack1) == processString(t, stack2);
}

int main() {
    string s1 = "ab#c";
    string s2 = "ad#c";

    if (backspaceCompare(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}