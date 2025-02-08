class NumberContainers {
private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
    unordered_map<int, int> indexToNumber;
public:
    NumberContainers() { }
    
    void change(int index, int number) {
        indexToNumber[index] = number;
        numberToIndices[number].push(index);
    }
    
    int find(int number) {
        if(numberToIndices.find(number) == numberToIndices.end()) {
            return -1;
        }

        auto& minHeap = numberToIndices[number];

        while(!minHeap.empty()) {
            int index = minHeap.top();

            if(indexToNumber[index] == number) {
                return index;
            }

            minHeap.pop();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */