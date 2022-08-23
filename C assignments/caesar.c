//encrypts message using Caesar's cipher. usage - ./caesar 'number' 
//example - ./caesar 13

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
        if ( argc != 2 || (argc = 2 && only_digits(argv[1]) == 1)) {
                printf("Usage: ./caesar key\n");
                return 1;
        } else {
                string input = get_string("plaintext: ");
                int input_length = strlen(input);
                char output[input_length];
                int key = atoi(argv[1]);
                printf("ciphertext: ");
                for (int j = 0; j < input_length; j++) {
                        output[j] = rotate(input[j], key);
                        printf("%c", output[j]);
                }
                printf("\n");
                return 0;
        }
}

bool only_digits(string s) {
        int s_length = strlen(s);
        int value = 0;
        for (int i=0; i<s_length; i++) {
                if (isdigit(s[i])) {
                        value = value + 0;
                } else {
                        value = 1;
                }
        }
        return value;
        return 0;
}

char rotate(char c, int n) {
        if (isalpha(c)) {
                int final_key = n%26;
                int new_ci;
                if ( islower(c)) {
                        if (c + final_key > 122) {
                                new_ci = (c+final_key - 122) + 96;
                        } else {
                                new_ci = c + final_key;
                        }
                } else {
                        if (c + final_key > 90) {
                                new_ci = (c+final_key - 90) + 64;
                        } else {
                                new_ci = c + final_key;
                        }
                }
                char new_c = new_ci;
                return new_ci;
        } else {
                return c;
        }
        return 0;

}
