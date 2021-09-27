#include <iostream>
using namespace std;

bool checkAB(char input[]) {
	// Write your code here

    if(input[0] == '\0') //base case
    return false;


    if(input[0]=='a') 
    {

        if(input[1] == '\0')
        return true;

        else if(input[1] == 'a')
        checkAB(input+1);

        else if(input[1]=='b')
        {
            if(input[2]=='b')
            {
                if(input[3]=='\0')
                return true;
                else if(input[3]=='a')
                checkAB(input+3);
                else
                return false;
            }

            else
            return false;
        }
        else
        return false;
        
    }

    else
    return false;
}   

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
