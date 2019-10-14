void help(int input[],int size,int output[],int m)
{
    if(size==0)
    {
        for(int i=0;i<m;i++)
        {
            cout << output[i]<<" " ;
        }
        cout << endl;
        return;
    }
    
    help(input+1,size-1,output,m);
    
    int* newOutput = new int[m+1];
    for(int i=0;i<m;i++)
        {
            newOutput[i] = output[i];
        }
    newOutput[m] = input[0];
    help(input+1,size-1,newOutput,m+1);
    return;
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[]={};
    int m =0;
    help(input,size,output,m);

}
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
