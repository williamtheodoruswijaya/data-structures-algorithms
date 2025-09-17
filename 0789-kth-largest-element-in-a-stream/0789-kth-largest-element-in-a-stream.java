class KthLargest {
    private int k;
    private PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    
    public KthLargest(int k, int[] nums) {
        super();
        this.k = k;
        for (int num : nums) {
            this.minHeap.add(Integer.valueOf(num));
        }
        
        while (this.minHeap.size() > k) this.minHeap.poll();
    }
    
    public int add(int val) {
        this.minHeap.add(val);
        if (this.minHeap.size() > k) this.minHeap.poll();

        return this.minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */