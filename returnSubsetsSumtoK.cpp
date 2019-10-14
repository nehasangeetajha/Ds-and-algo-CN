/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
//run till s1 + s2 righ second loop will start from s1

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    // if(n==0)
    //     return 1;
    int o1[100000][50];
    int o2[100000][50];
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else 
            return 0;
    }
    int s2=subsetSumToK(input+1,n-1,o2,k-input[0]);
        int s1=subsetSumToK(input+1,n-1,o1,k);
int i,j;
    for(i=0;i<s2;i++){
        output[i][0]=o2[i][0]+1;
        output[i][1]=input[0];
        
        for(j=0;j<=o2[i][0];j++){
            output[i][j+2]=o2[i][j+1];
 }
    }
    
    for(i=0;i<s1;i++){
        for(j=0;j<=o1[i][0];j++){
            output[i+s2][j]=o1[i][j];
        }
    }
    return s1+s2;

}
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
