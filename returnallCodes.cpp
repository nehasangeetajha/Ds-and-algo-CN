#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty())
    {
        output[0] = "";
        return 1;
    }
    
    int j,q;
    int d = input[0] - '0';
    char c = d + 'a' - 1;
    char k = '\0';
    string result1[10000],result2[10000];
    int p = getCodes(input.substr(1),result1);
    int r = 0;
    if(input[1]!='\0')
    {
        int e = d*10;
        q = input[1] - '0';
        j = e+q;
        if(j>=10 && j<=26)
        {
            k = j+'a' - 1;
            r = getCodes(input.substr(2),result2);
        }
    }
    int m = 0;
    for(int i =0;i<p;i++)
    {
        output[m] = c+result1[i];
        m++;
    }
    
    if(k!='\0')
    {
        for(int i =0;i<r;i++)
        {
            output[m] =  k + result2[i];
            m++;
        }
    }
    return m;
}

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
