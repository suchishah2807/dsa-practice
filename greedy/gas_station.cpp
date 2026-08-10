#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int n1 = gas.size();
    for(int i = 0; i < n1; i++){
        gas.push_back(gas[i]); // cyclic vector
    }
    int n2 = cost.size();
    for(int i = 0; i < n2; i++){
        cost.push_back(cost[i]);
    }
    
    int ans; 

    for(int j = 0; j < n; j++){ // testing for every station as starting point
        int fuel = 0;
        bool completed = true;
        for(int i = j; i < j+n; i++){ // going around whole circuit
            fuel += gas[i] - cost[i];
            if(fuel < 0){ completed = false; break; }
        }
        if(completed) return j;
    }
    return -1;
}

int canCompleteCircuit_greedy(vector<int>& gas, vector<int>& cost) {
    int total_fuel = 0;
    int fuel = 0;
    int start = 0;
    for(int i =0; i<gas.size(); i++){
        fuel += gas[i]-cost[i];
        total_fuel += gas[i]-cost[i];
        if(fuel<0){
            start = i+1;
            fuel = 0;
        }
    }
    if(total_fuel<0) return -1;
    return start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}