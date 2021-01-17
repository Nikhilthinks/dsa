#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;

    public:
        int a[MAX]; //maximum size of stack
        Stack() { top = -1; }
        int pop();
        bool push(int x);
        int peek();
        bool isEmpty();
        int stack_height();
        int peek_any(int adrs);

};

//push
bool Stack::push(int x) { // :: is scope resolution operator
    if(top >= (MAX - 1)) {
        //cout << "Stack Overflow\n" << endl;
        return false;
    }
    else {
        a[++top] = x;
        //cout << x << " Pushed into stack\n" <<endl;
        return true;
    }
}
//pop
int Stack::pop() {
    if(top < 0) {
        //cout << "Stack Underflow\n" << endl;
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
//isEmpty
bool Stack::isEmpty() {
if (top < 0) {
    //cout << "Stack is empty\n" << endl;
    return false;
}
else  {
    //cout << "Stack is not empty\n" << endl;
    return true;
}
}
//peek
int Stack::peek() {
    if(top<0) {
        //cout << "Stack is Empty\n" <<endl;
        return 0;
    }
    else {
        int x = a[top];
        //cout << "The top most value in stack is: " << x <<endl;
        return x;
    }
}

//peek any element of stack - illegal - but that's how mafia works.
int Stack::peek_any(int adrs) {
    if (top > 0 && adrs < top+1) {
        //cout << a[adrs] << endl;
        return a[adrs];
    }
    else {
        //cout << "Stack Underflow" << endl;
        return 0;
    }
}


//stack height
int Stack::stack_height() {
    //cout << top+1 << endl;
    return top+1;
}

int main () {
    class Stack s;
    // s.isEmpty();
    // s.push(10);
    // s.isEmpty();
    // s.peek();
    // s.push(18);
    // cout << s.pop() << " Popped from Stack\n";
    // s.peek();
    // s.isEmpty();
    s.push('(');
    s.push('(');
    s.push('(');
    s.push(')');
    s.push(')');
    s.push(')');
    //s.peek();
   class Stack s2; //Creating a new stack to add opening brackets in it.
//    cout<< s.peek_any(3)<<endl;
int stack_height = s.stack_height();
 for( int i = 0 ; i < stack_height ; i++) {
     if(s.peek_any(i) == '(' || s.peek_any(i) == '[' || s.peek_any(i) == '{') {
         s2.push(s.peek_any(i));
         continue;
     }
     if( (s.peek_any(i) == '}' && s2.peek() != '{') || ( s.peek_any(i) == ')' && s2.peek() != '(') || ( s.peek_any(i) == ']' && s2.peek() != '[')){

         cout << "Not a valid pair" << endl;
         s2.pop();
         continue;
     }
 }
 // now checking for closing brackets
//    s2.peek();
    return 0;
}