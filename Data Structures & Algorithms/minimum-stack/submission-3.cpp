class MinStack {
public:
    vector<int> nums;
    vector<int> mins;
    int count;

    MinStack() {
        count = 0;
    }
    
    void push(int val) {
        nums.push_back(val);
        if (count == 0) mins.push_back(val);
        else mins.push_back(min(mins[count - 1], val));
        count++;
    }
    
    void pop() {
        nums.pop_back();
        mins.pop_back();
        count--;
    }
    
    int top() {
        return nums[count - 1];
    }
    
    int getMin() {
        return mins[count - 1];
    }
};
