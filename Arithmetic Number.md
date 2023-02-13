## Arithmetic Number [</>POTD](https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1)
An arithmetic sequence is a sequence of numbers in which the difference between any two consecutive terms is constant. Here's an example to illustrate the concept of an
arithmetic sequence: 

Consider the sequence of numbers [2, 5, 8, 11, 14]. The difference between any two consecutive terms in this sequence is constant and equal to 3. 
This means that each term can be obtained by adding 3 to the previous term. For example, 5 = 2 + 3, 8 = 5 + 3, 11 = 8 + 3 and so on. 

Therefore, this sequence of numbers
is an example of an arithmetic sequence with a common difference of 3 and the first term is 2. The nth term of this sequence can be found using the formula: 
An = A + (n-1) * C, where A is the first term (2), C is the common difference (3), and n is the term number. For example, if n = 3, the third term of the sequence
would be 8. (A + (n-1) * C = 2 + (3-1) * 3 = 2 + 2 * 3 = 8).

Now back to question, to determine whether the integer 'B' is present in the arithmetic sequence, we can use the formula above to calculate the value of 'An' for various 
values of 'n' and check if it is equal to 'B'. If there is a value of 'n' for which 'An' equals 'B', then 'B' is present in the arithmetic sequence and we return 1. 
If there is no value of 'n' for which 'An' equals 'B', then 'B' is not present in the sequence and we return 0

The code first checks if the common difference 'C' is equal to zero. If it is, then it returns 1. if 'A' and 'B' are equal, and 0 otherwise. This is because if 'C' is 
equal to zero, then the sequence will consist of only one term 'A'.If 'C' is not equal to zero. 

then the code calculates the number of terms in the sequence using the formula 'N= (B-A)/C + 1'. This is done to find the position of the term 'B' in the sequence. 
The code then checks if 'B' is equal to A + (N-1)*C and 'N' is positive. If both the conditions are true, well then 'B' exists in the sequence and the code
returns 1. If not, the code returns 0

#### code
````
class Solution{
public:
    int inSequence(int A, int B, int C){
      if(C==0){
        if(A==B)
            return 1;
         else
           return 0;
       } 
    
    int N= (B-A)/C + 1;
    
    if(B== A+(N-1)*C && N>0)
        return 1;
    else
        return 0;
         
   }
};
````

The condition N > 0 is used to ensure that B is not the first term in the arithmetic sequence. In other words, it ensures that there is at least one term in the 
sequence before B. This is because N is defined as the number of terms in the arithmetic sequence between A and B, including B.

For example, if A = 0, B = 3, and C = 2, then N = 2. This means that there are two terms in the sequence between A and B, 0 and 2. Since B = 2, it is a part of the 
sequence, and the function returns 1. However, if N <= 0, then there are no terms in the sequence between A and B, and B is not a part of the sequence.
In this case, the function returns 0.

 if A = 3, B = 0, and C = 2. In this case, N = -1. Since N is less than or equal to zero, there are no terms in the sequence 
 between A and B, and B is not a part of the sequence. In this case, the function would return 0.
