/*
Explanation: It would likely take way too long to calculate the entire string of ABC's and then return the substring from there. Instead, we will
create a new string and add each individual character from positions l to r. We can actually determine what the letter is supposed to be using just
the position and the k level. We're going to use recursion. As we know, the string S_k comprises of A then S_k-1 then B then S_k-1 then C. Since we are
dealing with multiple test cases at once, I wanted to just calculate the length of all possible S_k strings, which would then be accessible in O(1) time.
To find the character that we want to append to our answer substring, we're going to use recursion. We'll check whether the position fits into which spot: either
at a guaranteed A, somewhere between A and B, at a guaranteed B, somewhere between B and C, or at a guaranteed C. Eventually, we'll end up recursing to k = 1,
which is a base case and we'll directly return the letter based on the position. Time complexity is O((r - l + 1) * k). r - l + 1 comes from the substring function, which
runs for every character we want to get. The k comes from the recursive findChar function where we have a maximum depth of k.

*/

#include <iostream>
#include <string>

using namespace std;

string ABC = "ABC";

long long length[51];

char findChar(int k, long long pos) {
    if (k == 1) {
        return ABC[pos - 1];
    }
    
    long long prev = length[k - 1];

    if (pos == 1) {
        return 'A';
    } else if (pos <= prev + 1) {
        long long new_pos = pos - 1;
        return findChar(k - 1, new_pos);
    } else if (pos == prev + 2) {
        return 'B';
    } else if (pos <= 2 * prev + 2) {
        long long new_pos = pos - (prev + 2);
        return findChar(k - 1, new_pos);
    } else {
        return 'C';
    }
}

string substring(int k, long long l, long long r) {
    string answer = "";
    for (long long i = l; i <= r; i++) {
        answer += findChar(k, i);
    }
    return answer;
}

int main() {
    length[1] = 3;
    for (int i = 2; i <= 50; i++) {
        length[i] = 2 * length[i - 1] + 3;
    }

    int t, k;
    long long l, r;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k >> l >> r;
        cout << substring(k, l, r) << endl;
    }
    return 0;
}