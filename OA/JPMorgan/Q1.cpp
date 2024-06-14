#include <iostream>
using namespace std;

int maximumIndex(int N, int B)
{
    int i = 0, j = 1;
    int cnt = 0;
 
    // Stores sum of first N
    // natural numbers
    int sum = N * (N + 1) / 2;
 
    bool flag = false;
 
    while (cnt < N) {
 
        // Increment i with j
        i += j;
 
        // Increment j with 1
        j++;
 
        // Increment count
        cnt++;
 
        // If i points to B
        if (i == B) {
 
            // Break
            flag = true;
            break;
        }
    }
 
    // Print the pointer index
    if (!flag) {
        cout << sum;
    }
    else
        cout << sum - 1;
}
 
// Driver Code
int main()
{
    // Given value of N & B
    int N = 4, B = 6;
 
    // Function call to find maximum
    // index the pointer can reach
    maximumIndex(N, B);
 
    return 0;
}