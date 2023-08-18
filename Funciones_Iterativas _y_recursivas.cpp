// =========================================================
// File: activity.h
// Author: Arles Guevara Molina - A01710380
// Date: 15/08/2023
// =========================================================
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef ACTIVITY_H
#define ACTIVITY_H


// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// =================================================================
int sumIterativa(int n){
int Sum = 0, aux = n;
for (int i=0;i<n;i++){
Sum += aux;
aux -=1;
};
};
// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// =================================================================

int sumRecursiva(int n){
if(n==1){
return 1;
}
else{
    return n +sumRecursiva(n-1);
};
};
// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(1)
// =================================================================
int sumDirecta(int n){
return (n*(n+1))/2;
};

int main(){
cout<< sumIterativa(3)<<endl;
cout<< sumRecursiva(3)<<endl;
cout<< sumDirecta(3)<<endl;
return 0;
};
#endif /* ACTIVITY_H */