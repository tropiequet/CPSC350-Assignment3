/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 3

This is my GenStack template class.
*/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>

class GenStack{

public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); //destructor

  void push(T data);
  char pop();
  char peek();

  bool isFull();
  bool isEmpty();
  int getSize();

  int top;
  int mSize;

  T *myArray;

};

template <class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  mSize = 128;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

template <class T>
void GenStack<T>::push(T data){
  if (isFull()){
    T *tempArray = new T[mSize*2];
    for (int i = 0; i < mSize; ++i){
      tempArray[i] = myArray[i];
    }
    myArray = tempArray;
  }
      myArray[++top] = data;
}


template <class T>
char GenStack<T>::pop(){
  if (isEmpty()){
    cout << "Error! Stack is empty!" << endl;
    return '\0';
  }
  return myArray[top--];
}

template <class T>
char GenStack<T>::peek(){
  if (isEmpty()){
    cout << "Error! Stack is empty!" << endl;
    return '\0';
  }
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize - 1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize(){
  return (top + 1);
}
