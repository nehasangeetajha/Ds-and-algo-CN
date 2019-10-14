// input - input array
// size - length of input array
// element - value to be searched
int helper(int input[],int si,int ei,int element)
{
    if(si>ei)
        return -1;
    int mid = (si+ei)/2;
    if(input[mid] == element)
        return mid;
    if(input[mid] > element)
        return helper(input,si,mid-1,element);
    if(input[mid] <element)
        return helper(input,mid+1,ei,element);
    
    return -1;

}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    int si = 0;
    int ei = size-1;
    
    int x = helper(input,si,ei,element);
    return x;
}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
