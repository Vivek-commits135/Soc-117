#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> D;
        vector<int> res;
        for(int i=0;i<k;i++) {
            while(!D.empty()&&nums[D.back()]<=nums[i]) D.pop_back();
            D.push_back(i);
        }
        res.push_back(nums[D.front()]);
        for(int i=k;i<nums.size();i++) {
            while(!D.empty()&&nums[D.back()]<=nums[i]) D.pop_back();
            D.push_back(i);
            if(i-k==D.front()) D.pop_front();
            res.push_back(nums[D.front()]);
        }
        return res;
    }
};
