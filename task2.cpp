#include <bits/stdc++.h>		//to utilise standard input and output functions
#include "MarsProject.h"
using namespace std;
//The function getMaxSum calculates the maximum sum of the contiguous subarray
void getMaxSum(vector<int> &input, int length)
{
int summation[length][length]; 
int maxValue = INT_MIN;	        //this variable holds the maximum sum calculated so far
int startIndex = -1;	//this variable holds the starting index of the maximum sum contiguous subarray
int endIndex = -1;	//this variable holds the ending index of the maximum sum contiguous subarray
for (int row = 0; row < length; row++)
{
for (int col = row; col < length; col++)
{
if (row == col)
{
summation[row][row] = input[row];		// summation[i][j] is the sum of elements of array from row to col indexes
if (maxValue<summation[row][row])	//compare the maximum sum with the current element
{
maxValue = summation[row][row];
startIndex = row;
endIndex = row;
}
}
else
{
summation[row][col] = summation[row][col - 1] + input[col];     //  Dynamic programming substructure property
if (summation[row][col] > maxValue)	//compare the current sum and maximum sum so far
{
maxValue = summation[row][col];
startIndex = row;
endIndex = col;
}
}
}
}

cout << startIndex + 1 << " " << endIndex + 1 << " " << maxValue << endl;
}
int task2()
{
int length;
cin>>length;
vector<int> input(length);
cout<<"Enter the input elements";
for (int index=0;index<length;index++)
{
    cin>>input[index];
    }
getMaxSum(input,length); 	//make a call to the function getMaxSum to calculate the maximum sum contiguous subarray
return 0;
}
