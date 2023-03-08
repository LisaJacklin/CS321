#include "pal.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    while (1)
    {
        char buffer[64] = {0};
	cout << "Enter a string: ";
        cin >> buffer;
 
        if (isPalindrome(buffer))
        {
            cout << "Word is a palindrome" << endl;
        }
        else
        {
            cout << "Word is not a palindrome" << endl;
        }
    }
 
    return 0;
}
