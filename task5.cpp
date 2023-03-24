 
#include <bits/stdc++.h>		//to utilise standard input and output functions
#include "MarsProject.h"
using namespace std;
//The function getMaxSum calculates the maximum sum of the 2D contiguous subarray
int getMaxSum(vector<int>  &A, int &startIndex, int &endIndex, int col )  
{
int maxSum = A[0];
int curMax = A[0];
startIndex = 0;
endIndex = 0;

	for(int i=1;i<col;i++)
	{
		if(A[i] < curMax+A[i]) //  substructure property for Dynamic programming
		{
		curMax = curMax +A[i];
			if(maxSum < curMax) //compare the maximum sum with the current element
			{
			maxSum = curMax;
			endIndex =i;
			}
		}
		else
		{
		curMax = A[i];
			if(maxSum < curMax) //compare the maximum sum with the current element


			{
			maxSum = curMax;
			startIndex =i;
			endIndex =i;
			}
		}
	}

return maxSum;
}

int task5()
{

int row,col;
cin>>row>>col;    // Read rows and columns of input array



vector<vector<int> > inputmatrix(row,vector<int> (col));

	for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
	cin>> inputmatrix [i][j];		// Reading of array elements from console
	}
	}	

int maxSum = INT_MIN;
int leftIndex,rightIndex,topIndex,bottomIndex;

int curLeft, curRight, i, j;
int sum, startIndex, endIndex;

for (curLeft = 0; curLeft < col; curLeft ++) {

	for (curRight = curLeft; curRight < col; curRight ++) {

	vector<int> temp_array(row,0);
		for (i = 0; i < row; i++)
		{
			for (j= curLeft; j<= curRight;j++)
			{
			temp_array[i] = temp_array[i]+ inputmatrix[i][j];
			}
		}

	sum = getMaxSum(temp_array, startIndex, endIndex, row); // method call to getMaxSum

	if (sum > maxSum) {
	maxSum = sum;
	leftIndex = curLeft;
	rightIndex = curRight;
	topIndex = startIndex;
	bottomIndex = endIndex;
	}
	}
}

cout<< topIndex+1<<" "<< leftIndex+1<<" "<< bottomIndex+1<<" "<< rightIndex+1<<" "<<maxSum<<endl;

return 0;
}
