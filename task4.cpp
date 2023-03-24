#include<bits/stdc++.h>		//to utilise standard input and output functions
#include "MarsProject.h"
using namespace std;
//The function getMaxSum calculates the maximum sum of the contiguous 2 D subarray
void getMaxSum (vector<vector<int>> &matrix, int rows, int columns)
{
int maxSum = INT_MIN;		  //this variable holds the maximum sum calculated so far

int row1 = -1,col1 = -1,row2 = -1,col2 = -1;
int sum;

    for(int r1=0; r1< rows;  r1++){ 
	for(int c1=0;c1< columns; c1++){
		for(int r2= r1; r2< rows; r2++){
			for(int c2= c1; c2< columns; c2++){
			sum = 0;
				for(int i=r1; i<=r2; i++){
				for(int j=c1; j<=c2; j++){
				sum = sum + matrix[i][j];
				}
			           }

		           if(sum > maxSum){	//compare the maximum sum with the current 							element

		           maxSum = sum;	//this variable holds the starting index of the 								maximum sum contiguous subarray

		           row1 = r1; col1 = c1;
		           row2 = r2; col2 = c2;
		           }
 		           }
		}
	}
    }

cout<< row1 +1<<" "<< col1+1<<" "<< row2+1<<" "<< col2+1<<" "<< maxSum<<endl;
}

int task4(){

int rows,columns;		
cin>> rows >> columns;				// Read rows and columns of input array

vector<vector<int>> matrix(rows,vector<int> (columns));

	for(int i=0;i< rows;i++){			// Reading of array elements from console
		for(int j=0;j< columns;j++){
		cin>>matrix[i][j];
		}
	}
getMaxSum(matrix, rows, columns);			// method call to getMaxSum

return 0;
}
