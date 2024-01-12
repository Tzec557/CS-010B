#include "minFunc.h"
/*
Implement the following global function using a recursive algorithm 
to find and return the location of the smallest value in an array of integers. 
If the size passed in is 0, return nullptr.*/
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    }
    if(arrSize == 1){
        return &arr[0];
    }
    
    const int * mins = min(arr, arrSize - 1);
    if(* mins < arr[arrSize - 1]){
        return mins;
    }
    else{
        return &arr[arrSize - 1];
    }

}