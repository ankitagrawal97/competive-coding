/*
 * Given a sorted array, A, with possibly duplicated elements, 
 * find the indices of the first and last occurrences of a target 
 * element, x. Return -1 if the target is not found.
 * */


#include <bits/stdc++.h>

using namespace std;

//function to calculate first occurance of the element
int first(int arr[], int low, int high, int key)
{
	int ans = -1;

	while(low <= high)
    {
    	int mid = low + (high - low)/2;
	
    	if(arr[mid]< key)
        {
			low = mid + 1;
		}
		else if (arr[mid]>key)
        {
			high = mid - 1;
		}
		else if (arr[mid]==key)
        {
			ans = mid;
			high = mid - 1;
		}
	}
		
	return ans;
	
}
//function to calculate last occurance of the element
int last(int arr[], int low, int high, int key)
{
    int ans = -1;
	
    while(low <= high)
    {
		int mid = low + (high - low)/2;
	
    	if(arr[mid]< key)
        {
			low = mid + 1;
		}
		else if (arr[mid]>key)
        {
			high = mid - 1;
		}
		else if (arr[mid]==key)
        {
			ans = mid;
			low = mid+1;
		}
	}
		
	return ans;

}

	
int main()
{
	int ans;
	int arr[] = {2,3,7,9,9,18,20}; //the array should be sorted as binary sort has been used to solve the problem.
    int len =  sizeof(arr)/sizeof(arr[0]);

    ans = first(arr,0,len-1, 9);
	cout<<"First(index) Occurance of 9: " << ans << endl;
	
    ans = last(arr,0, len-1, 9);
	cout<<"Last(index) Occurance of 9: " << ans << endl;
}