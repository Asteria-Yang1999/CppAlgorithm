#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class MonotionicQueue {
private:
    deque<int> q;

public:
    void push(int n) {
        while (!q.empty() && q.back() < n) {
            q.pop_back();
        }
        q.push_back(n);
    }

    void pop(int n) {
        if (n == q.front()) {
            q.pop_front();
        }
    }

    int getMax() {
        return q.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotionicQueue mq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < k - 1) {
            mq.push(nums[i]);
        } else {
            mq.push(nums[i]);
            res.push_back(mq.getMax());
            mq.pop(nums[i - k + 1]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    vector<int> res = maxSlidingWindow(nums, 4);
    for (auto i : res) cout << i << " ";
    return 0;
}
