/*Problem Statement
There exists a staircase with N steps, and you can climb up either 1 
  or 2 steps at a time. Given N, write a function that returns the 
  number of unique ways you can climb the staircase. 
  The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
 
 -Generalization of the Problem
 How to count the number of ways if the person can climb up to m stairs
 for a given value m.For example, if m is 4, the person can climb 1 stair
 or 2 stairs or 3 stairs or 4 stairs at a time.
*/
#include <bits/stdc++.h>

using namespace std;

//generalizing the function steps()
int genstep(int n,int m)
{
	int result = 0;

	if (n <= 1)
    {
		return n;
	}

	for(int i = 1 ; i<=n && i<=m;i++)
    {
		result = result + genstep(n-i,m);
	}
	return result;
	
}

//basically find (N+1)th ficonacci number
int steps(int n)
{
	if(n == 1)
    {
		return 1;
	}

	if (n == 0)
    {
		return 0;
	}
    
	return steps(n-1)+steps(n-2);
}
int main()
{
	int k = 10;
	cout<< steps(k+1)<<"\n";
	
	cout<<"-------------\n";
	
	int m = 4;
	cout<< genstep(k+1,m);
	
	return 0;
}
