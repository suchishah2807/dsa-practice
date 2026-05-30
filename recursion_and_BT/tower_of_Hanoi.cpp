#include <bits/stdc++.h>
using namespace std;
// printing instructions for tower of hanoi:
/* we hv 3 towers, one of the towers has disks in increasing size(top to bottom) we need to move it to tower 2 to get in same increasing order
    rules:
    1. move only 1 disk at a time
    2. u can only place a disk on a disk on bigger disk
    3. u can only move disk at top*/
/* for 3 disks expectations are:toh(3,A,B,C)
    tower A,B,C disk 1,2,3
    1 in B
    2 in C
    1 in C
    3 in B
    1 in A
    2 in B
    1 in B 
    now assume for 2 disks and relate it for 3 disks: toh(2,A,B,C)
    tower A - 3 B - 1,2, C
    1 in A
    2 in C
    1 in C
    3 in B
    1 in A
    2 in B
    1 in B
    but we actually use 2(A,C,B) because we want to move 3rd disk from A to B so its better if 2 disks are in C rather than in B
*/
void toh(int n, char A, char B, char C) {
    if (n == 0) return;
    toh(n-1, A, C, B);
    cout << n << " [ " << A << " tower -> " << B << " tower ]" << endl;
    toh(n-1, C, B, A);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char A='A';
    char B='B';
    char C='C';
    toh(3, A, B, C);  // n disks, from rod 1, to rod 2, using rod 3
    return 0;
}