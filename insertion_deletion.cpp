// leetcode problem order of 1 insertion and deletion

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;

    
public:
    RandomizedCollection() {
        // Constructor initializes the data structures.
    }
    
    bool insert(int val) {
        bool alreadyExists = m.find(val) != m.end() && !m[val].empty();
        nums.push_back(val);
        m[val].insert(nums.size() - 1);
        return !alreadyExists;
    }
    bool remove(int val) {
    if (m.find(val) == m.end() || m[val].empty()) {
        return false;
    }
    
    int pos = *m[val].begin();
    int lastElement = nums.back();
    int lastPos = nums.size() - 1;
    
    if (val == lastElement) {
        // Special case: the element to be removed is the same as the last element
        nums.pop_back(); // Remove the last element from `nums`
        m[val].erase(lastPos);
        if (m[val].empty()) {
            m.erase(val);
        }
    } else {
        // General case: the element to be removed is not the last element
        nums[pos] = lastElement; // Move the last element to the position of `val`
        nums.pop_back(); // Remove the last element from `nums`
        
        m[lastElement].insert(pos);
        m[lastElement].erase(lastPos);
        
        m[val].erase(pos);
        if (m[val].empty()) {
            m.erase(val);
        }
    }
    
    return true;
}
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
    void display()
    {
        for(int i=0; i<nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main()
{
    RandomizedCollection* obj = new RandomizedCollection();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->insert(2);
    bool param_4 = obj->insert(4);
    bool param_5 = obj->insert(5);
    bool param_12 = obj->insert(1);
    bool param_13 = obj->insert(2);
    bool param_3 = obj->insert(3);
    obj->display();
    bool param_6 = obj->remove(3);
    bool param_7 = obj->remove(4);
    bool param_8 = obj->remove(5);
    bool param_9 = obj->remove(2);
    bool param_10 = obj->remove(1);
    obj->display();
    int param_11 = obj->getRandom();
    return 0;
}