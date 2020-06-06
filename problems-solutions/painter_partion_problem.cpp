/*Problem Statement:
 * We have to paint n boards of length {A1, A2, .. An}. 
 * There are k painters available and each takes 1 unit time 
 * to paint 1 unit of board. The problem is to find the minimum time 
 * to get this job done under the constraints that any painter will 
 * only paint continuous sections of boards, say board {2, 3, 4} or
 * only board {1} or nothing but not board {2, 4, 5}.
 */

#include <bits/stdc++.h>

using namespace std;

//function to find maximum element in array
int maxinarr(int arr[],int len)
{
	
	int maxi = INT_MIN;
	
	for(int i = 0 ; i< len; i++)
	{
		maxi = max(maxi,arr[i]);
	}
	
	return maxi;

}


//function to find sum of all elements in array	
int sumall(int arr[], int len)
{
	
	int sum = 0;
	
	for(int i = 0; i< len; i++)
	{
		sum = sum + arr[i];
	}
	
	return sum;
}

//function to find number of painters required	
int numberofpaintersreq(int arr[],int arrlen, int maxlen)
{
	
	int sum = 0;
	int noofpainters = 1;
	
	for (int i = 0 ; i< arrlen ; i++)
	{
	
		sum = sum + arr[i];
	
		if (sum >maxlen)
		{
			noofpainters++;
			sum = arr[i];
		}
		
	}
	
	return noofpainters;
}

//main function to solve the problem	
int solve(int arr[], int arrlen, int k)
{
	
	int low = maxinarr(arr,arrlen);//largest val in arr
	int high = sumall(arr,arrlen);//sum of all val in arr
	
	while(low<=high)
	{
		
		int mid = low + (high - low)/2;
		int numberofpainters = numberofpaintersreq(arr,arrlen,mid);
		
		if(numberofpainters <= k)
		{
			high = mid-1;
		}else
		{
				low = mid +1;
		}
	}
	
	return low;
}

int main()
{
	int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	int k = 3;//number of painters given.
	cout<< solve(arr,arrlen, k);
	return 0;
}
