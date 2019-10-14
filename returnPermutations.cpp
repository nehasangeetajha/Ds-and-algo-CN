#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int n = input.size();
    if(n==0){
        output[0]="";
        return 1;//because reaching here means you have got one permutation
    }
        
    int smallOutput;
    for(int i = 0;i<n;i++)
    {
        string subString = input.substr(0,i) +input.substr(i+1,n-i-1);
        string newOP[10000];
        smallOutput = returnPermutations(subString,newOP);
        for(int k=(i*smallOutput); k<(i*smallOutput)+smallOutput ; k++)
            output[k] = input[i] + newOP[k-(i*smallOutput)];
    }
    
    return n * smallOutput;
    
    
}
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
