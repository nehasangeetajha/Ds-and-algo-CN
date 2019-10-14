#include <string.h>
using namespace std;

void help (string input,string output)
{
    if(input.empty())
    {
        cout << output << endl;
        return;
    }
    
    int i = input[0] - '0';
    char c1 = 'a' + i -1;
    // output+= c1;
    help(input.substr(1),output+c1);
    int j = (input[0] - '0') * 10 + (input[1] - '0');
    char c2 = 'a' + j -1;
    if(j>=10&&j<=26){output+= c2;
    help(input.substr(2),output);
}}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = {};
    help(input,output);
}

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
