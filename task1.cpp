#include <bits/stdc++.h>		//to utilise standard input and output functions
#include "MarsProject.h"
using namespace std;
//The function getMaxSum calculates the maximum sum of the contiguous subarray
void getMaxSum(vector<int> &myVector, int length)
{
  int maxValue = INT_MIN;
  int startIndex=0, endIndex =0;
 
		for ( int i = 0; i < length; i++)
		{
		int curSum =myVector[i];
          			if(maxValue < myVector[i]) { // checking if current element greater than 								    so far calculated maximum value. 
             		maxValue = myVector[i];	// if yes, then maxvalue will be current 								  element
              		startIndex =i+1;		//starting index will be equal to index of 								  current element 
              		endIndex = i+1;		//ending index will be equal to index of 								  current element
          			} 
             	    for (int j = i+1; j < length; j++)
		   {
			  int sum=0; 
			    for(int k=i; k<j;k++)           // calculation of sum of array elements 								    ranging from i to j
			    {
			        sum = sum + myVector[k];
			    }
			    curSum = sum + myVector[j];
            		if(maxValue < curSum)           // current sum will be compared with the 								    maxValue
            			{
                		maxValue = curSum;
                		startIndex =i+1;                        // starting index of contiguous sub array 								     corresponding to maximum sum
                		endIndex = j+1;   		 // ending index of contiguous sub array 								    corresponding to maximum sum
			}
			
		}		
	}
cout<<startIndex<<" "<<endIndex<<" "<<maxValue; // printing startIndex, endIndex, maxValue
}
 
int task1()
{
    int length;
    cin>>length;   					// Read length of contiguous input array
    vector<int> myVector(length);  			//creation of vector of size 'length'
    	for (int i = 0; i < length; i++) 
	{
	cin >> myVector[i]; 				// Reading of array elements from console
	}
    getMaxSum(myVector,length); 			// method call to getMaxSum
    return 0;
}
