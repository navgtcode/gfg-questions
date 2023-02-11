## Minimum Days [</> POTD](https://practice.geeksforgeeks.org/problems/f4d22b1f9d62e8bee0ff84e9fa51dc66eb5005ec/1)

The problem is to find the minimum number of days required to replace some characters in a string such that no two consecutive characters are equal.
The condition "if S[i] is not '?', then S[i] is not equal to S[i+1]" states that if the character at index i in the string S is not a '?', then it 
should not be equal to the character at the next index i+1. In other words, no two consecutive characters in the string S should be equal. 

For example, if S = "abccd", then after some replacements, the string should look like "a?c?d" or "ab?cd" or "abc?d". In all these cases, 
no two consecutive characters are equal. The goal of the problem is to determine the minimum number of days required to make these replacements 
such that the condition "if S[i] is not '?', then S[i] is not equal to S[i+1]" is satisfied for all indices i (0 <= i < N-1)

The approach to solve this problem is to use a greedy algorithm. The idea is to iterate through the string S from the first position to the second-last 
position and replace the character in the current position with a '?' if its value is equal to the value of the next position. This ensures that after 
replacing the current position with a '?', it satisfies the condition S[i] != S[i+1]. 

````
int getMinimumDays(int N,string S, vector<int> &P) 
    {
        int ans = 0;
        int i =0;
        while(i<N-1)
        {
            if(S[i]!='?')
            {
                if(S[i]!=S[i+1])
                {
                    i++;
                    continue;
                }
                else
                {
                    S[P[ans]]='?';
                    ans++;
                }
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
  github.com/navgtcode
};
````

The code uses a greedy approach and tries to make changes in the string S in order to satisfy the above condition. The algorithm starts from the first character and iterates through the string S. If the current character is not equal to the next character and is not '?', then the algorithm moves to the next character. If the current character is equal to the next character and is not '?', then the algorithm replaces the next character with a '?' and increments the number of changes made. If the current character is '?', then the algorithm moves to the next character without making any changes. The algorithm continues until it has processed all the characters in the string S. The final answer is the number of changes made during the iteration.
