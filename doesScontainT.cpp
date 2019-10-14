bool checksequenece(char large[] , char*small) {
    if(small[0] == '\0')
        return true;
     if(large[0]=='\0')
         return false;
    
    if(large[0]==small[0])
    {
        bool a = checksequenece(++large,++small);
        return a;
    }
     return checksequenece(++large,small);
    
}
#include<iostream>
using namespace std;
#include "solution.h"

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
