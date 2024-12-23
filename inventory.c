#include <stdio.h>
#include <stdlib.h>
#include <readline.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part 
{
    int number;
    char name [NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_parts(int number);
void insert ();
void search ();
void update ();
void print ();

int main(int argc, char *argv[])
{
    char code;
    for(;;)
    {
        printf("Enter operation code: ");
        scanf("%c", &code);
        while (getchar () != \n); 
        switch (code) 
        {
            case 'i':
                insert ();
                break;
            case 's':
                search ();
                break;
            case 'u':
                upadte ();
                break;
            case 'p':
                print ();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n")
    }
}
