#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Contact
{
    char fname[60];
    char lname[60];
    char tel[20];
    char city[40];
    int cons_marketing;
} Contact;
struct Node
{
    Contact contact;
    struct Node *next;
};
int main()
{
    printf("Welcome in Contacts\n");
}