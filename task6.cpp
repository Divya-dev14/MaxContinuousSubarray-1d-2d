#include <bits/stdc++.h>	//to utilise standard input and output functions
#include "MarsProject.h"
using namespace std;

//The function getMaxSum calculates the maximum sum of the contiguous 2D subarray
int getMaxSum(vector<vector<int>> &inputmatrix,int r,int c)
    {
        int maxSum = -1,minSum = INT_MIN,row = 0, col = 0,r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        vector<vector<int>> temp_array(r+1,vector<int> (c));
        for (int index1 = 0; index1 < r; index1++)
        {
            for (int index2 = 0; index2 < c; index2++)
            {
                temp_array[index1 + 1][index2] = temp_array[index1][index2] + inputmatrix[index1][index2];
            }
        }
 
        for (int row_start = 0;row_start < r; row_start++)
        {
            for (int row1 = row_start; row1 < r; row1++)
            {
                int sum = 0, col_start = 0;
                for (int col1 = 0; col1 < c; col1++)
                {
                    sum += temp_array[row1 + 1][col1]- temp_array[row_start][col1];
                    if (sum < 0) {
                        if (minSum < sum) {
                        row = row1;
                        col = col1;
                        minSum = sum;
                        }
                        sum = 0;
                        col_start = col1 + 1;
                    }
                    else if (maxSum < sum)
                    {
                    r1 = row_start;
                    r2 = row1;
                    c1 = col_start;
                    c2 = col1;
                    maxSum = sum;  
                    }
                }
            }
        }
        if (maxSum == -1) {
            cout<<"row start : "<<row+1<<" to row end : "<<row+1<<"; ";
            cout<<"col start : "<<col+1<<" to col end : "<<col+1;
        }
        else {
            cout<<"row start : "<<r1+1<<" to row end : "<<r2+1<<"; ";
            cout<<"col start : "<<c1+1<<" to col end : "<<c2+1<<" ";
        }
        return maxSum == -1 ? minSum : maxSum;
    }
 
int task6()
{
int row,col;
cin>>row>>col;		// Read rows and columns of input array
vector<vector<int>> inputmatrix(row,vector<int> (col));
	  for(int i=0;i<row;i++){
	  for(int j=0;j<col;j++){
	  cin>> inputmatrix [i][j];	// Reading of array elements from console
	  }
	  }	
int max=getMaxSum(inputmatrix,row,col);	// method call to getMaxSum
cout<<"; sum = "<<max<<endl;
return 0;
}
