// 1381. Design a Stack With Increment Operation (MEDIUM)
// https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30


class CustomStack {
public:

    vector<int> arr;
    int n = 0, size;
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        size = maxSize;
    }
    
    void push(int x) {
        if(n == size) return;
        arr[n++] = x;
    }
    
    int pop() {
        if(n == 0) return -1;
        int num = arr[n-1];
        n--;
        return num;
    }
    
    void increment(int k, int val) {
        int len = n > k ? k : n;
        for(int i=0;i<len;i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
