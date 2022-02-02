#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NUMBER_SIG 7

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char *ascii[55] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

char *decode_morse(const char *morse_code)
{
    // Allocate and copy the original array ________

    char *morse_out = (char *)calloc(strlen(morse_code), 1);
    morse_out = strdup(morse_code);
    char *mo = morse_out;

    char *morse_token;
    morse_token = strtok(morse_out, " ");

    while (morse_token)
    {

        for (int i = 0; i < (sizeof(morse_out) / sizeof(morse_out[0])); i++)
        {

            if (!strcmp(morse_token, morse[i]))
            {
                strcpy(mo, ascii[i]);
                mo += sizeof(ascii[i]);

                break;
            }
        }

        if ((morse_token = strtok(NULL, " ")) && (*(morse_token - 1) == ' '))
        {
            *mo++ = ' ';
        }
    }

    return morse_out;
}

void main(void)
{
    char morse1[] = ". -.--   .--- ..- -.. .";
    char *sentence;
    sentence = decode_morse(morse1);

    printf("Word: %s \n", sentence);
}