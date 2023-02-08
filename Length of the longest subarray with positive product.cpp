/* 
#########################################################################################################################################
Given an array arr[] consisting of n integers, find the length of the longest subarray with positive (non zero) product.

Example 1: Input: arr[] ={0, 1, -2, -3, -4} 
           Output: 3
           Explanation: The longest subarray with positive product is: {1, -2, -3}.Therefore, the required length is 3.
 
Example 2: Input: arr[]={-1, -2, 0, 1, 2}
           Output: 2
           Explanation: The longest subarray with positive products are: {-1, -2}, {1, 2}. Therefore, the required length is 2.
 

Your Task: This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just 
need to complete the function maxLength() that takes array arr[], and an integer n as parameters and return the length of the longest 
subarray where the product of all of its element is positive. 

 
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
#########################################################################################################################################




-----------------------------------------------------------------------------------------------------------------------------------------
Brute Force Approach 
-----------------------------------------------------------------------------------------------------------------------------------------
The brute force approach to solve this problem starts by considering all possible subarrays of the input array "arr". To do this, we use 
two nested loops. The outer loop iterates over the starting index of the subarray, and the inner loop iterates over the ending index of the 
subarray. For each subarray, the product of its elements is calculated. If the product of the elements is positive (i.e., greater than zero), 
we calculate the length of the subarray by subtracting the starting index from the ending index and adding 1. If the length of the subarray 
is greater than the current maximum length, we update the maximum length to the length of the subarray. This process continues until all 
possible subarrays have been considered. Finally, the maximum length is returned as the result. // TC o(n^2)
---------------------------------------------------------------------------------------------------------------------------------------*/
class Solution {
    public: //github.com/Sugaax
        int maxLength(vector<int> &arr,int n){
            int maxlength=0;
            for(int i=0;i<n;i++){
                int product=1;
                for(int j=i;j<n;j++){
                    product=product*arr[j];
                    if(p>0)
                    maxlength=max(maxlength,j-i+1);
                }
            }
            return maxlength;
        }
};





/*---------------------------------------------------------------------------------------------------------------------------------------
Optimized Solution 
---------------------------------------------------------------------------------------------------------------------------------------*/
class Solution {
    public: //github.com/Sugaax
        int maxLength(vector<int> &arr,int n){
            int maxLen = 0, negCount = 0, prevZero = -1, firstNeg = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < 0)
                {
                    negCount++;
                    if (firstNeg == -1)
                        firstNeg = i;
                }
                if (arr[i] == 0)
                {
                    firstNeg = -1;
                    negCount = 0;
                    prevZero = i;
                }
                else 
                {
                    if (negCount % 2 == 0)
                        maxLen = max(maxLen,i - prevZero);
                    else 
                        maxLen = max(maxLen,i - firstNeg);
                }
            }
            return maxLen;
        }
};





