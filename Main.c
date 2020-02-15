/*
 * Main.c
 * Conversion hexadecimal string to its logical 
 * analog - hexadecimal integer.
 * !WORKING ONLY WITH ASCII!
 * 
 *  Created to: 15 February
 *     Autor: SashaMois
 */

#include <stdio.h>
#include <ctype.h>

int htoi(char string_for_initialization[]);

int main()
{
    int c; /* saves input */
    int i; /* count */

    enum {
        MAXLINE = 100,
    };
    char hexadecimal[MAXLINE];
    hexadecimal[0] = '0';
    hexadecimal[1] = 'X';

    for (i = 2; (c = getchar()) != '\n'; ++i)
        hexadecimal[i] = c;
    hexadecimal[i] = '\n';

    printf("%x\n", htoi(hexadecimal));

	return 0;
}

int htoi(char string[])
{
    int saver_result = 0;

    if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
        unsigned int i; /* counter */
        unsigned int degrees_of_16 = 1;

        enum {
            NEGATIVE = 87, /* it is for get hexadecimal that more 9 */
        };

        for (i = 3; string[i] != '\n'; ++i)
            degrees_of_16 *= 16;
        
        for (i = 2; string[i] != '\n'; ++i) {
            if (isalpha(string[i])) {
                string[i] = tolower(string[i]);

                saver_result += ((string[i] - NEGATIVE) * degrees_of_16);
                degrees_of_16 /= 16;
            }
            else {
                saver_result += ((string[i] - '0') * degrees_of_16);
                degrees_of_16 /= 16;
            }
        }

    }

    return saver_result;
}