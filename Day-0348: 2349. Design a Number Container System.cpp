// 2349. Design a Number Container System (MEDIUM)
// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

class NumberContainers {
private:
    unordered_map<int, int> indexToNumber; // Maps index to number.
    map<int, set<int>> numberToIndices; // Maps number to a set of indices.

public:
    NumberContainers() {
        // Constructor initializes the data structures.
    }

    void change(int index, int number) {
        // If the index already has a number, remove the index from the old number's set.
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }

        // Update the index with the new number.
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        // Check if the number exists in the map and has indices.
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin(); // Return the smallest index.
        }
        return -1; // Number not found.
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
