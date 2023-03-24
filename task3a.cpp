#include <bits/stdc++.h>
#include "MarsProject.h"
//#include "headerfile.h"

using namespace std;

int getMaxSum(vector<int> airqualityind, vector<int> sum_temp, int index1, int &startIndex, int &endIndex , int &maxValue)
{
if (index1 == 0)
{
return airqualityind[0];
}
else // recursive case
{
if (sum_temp[index1] == INT_MIN) 	// use the recursion to calculate the s
{
int s = getMaxSum( airqualityind, sum_temp, index1 - 1, startIndex, endIndex , maxValue) + airqualityind[index1]; 	// Dynamic programming optimal substructure
if (s >  airqualityind[index1])	// if s is greater than the current value in the array then update the sum_temp[index1] with s
{
sum_temp[index1] = s;
if (maxValue < sum_temp[index1])     // if the maxValue is less than the sum_temp[index1] than update the maxValue with the sum_temp[index1] and endIndex
{
maxValue = sum_temp[index1];
endIndex = index1;
}
}
else
{
sum_temp[index1] = airqualityind[index1];
if (maxValue < sum_temp[index1])      // if the maxValue is less than the sum_temp[index1] than update the maxValue with the sum_temp[index1] along with endIndex
{
maxValue = sum_temp[index1];
startIndex = index1;
endIndex = index1;
}
}
}
else
{
int s = sum_temp[index1 - 1] + airqualityind[index1];
if (s > airqualityind[index1])
{
sum_temp[index1] = s;
if (maxValue < sum_temp[index1])     // if the maxValue is less than the sum_temp[index1] than update the maxValue with the sum_temp[index1] and endIndex
{
maxValue = sum_temp[index1];
endIndex = index1;
}
}
else
{
sum_temp[index1] = airqualityind[index1];
if (maxValue < sum_temp[index1])    // if the maxValue is less than sum_temp[index] then maxValue is updated to sum_temp[i]
{
maxValue = sum_temp[index1];
startIndex = index1;
endIndex = index1;
}
}
}
}
return sum_temp[index1];
}

int task3a()
{
int length; 			// this variable is to store the number of elements
cin >> length;
vector<int> airqualityind(length); 	// vector to store the input elements
vector<int> sum_temp(length); 	// maxValue[i] holds maximum sum till index i
for (int i = 0; i < length; i++)
{
cin >> airqualityind[i];
sum_temp[i] = INT_MIN;
}
int startIndex = 0;		// Intialize startIndex to 0
int endIndex = 0; 		// Intialize endIndex to 0
int maxValue = INT_MIN; 	// Intialize highest negative integer
int sum = getMaxSum(airqualityind, sum_temp, length - 1, startIndex , endIndex, maxValue); // Recursive function to calculate the maximum sum of the subarray
cout << startIndex + 1 << " " << endIndex + 1 << " " << maxValue << endl; // print the desired output.
return 0;
}