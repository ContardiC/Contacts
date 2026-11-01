# Contacts

A simple command-line address book written in C. Contacts are stored in a linked list while the program is running.

## Features

- Add a contact with a first name, last name, phone number, city, and marketing-consent choice.
- Display all contacts in the address book.
- Delete the most recently added contact.
- Delete all contacts currently in memory.
- Search for contacts by city and display the matching entries. The city search compares the entered city exactly, including letter case.
- Export the current address book to `contacts.csv` as a backup.

## Build and run

Compile with GCC:

```sh
gcc  main.c -o contacts
```

Run the program:

```sh
./contacts
```

On macOS, the same executable can be launched from the terminal with `./contacts`.

## Data storage

Contacts remain in memory and are cleared when the program exits. Use the CSV backup option to export the current address book; the program does not load contacts from the CSV file.
