#include<iostream>
using namespace std;

class Furqan_lab06{
    private:
        int *arr;
        int front;
        int rear;
        int size;
    public:
    Furqan_lab06(int s){
        size=s;
        arr=new int[size];
        front=-1;
        rear=-1;
    }  
    void enqueue(int value){
        if(rear==size-1){
            cout<<"queue is full"<<endl;
        }
        else{
            rear++;
            arr[rear]=value;
            if(front==-1){
                front=0;
            }
        }
    }
    void dequeue(){
        if(front==-1){
            cout<<"queue is empty"<<endl;
        }else{
            cout<<"Dequeued element is:"<<arr[front]<<endl;
            front++;
            if(front==rear){
                front=rear=-1;
            }           
        }
    }
    void display(){
        if(front==-1){
            cout<<"queue is empty"<<endl;
        }else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    void peek(){
        if(front==-1){
            cout<<"queue is empty"<<endl;
        }else{
            cout<<"Peek element is:"<<arr[front]<<endl;
        }
    }
    void isFull(){
        if(rear==size-1){
            cout<<"Queue is full"<<endl;
        }else{
            cout<<"Queue is not full"<<endl;
        }
    }
    void isEmpty(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }else{
            cout<<"Queue is not empty"<<endl;
        }
    }
};

int main(){
    Furqan_lab06 obj(5);
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);
    obj.display();
    obj.dequeue();
    obj.display();
    obj.peek();
    obj.isFull();
    obj.isEmpty();
    return 0;
}




