#include <iostream>
#include <string>
using namespace std;

void help(string input,int si,int ei)
{
    if(si == ei)
        cout << input << endl;
    
    for(int i = si;i<=ei;i++)
    {
        swap(input[si],input[i]);
        help(input,si +1,ei);
        swap(input[si],input[i]);
    }
    
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int si = 0;
    int ei = input.size() -1;
    help(input,si,ei);
}
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
