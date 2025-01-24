class MyQueue {
    stack<int> set;
    stack<int> get;
    void move(stack<int>& s1, stack<int>& s2)
    {
        if(s1.empty())
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        move(set, get);
        set.push(x);
    }
    
    int pop() {
        move(get, set);
        int element = get.top();
        get.pop();
        return element;
    }
    
    int peek() {
        move(get, set);
        return get.top();
    }
    
    bool empty() {
        return set.empty() && get.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */