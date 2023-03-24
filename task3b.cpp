#include<iostream> 			//to utilise standard input and output functions
#include "MarsProject.h"
#include<climits>
using namespace std;
//Function to calculate the maximum sum of the contiguous subarray
 void getMaxSum(int a[], int length)
{
    int maxValue = INT_MIN, curSum = 0,
       startIndex =0, endIndex = 0, st=0;
 
    for (int i=0; i< length; i++ )
    {
        curSum+= a[i];
        if (maxValue < curSum)		//compare the maximum sum with the current element
        {
            maxValue = curSum;		//this variable holds the maximum sum calculated so far
            startIndex = st;		//this variable holds the starting index of the maximum sum 					 contiguous subarray
 
            endIndex= i;			//this variable holds the ending index of the maximum sum 						contiguous subarray
 
        }
 
        if (curSum < 0)
        {
            curSum = 0;
            st = i + 1;
        }
    }
    cout << startIndex+1<<" "<< endIndex+1 <<" "<< maxValue;
}
 
//Main program to take the inputs and call the function getMaxSum 
int task3b()
{
int length;
cin>>length;				 		// Read length of contiguous input array
int A[length];						//declaration of array of size 'length'
for (int i=0;i<length;i++)
{
cin>>A[i];						// Reading of array elements from console
}
getMaxSum(A, length); 				// make a call to the function getMaxSum to calculate the maximum sum contiguous subarray
 
return 0;
}
