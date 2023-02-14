# Merge Sort 
- [Notes](https://github.com/navgtcode/Sorting-Algorithms-/blob/main/Merge%20Sort.md) 
- [Gfg Question](https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

## Gfg Code
````
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays L and R
    int L[n1], R[n2];

    // Copy data from arr to L and R
    for(int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the two temporary arrays back into arr
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from L to arr
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements from R to arr
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
````

- _In the notes, a single temporary array ``brr`` was created to merge the two sub-arrays. However, in this code (gfg que.), two temporary arrays L and R are created to hold the left and right sub-arrays, respectively. This is because the two code snippets use different data structures to represent the input array. The first code snippet uses a ``std::vector<int>``, which is a dynamic array that can grow and shrink as needed. The second code snippet uses a static array ``int[]``, which has a fixed size and cannot be resized._

- _When using a static array, it is not possible to resize the array or create a new array of a different size. Therefore, in the merge function of the second code snippet, two temporary arrays L and R are created with sizes n1 and n2, respectively, to hold the left and right sub-arrays._

- _In contrast, in the notes code snippet, the ``std::vector<int>`` data structure can be resized as needed, so a single temporary vector ``brr`` is used to hold the merged sub-arrays._
