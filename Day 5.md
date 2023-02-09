## Balloon Everywhere
`github.com/navgtcode`

In this problem, we are given a string of lowercase letters and we need to form as many instances of the word "balloon" as possible using the characters of the given string. The function should return the maximum number of instances that can be formed.

### Brute Force Approach

The brute force solution would be to loop through the string and check if the current character is 'b'. If it is 'b', we then loop through the rest of the string and keep track of the count of each character 'a', 'l', 'o', 'n'. Finally, we calculate the minimum count of these characters and use it as the number of instances of "balloon" that can be formed. The maximum of all such instances will be our answer. this solution has a time complexity of O(n^2)

````
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxInstance(string s){
        int ans = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'b') {
                int count_a = 0, count_l = 0, count_o = 0, count_n = 0;
                for (int j = i + 1; j < len; j++) {
                    if (s[j] == 'a') {
                        count_a++;
                    }
                    else if (s[j] == 'l') {
                        count_l++;
                    }
                    else if (s[j] == 'o') {
                        count_o++;
                    }
                    else if (s[j] == 'n') {
                        count_n++;
                    }
                }
                int num_balloon = min(count_a, count_n);
                num_balloon = min(num_balloon, count_l / 2);
                num_balloon = min(num_balloon, count_o / 2);
                ans = max(ans, num_balloon);
            }
        }
        return ans;
    }
};

````
### Optimized Solution 
The optimized solution would be to use a hash map to keep track of the frequency of each character in the string. Then, we simply calculate the minimum frequency of 'b', 'a', 'l' divided by 2, 'o' divided by 2, and 'n'. This minimum frequency will be our answer. This solution has a time complexity of O(n), which is much more efficient for large inputs
````
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxInstance(string s){
        int ans = 0;
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        ans = min(freq['b'], min(freq['a'], min(freq['l']/2, min(freq['o']/2, freq['n']))));
        return ans;
    }
};
````
