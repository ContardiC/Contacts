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
void deleteLastContact(struct Node **head)
{
    if (*head == NULL)
    {
        puts("La rubrica è vuota: non ci sono contatti da eliminare.");
        return;
    }

    struct Node *last = *head;
    if (last->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        struct Node *previous = NULL;
        while (last->next != NULL)
        {
            previous = last;
            last = last->next;
        }
        previous->next = NULL;
    }

    printf("Eliminato contatto: %s %s\n", last->contact.fname, last->contact.lname);
    free(last);
}
void printList(struct Node *head)
{
    if (head == NULL)
    {
        puts("La rubrica è vuota");
        return;
    }
    while (head != NULL)
    {
        puts(" --- CONTATTO ---");
        puts(head->contact.fname);
        puts(head->contact.lname);
        puts(head->contact.tel);
        puts(head->contact.city);
        if (head->contact.cons_marketing == 1)
        {
            puts("Ha espresso il consenso al trattamento dei dati al fine del marketing");
        }
        else
        {
            puts("Non ha espresso il consenso al trattamento dei dati al fine del marketing");
        }
        puts(" --- FINE CONTATTO ---");
        head = head->next;
    }
}
void freeList(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void toCSV(struct Node *head)
{
    FILE *file = fopen("contacts.csv", "w");
    if (file == NULL)
    {
        puts("Errore nell'apertura del file");
        return;
    }
    if (head == NULL)
    {
        puts("La rubrica è vuota: non ci sono contatti da salvare.");
        fclose(file);
        return;
    }
    // Scrivi l'intestazione del CSV
    fprintf(file, "Nome,Cognome,Telefono,Città,Consenso Marketing\n");
    while (head != NULL)
    {
        fprintf(file, "\"%s\",\"%s\",\"%s\",\"%s\",%d\n",
                head->contact.fname,
                head->contact.lname,
                head->contact.tel,
                head->contact.city,
                head->contact.cons_marketing);
        head = head->next;
    }

    fclose(file);
    printf("Backup della rubrica salvato in contacts.csv\n");
}
int main()
{
    int opt;
    Contact c;
    struct Node *contacts = NULL;

    printf("|---- Welcome in Contacts ----|\n");
    do
    {
        puts("1) Inserisci un contatto");
        puts("2) Visualizza la Rubrica");
        puts("3) Elimina l'ultimo contatto inserito");
        puts("4) Elimina tutti i contatti");
        puts("5) Crea un file CSV di backup della rubrica");
        puts("0) Esci dal programma");
        scanf("%d", &opt);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        switch (opt)
        {
        case 0:
            printf("Arriverci\n");
            break;
        case 1:
            puts(" --- INSERIMENTO CONTATTO ---");
            puts("Inserisci il nome: ");
            scanf(" %59[^\n]", c.fname);
            puts("Inserisci il cognome: ");
            scanf(" %59[^\n]", c.lname);
            puts("Inserisci il numero di telefono: ");
            scanf(" %19[^\n]", c.tel);
            puts("Inserisci la città di residenza o domicilio: ");
            scanf(" %39[^\n]", c.city);
            puts("0: Nego il consenso al trattamento dei miei dati a finalità di marketing");
            puts("1: Do il consenso al trattamento dei miei dati a finalità di marketing");
            scanf("%d", &c.cons_marketing);
            insertContact(&contacts, c);
            break;
        case 2:
            printList(contacts);
            break;
        case 3:
            deleteLastContact(&contacts);
            break;
        case 4:
            freeList(contacts);
            contacts = NULL;
            break;
        case 5:
            // Implement CSV backup functionality here
            break;
        default:
            puts("Input errato");
            break;
        }
    } while (opt != 0);
}