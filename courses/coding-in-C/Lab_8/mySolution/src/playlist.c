#include "../include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSong(Playlist *playlist, char *songName, char *artistName){
    if(playlist->playlist_lenght < MAX_SONGS){
        Song *newnode = malloc(sizeof(*newnode));
         if(newnode == NULL){
            printf("Fehler bei der Speicherfreigabe");
        }
        newnode->songName = malloc(strlen(songName)+1);
        newnode->artist = malloc(strlen(artistName)+1);
        strcpy(newnode->songName, songName);
        strcpy(newnode->artist, artistName);
        newnode->pnext = NULL;
    
        if (playlist->firstSong == NULL) {
                playlist->firstSong = newnode;      // Head wird durch die erste Node ersetzt. Da es nur eine gibt, ist current diese Node
                playlist->current = playlist->firstSong;
        }else {
            playlist->current->pnext = newnode; //im bei der 2. Node wird der pnext vom Head auf diesen gelegt, dann wandert current zum nächsten. Bei der 3. Node wird der pnext von der 2.Node auf die Adresse der 3. gesetzt, da current == Node2 ist
            playlist->current = newnode;
        }
        playlist->playlist_lenght++;
        printf("\nAdded Song: %s, %s", songName, artistName);
        return;
    }else{
        printf("\nPlaylist is full!!");
        return;
    }
}

void delete_first_Song(Playlist *Playlist){
    Song *tmp = Playlist->firstSong;
    Playlist->firstSong = Playlist->firstSong->pnext;
    char *name = tmp->songName;
    printf("\nDeleted Song:%s", name);
    free(tmp->songName);
    free(tmp->artist);
    free(tmp);
    return;

}

void delete_Songs(Playlist *Playlist){
     if(Playlist->firstSong == NULL){
        printf("\nPlaylist is empty!");
        return;
    }
    Song *tmp = Playlist->firstSong;
    while(tmp != NULL){
        Playlist->current = tmp->pnext;
        free(tmp->artist);
        free(tmp->songName);
        free(tmp);
        tmp = Playlist->current;
    }
    if(tmp == NULL){
        printf("\nSongs deleted!");
    }
    Playlist->current = NULL;
    Playlist->firstSong = NULL;
}

void print_Playlist(Playlist *playlist){
    Song *tmp = playlist->firstSong;

    if(tmp == NULL){
        printf("\nPlaylist is empty!");
        return;
    }

    while(tmp != NULL){
        printf("\nTitle: %s, Artist: %s", tmp->songName, tmp->artist);
        tmp = tmp->pnext;
    }
}

void initPlaylist(Playlist *pplaylist){
    pplaylist->firstSong = NULL;
    pplaylist->current = NULL;
    pplaylist->playlist_lenght = 0;
    return;
}