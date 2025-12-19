#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n, vector<int>& f){ // fiboancci using memoisation

    if(n == 0 || n == 1){
        return n;
    }

    if(f[n] != -1){
        return f[n];
    }

    f[n] = fibonacci(n-1, f) + fibonacci(n-2, f);
    return f[n];
}

int fibTabulation(int n){ // using tabulation

    vector<int>fib(n+1, 0);
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < n; i++){
        fib[n] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}