
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[] )
{

    // If file args aren't correctly inputted.
    while(argc < 2)
    {
        printf("Correct usage: ./%s.c file.csv\n", argv[0]);
        exit(0);
    }


FILE *questions = fopen(argv[1], "a+");
FILE *answers = fopen(argv[1], "a+"); // opens a new file stream of the same file

// If wasn't successfully opened then exit while informing user
if(questions == NULL)
{
    printf("Could not open file. Please try again.");
    exit(0);
}

printf("N - Shows next questions. R - Reveals answer. A - appends a question and answer to CSV file. E - Exits terminal.\n");

int flag = 1; // Do while flag
char buffer[1024]; // Buffer to read questions into
char buffer2[1024]; // buffer to read answers into
char command; // For scanf to read into and compare

fgets(buffer, sizeof(buffer), questions); // Reads the CSV headers into the buffer and ignores the call so we can skip reading the csv headers
fgets(buffer2, sizeof(buffer2), answers); // reads the csv headers... again for a different buffer. Ignores the headers.

do
{
    printf("Enter a command: ");
    scanf(" %c", &command);

    // Exit command
    if(command == 'e' || command == 'E')
    {
        printf("Exiting.\n");
        exit(0);
    }

    if(command == 'n' || command == 'N')
    {
        while(fgets(buffer, sizeof(buffer), answers))
        {
            
            char *question = strtok(buffer, ","); // Seperates the CSV files using a comma as a seperator to only print questions. 
            printf("%s\n", question);
            break;
        }

        
    }
    
    if(command == 'r' || command == 'R')
    {
        while(fgets(buffer2, sizeof(buffer2), questions))
        {
            
            char *question = strtok(buffer2, ","); // call strtok to read the questions into buffer so next call will work on answers
            char *answer = strtok(NULL, ","); // continue reading the buffer which is now on answers
            char *no_whitespace = strtok(answer, "\n"); // Trims the answer of all whitespace

            printf("%s\n", no_whitespace);

            break;
        }
    }



} while (flag ==  1);


fclose(questions);
fclose(answers);
}

