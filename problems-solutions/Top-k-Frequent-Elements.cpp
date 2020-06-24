/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.

*/
#include <bits/stdc++.h>

using namespace std;

vector<int> topkfrequent(vector<int> nums, int k){
    unordered_map<int,int> mymap;
    vector<int> ans;
    for ( auto c : nums)
    {
        mymap[c]++;
    }
    priority_queue<pair<int,int>> mypq;
    for ( auto c = mymap.begin();c!=mymap.end();c++)
    {
        mypq.push(make_pair(c->second,c->first)); //second is frequency , first is value;
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(mypq.top().second);
        mypq.pop();
    }
    
    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topkfrequent(nums,k);
    for(auto c : ans){
        cout<<c<<" ";
    }
}