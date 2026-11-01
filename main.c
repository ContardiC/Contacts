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
void insertContact(struct Node **head, Contact contact)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->contact = contact;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        struct Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}
int main()
{
    int opt;
    printf("|---- Welcome in Contacts ----|\n");
    do
    {
        printf("1) Inserisci un contatto\n");
        printf("0) Esci dal programma\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            printf("Arriverci\n");
            break;
        case 1:

            break;

        default:
            break;
        }
    } while (opt != 0);
}