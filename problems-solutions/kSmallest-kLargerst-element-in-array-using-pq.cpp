/*K’th Smallest/Largest Element in Unsorted Array*/

#include <bits/stdc++.h>

using namespace std;

int findkLargest(vector<int> arr, int k){
    priority_queue<int> mympq;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = -1 * arr[i];
    }
    
    for (int i = 0; i < k; i++)
    {
        mympq.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if(arr[i]<mympq.top()){
            mympq.pop();
            mympq.push(arr[i]);
        }
    }
    
    return -1* mympq.top();
}
int findkSmallest(vector<int> arr, int k){
    priority_queue<int> mympq;
    
    
    for (int i = 0; i < k; i++)
    {
        mympq.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if(arr[i]<mympq.top()){
            mympq.pop();
            mympq.push(arr[i]);
        }
    }
    
    return mympq.top();
}
int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout<<findkSmallest(arr,k)<<endl;
    cout<<findkLargest(arr,k);
}