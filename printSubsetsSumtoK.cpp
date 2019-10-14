void printSubs(int input[],int size,int k,int output[],int m)
{
    if(size==0)
    {
        if(k==0)
        {
            for(int i =0;i<m;i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        return;}
        if(k<0||size==0)
            return;
    }
    int i;
    output[m] = input[0];
    printSubs(input+1,size-1,k-input[0],output,m+1);
    
    printSubs(input+1,size-1,k,output,m);
    
    
    return;
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[size+100]={};
    int m =0;
    printSubs(input,size,k,output,m);
    return;
}
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
