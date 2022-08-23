#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    int key_length = strlen(key);
    for (int i = 0; i < 26; i++)
    {
        if (key_length != 26 || isalpha(key[i]) == 0)
    {
        printf("USAGE: ./substitution key");
    }
    }

}