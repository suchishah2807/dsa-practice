#include <bits/stdc++.h>
using namespace std;
/*
The Euler Path: Think of recursion as a journey down into the stack and then back out. You visit every node three times:
Pre-area (Before calls): When you first enter the function.
Left-call
In-area (Between calls): When you return from the first recursive call but before making the second.
Right-call
Post-area (After calls): After both recursive calls are finished, before the function returns to the caller.
Analyzing the "Print Zig-Zag" Function
To visualize the process, the instructor writes a recursive function pzz(n) that prints values based on the following pattern:

Print n (Pre-area): Executed when you enter the function.
Call pzz(n-1): The first recursive call (Left call).
Print n (In-area): Executed after the first call returns.
Call pzz(n-1): The second recursive call (Right call).
Print n (Post-area): Executed after the second call returns.

Recursive Depth: When you call pzz(n), the function doesn't just run once; it branches out. For n=2, the function calls itself for n=1, which calls itself for n=0 (the base case).

*/
void pzz(int n){
    if(n==0) return;
    cout<<"Pre: "<<n<<endl; // pre area. before left and right call
    pzz(n-1); // left call
    cout<<"In: "<<n<<endl; // in area. in between left and right call
    pzz(n-1); // right call
    cout<<"Post: "<<n<<endl; // post area. after left and right call
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}