class MinStack {
public:
    vector<int> valSt;
    vector<int> minSt;

    MinStack() {}
    
    void push(int val) {
        valSt.push_back(val);
        if (minSt.empty()) minSt.push_back(val);
        else               minSt.push_back(min(minSt.back(), val));
    }
    
    void pop() {
        valSt.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return valSt.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};
