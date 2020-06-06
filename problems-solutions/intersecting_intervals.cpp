/*Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
*  The intersection of two closed intervals is a set of real numbers that is either empty, or can be 
* represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects,
and not arrays or lists.

Algorithm
*[s1,e1], [s2,e2]
 * for intersection s2<=e1 and s1<=e2
 * output= [max(s1,s2),min(e1,e2)]
 * for iteration in the list 
 * if A.second(i) > B.second(i) then Bptr++ else Aptr++*
 * */
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int sizeA = A.size();
        int sizeB = B.size();
        int aptr = 0;
        int bptr = 0;
		vector<vector<int>> res;
        vector<vector<int>> temp(2);

        while (Aptr < sizeA && j < sizeB)
        {	
			if(B[bptr][0]<=A[aptr][1] && A[aptr][0]<=B[bptr][1])
			{
					temp[0]=max(A[aptr][0],B[bptr][0]);
					temp[1]=min(A[aptr][1],B[bptr][1]);
					res.push_back(temp);
			}
					if(A[aptr][1]>B[bptr][1])
					{
						bptr++;
					}else{
						aptr++;
					}
		}
        return res;
    }
};