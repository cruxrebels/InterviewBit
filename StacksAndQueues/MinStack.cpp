/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1

https://www.interviewbit.com/problems/min-stack/
*/

vector<int> myStack;
int flag;
int minEle;

MinStack::MinStack() {
    myStack.clear(); 
    flag = false;
    minEle = INT_MAX;
}

void MinStack::push(int x) {
    myStack.push_back(x);
    minEle = min(minEle, x);
}

void MinStack::pop() {
    if(!myStack.empty())
    {
        if(myStack[myStack.size()-1] == minEle)
            flag = true;
        myStack.pop_back();
    }
}

int MinStack::top() {
    if (myStack.empty())
        return -1;
    return myStack[myStack.size()-1];
}   

int MinStack::getMin() {
    if (myStack.empty())
        return -1;
    if (flag)
    {
        minEle = INT_MAX;
        for (auto i = 0; i<myStack.size(); ++i)
            minEle = min(minEle, myStack[i]);
    }
    return minEle;
}
