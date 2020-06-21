/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int dis = 0;
        int T = 0;
        int B = matrix.size()-1;
        if(matrix.size()==0){
            return res;
        }
        int L = 0;
        int R = matrix[0].size()-1;
        
        
        
        while(T<=B && L<=R){
            if(dis == 0){
                for(int i = L; i<=R;i++){
                    res.push_back(matrix[L][i]);
                }
                T++;
            }else if(dis == 1){
                for(int i = T; i<=B;i++){
                    res.push_back(matrix[i][R]);
                }
                R--;
            }else if(dis == 2){
                for(int i = R; i>=L;i--){
                    res.push_back(matrix[B][i]);
                }
                B--;
            }else if(dis == 3){
                for(int i = B; i>=T;i--){
                    res.push_back(matrix[i][L]);
                }
                L++;
            }
            dis = (dis+1)%4;
            
        }
    return res;
    }
};