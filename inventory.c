#include <stdio.h>
#include <ctype.h>


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
void insert();
void search();
void update();
void print();
int read_line(char str[], int n);

int main(int argc, char *argv[])
{
    char code;
    for(;;)
    {
        printf("Enter operation code: ");
        scanf("%c", &code);
        while (getchar () != '\n'); 
        switch (code) 
        {
            case 'i':
                insert ();
                break;
            case 's':
                search ();
                break;
            case 'u':
                update ();
                break;
            case 'p':
                print ();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_parts(int number)
{
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert()
{
    int part_number;
    if (num_parts == MAX_PARTS)
    {
        printf("FULL DATABASE\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", & part_number);

    if (find_parts(part_number) >= 0)
    {
        printf("part already exists \n");
        return;
    }
    inventory[num_parts].number = part_number;
    printf("enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts ++;
}

void search()
{
    int i, number;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_parts(number);

    if ( i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
        printf("Part not found\n");
}

void update()
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_parts(number);
    if( i >= 0)
    {
        printf("Enter quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        printf("part not found\n");
}

void print()
{
    int i;
    printf("Part number   Part name   Quantity on hand\n");
    for( i = 0; i < num_parts; i++)
        printf("%7d          %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF)
    {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}