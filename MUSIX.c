#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Song
{
    char name[50];
    char artist[50];
    int duration;
    float rating;

    struct Song *prev;
    struct Song *next;
};

void addSong(struct Song **head)
{
    struct Song *newSong;
    struct Song *temp;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    printf("\nEnter song name: ");
    fgets(newSong->name, 50, stdin);
    newSong->name[strcspn(newSong->name, "\n")] = '\0';

    printf("Enter artist name: ");
    fgets(newSong->artist, 50, stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = '\0';

    printf("Enter duration (minutes): ");
    scanf("%d", &newSong->duration);

    newSong->rating = 3.0 + (rand() % 21) / 10.0;

    newSong->prev = NULL;
    newSong->next = NULL;

    if (*head == NULL)
    {
        *head = newSong;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    printf("\nSong added successfully!\n");
    printf("Generated Rating: %.1f\n", newSong->rating);
}

void displayPlaylist(struct Song *head)
{
    struct Song *temp;
    int count = 1;

    if (head == NULL)
    {
        printf("\nPlaylist is empty.\n");
        return;
    }

    temp = head;

    printf("\n========== MY PLAYLIST ==========\n");

    while (temp != NULL)
    {
        printf("\n%d. %s", count, temp->name);
        printf("\n   Artist: %s", temp->artist);
        printf("\n   Duration: %d minutes", temp->duration);
        printf("\n   Rating: %.1f\n", temp->rating);

        temp = temp->next;
        count++;
    }

    printf("\n=================================\n");
}

int main()
{
    struct Song *head = NULL;
    int choice;

    srand(time(NULL));

    do
    {
        printf("\n\n========== MUSIX ==========\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Exit\n");
        printf("============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                addSong(&head);
                break;

            case 2:
                displayPlaylist(head);
                break;

            case 3:
                printf("\nThank you for using MUSIX!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}