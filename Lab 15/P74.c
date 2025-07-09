// Write a program to simulate music player application using suitable data structure. There is no estimation about number of music files to be managed by the music player. Your program should support all the basic music player operations to play and manage the playlist.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[100];
    int duration;
    struct Song *lptr, *rptr;
};

struct Song *first = NULL, *last = NULL, *current = NULL;

void addSong()
{
    char title[100];
    int duration;

    printf("Enter Song Title: ");
    scanf(" %[^\n]", title);
    printf("Enter Duration (seconds): ");
    scanf("%d", &duration);

    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    newSong->duration = duration;
    newSong->rptr = newSong->lptr = NULL;

    if (first == NULL)
    {
        first = last = current = newSong;
    }//if
    else
    {
        last->rptr = newSong;
        newSong->lptr = last;
        last = newSong;

        if (current == NULL)
        {
            current = newSong;
        }//if
    } // else

    printf("Song added to playlist.\n");
} // add song

void deleteSong()
{
    if (first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    } // if

    char title[100];
    printf("Enter title of the song to delete: ");
    scanf(" %[^\n]", title);

    struct Song *save = first;
    while (save != NULL)
    {
        if (strcmp(save->title, title) == 0)
        {
            if (save == first)
            {
                first = save->rptr;
            } // if
            if (save == last)
            {
                last = save->lptr;
            } // if
            if (save->lptr)
            {
                save->lptr->rptr = save->rptr;
            } // if
            if (save->rptr)
            {
                save->rptr->lptr = save->lptr;
            } // if

            if (current == save)
            {
                current = save->rptr ? save->rptr : save->lptr;
            } // if

            free(save);
            printf("Song deleted.\n");
            return;
        } // if
        save = save->rptr;
    } // while

    printf("Song not found.\n");
} // delete song

void playCurrent()
{
    if (current == NULL)
    {
        printf("No song is currently selected.\n");
        return;
    } // if

    printf("Now Playing: \"%s\" [%d sec]\n", current->title, current->duration);
} // play current

void playrptr()
{
    if (current && current->rptr)
    {
        current = current->rptr;
        playCurrent();
    } // if
    else
    {
        printf("No rptr song in the playlist.\n");
    } // else
} // play rptr

void playlptrious()
{
    if (current && current->lptr)
    {
        current = current->lptr;
        playCurrent();
    } // if
    else
    {
        printf("No lptrious song in the playlist.\n");
    } // else
} // play lptrious

void displayPlaylist()
{
    if (first == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    } // if

    printf("\nPlaylist:\n");
    struct Song *save = first;
    int index = 1;

    while (save != NULL)
    {
        char *label = (save == current) ? "  <-- current" : "";
        printf("%d. \"%s\" [%d sec]%s\n", index++, save->title, save->duration, label);
        save = save->rptr;
    } // while
} // display

void main()
{
    int choice;

    while (1)
    {
        printf("\nMusic Player Menu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Current Song\n");
        printf("4. Play rptr Song\n");
        printf("5. Play lptrious Song\n");
        printf("6. Display Playlist\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong();
            break;
        case 2:
            deleteSong();
            break;
        case 3:
            playCurrent();
            break;
        case 4:
            playrptr();
            break;
        case 5:
            playlptrious();
            break;
        case 6:
            displayPlaylist();
            break;
        default:
            printf("Invalid choice. Try again.\n");
        } // switch case
    } // while
} // main