class MinStack {
public:
    vector<int> nums;
    vector<int> mins;

    MinStack() {}
    
    void push(int val) {
        nums.push_back(val);
        if (mins.size() == 0) mins.push_back(val);
        else mins.push_back(min(mins[mins.size() - 1], val));
    }
    
    void pop() {
        nums.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return nums[nums.size() - 1];
    }
    
    int getMin() {
        return mins[mins.size() - 1];
    }
};
