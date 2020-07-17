#include <iostream>
#include <string>

// in a string of lowercase characters shift each character by key
// result should be a string of lowercase characters

using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    string result = "";
    for (int i = 0; i < str.size(); i++)
    {
        unsigned char ch = str[i] + key % 26;

        if (ch <= 122)
        {
            result += ch;
        }
        else
        {
            result += (96 + (ch % 122));
        }
    }
    return result;
}

int main()
{
    cout << caesarCypherEncryptor("abxcz", 16) << endl;
    return 0;
}