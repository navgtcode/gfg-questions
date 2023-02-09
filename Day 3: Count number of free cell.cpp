/* 
#########################################################################################################################################
Given a Matrix size N*N and an integer K. Initially, the matrix contains only 0. You are given K tasks and for each task, you are given 
two coordinates (r,c) [1 based index]. Where coordinates (r,c) denotes rth row and cth column of the given matrix.You have to perform each 
task sequentially in the given order. For each task, You have to put 1 in all rth row cells and all cth columns cells. After each task, You 
have to calculate the number of 0 present in the matrix and return it.

Example 1: Input: n = 3, k= 3
                  2 2
                  2 3
                  3 2
          Output: 4 2 1
          Explanation: After 1st Operation, all the 2nd row and all the 2nd column will be filled by 1. So remaning cell with value 0 will 
          be 4 After 2nd Operation, all the 2nd row and all the 3rd column will be filled by 1. So remaning cell with value 0 will be 2. After 
          3rd Operation cells having value 0 will be 1.
          
          
Example 2: Input: n = 2, k = 2
                  1 2
                  1 1
           Output: 1 0
           Explanation:  After 1st Operation, all the 1st row and all the 2nd column will be filled by 1. So remaning cell with value 0 will 
           be 1. After 2nd Operation, all the 1st row and all the 1st column will be filled by 1. So remaning cell with value 0 will be 0. 
           
           
           
Your Task: The task is to complete the function countZero(), which takes parameter n, size of the matrix, k no of operation and array arr[][], 
which denotes the position of the cells.You have to return an array that contains all the results.

Expected Time Complexity: O( k ).
Expected Auxiliary Space: O( n+n+k ).
#########################################################################################################################################

note : This question is asking you to perform a series of tasks on a matrix of size n x n, which initially contains only 0's. For each task, 
you are given two coordinates (r and c) and you have to put 1's in all the cells of the rth row and the cth column. After each task, you need 
to count the number of 0's remaining in the matrix and return it.

-----------------------------------------------------------------------------------------------------------------------------------------
Brute Force Approach 
---------------------------------------------------------------------------------------------------------------------------------------*/
class Solution {
  public: 
    vector<long long int> countZero(int n, int k, vector<vector<int>>& arr) {
        //github.com/Sugaax
        vector<long long int> ret;
        bool a[n][n];
        memset(a, false, sizeof a);

        for (int i = 0; i < k; i++) {
            int x = arr[i][0] - 1, y = arr[i][1] - 1;
            for (int j = 0; j < n; j++)
                a[j][y] = a[x][j] = true;

            int cnt = 0;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (!a[j][k])
                        cnt++;

            ret.push_back(cnt);
        }

        return ret;
    }
};


/*The time complexity of the brute force approach is O(n^3) because for each task, it loops through the entire matrix to update the values 
and count the number of zeros. This can be improved by using two arrays rows and cols to keep track of which rows and columns have been 
updated. For each task, we can set the corresponding entries in rows and cols to true and update the count of zeros accordingly. The time 
complexity of this optimized solution is O(n^2).

note: The memset function sets a block of memory to a particular value. In this case, the a array of n by n elements is set to false 
(or 0 in binary). The sizeof a operator returns the number of bytes in the a array, which is then passed as the third argument to memset 
to specify the number of bytes to set to false. This sets the entire a array to false, effectively marking all cells as unoccupied.


-----------------------------------------------------------------------------------------------------------------------------------------
Optimized Approach
-----------------------------------------------------------------------------------------------------------------------------------------
One approach could be to use two arrays, one to keep track of the number of ones in each row and another to keep track of the number of ones 
in each column. This way, we can keep track of the number of ones in each row and column in constant time, which would reduce the overall time 
complexity.

Another approach could be to use a bitset data structure, which allows us to keep track of multiple binary values in a compact and efficient
manner. By using a bitset, we can keep track of the number of ones in each row and column with a time complexity of O(k log n), which is much 
better than the brute-force approach.

Approach :
At first total no of free cells will be (N*N)

Step 1 : From the start keep track of the row index and col index filled till now and the count of rows and cols filled till now.
Step 2 : For every k , check if the respective row / col is filled or not , if already filled don't do anything.
Step 3 : If that's a new row or col then decrease the count of free cells using the formula explained above for both row and col differently
Step 4 : Mark the respective row index / col index as filled and increase the count of rows / cols filled till now
Step 5 : Return the ans array after the iteration is done.1

Time Complexity: O( k ).
Auxiliary Space: O( n+n+k ). */


class Solution{
  public:
  vector<long long int> countZero(int N, int K, vector<vector<int>>& arr){
        //github.com/Sugaax
        long freeCells = N * N;
        std::vector<bool> filledRows(N);
        std::vector<bool> filledCols(N);
        int rowCount = 0;
        int colCount = 0;
        std::vector<long long> ans(K);
        
        for (int i = 0; i < K; i++)
        {
            int row = arr[i][0];
            int col = arr[i][1];
            
            if (!filledRows[row - 1])
            {
                freeCells -= (N - colCount);
                filledRows[row - 1] = true;
                rowCount++;
            }
            
            if (!filledCols[col - 1])
            {
                freeCells -= (N - rowCount);
                filledCols[col - 1] = true;
                colCount++;
            }
            
            ans[i] = freeCells;
        }
        return ans;
  }
};

/*The code defines two vectors filledRows and filledCols to keep track of the rows and columns that have already been filled. These vectors
are initialized to have N elements and all the elements are initially set to false. In the for-loop, for each iteration, the row and column 
that is filled is determined by the values in arr[i][0] and arr[i][1] respectively. Then, the following two conditions are checked to see if 
the row and column being filled are already filled or not:

If the row is not filled, the number of remaining free cells is decremented by N - colCount (since all the columns will now be filled). The 
filledRows vector is updated to indicate that this row is now filled, and the row count is incremented.

If the column is not filled, the number of remaining free cells is decremented by N - rowCount (since all the rows will now be filled). The 
filledCols vector is updated to indicate that this column is now filled, and the column count is incremented.

Finally, the number of remaining free cells is stored in the ans vector and this value is returned after all iterations.


-----------------------------------------------------------------------------------------------------------------------------------------
Another Approach
---------------------------------------------------------------------------------------------------------------------------------------*/
 

class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long> ans;
        int rk = 0, ck = 0;
        long long temp = n*n;
        int row[100001] = {0};
        int col[100001] = {0};
        for(int i = 0;i<k;i++)
        {
            int r = arr[i][0], c = arr[i][1];
            if(row[r] == 1 && col[c] == 1)
            {
                ans.push_back(temp);
            }
            else if(row[r] == 1)
            {
                col[c] = 1;
                ck++;
                temp = temp - n + rk;
                ans.push_back(temp);
            }
            else if(col[c] == 1)
            {
                row[r] = 1;
                rk++;
                temp = temp - n + ck;
                ans.push_back(temp);
            }
            else
            {
                row[r] = 1;
                col[c] = 1;
                temp = temp - n + ck - n + rk + 1;
                ck++;
                rk++;
                ans.push_back(temp);
            }
        }
        return ans;
  }
};
