class MinStack {
    public ArrayList<Integer> stack;
    public ArrayList<Integer> minStack;

    public MinStack() {
        this.stack = new ArrayList<>();
        this.minStack = new ArrayList<>();;
    }
    
    public void push(int val) {
        this.stack.add(Integer.valueOf(val));

        if (this.minStack.isEmpty()) {
            this.minStack.add(Integer.valueOf(val));
        } else if (val <= this.minStack.get(this.minStack.size() - 1)) {
            this.minStack.add(Integer.valueOf(val));
        } 
    }
    
    public void pop() {
        if (this.minStack.get(this.minStack.size() - 1).equals(this.stack.get(this.stack.size() - 1))) {
            this.minStack.remove(this.minStack.size() - 1);
        }
        this.stack.remove(this.stack.size() - 1);
    }
    
    public int top() {
        return this.stack.get(this.stack.size() - 1);
    }
    
    public int getMin() {
        return this.minStack.get(this.minStack.size() - 1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */