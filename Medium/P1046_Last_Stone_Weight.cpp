// Priority_Queue:
int lastStoneWeight(vector<int>& stones) {
    int s1 = 0;
    int s2 = 0;
    priority_queue<int> pq;
    for (auto s : stones) {
        pq.push(s);
    }
    while (pq.size() != 1) {
        s1 = pq.top();
        pq.pop();
        s2 = pq.top();
        pq.pop();

        pq.push(s1 - s2);
    }

    return pq.top();
}
// Make_Heap:
int lastStoneWeight(vector<int>& stones) {
    int s1 = 0;
    int s2 = 0;
    make_heap(stones.begin(), stones.end());
    while (stones.size() != 1) {
        s1 = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();

        s2 = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();

        stones.push_back(s1 - s2);
        push_heap(stones.begin(), stones.end());
    }

    return stones.front();
}