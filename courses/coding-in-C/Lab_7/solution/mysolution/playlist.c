#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char *songName;
    char *artist;
    struct Song *pnext;
}Song;

typedef struct Playlist{
    Song *firstSong;
    Song *current;
}Playlist;

void addSong(Playlist *playlist, char *songName, char *artistName){
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
    return;
}

void insert_Node(Song *New_Node, Song *head, int index){ 
    if(index == 0){
        New_Node->pnext = head;
        head = New_Node;
    }else{
        Song *current = NULL;
        current = head;
        for(int i=0; i<index-1; i++){
            current = current->pnext;
        }
        New_Node->pnext = current->pnext;
        current->pnext = New_Node;
    }

}

void delete_first_Song(Playlist *Playlist){
    Song *tmp = Playlist->firstSong;
    Playlist->firstSong = Playlist->firstSong->pnext;
    char *name = tmp->songName;
    free(tmp);
    printf("\nDeleted Song:%s", name);
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
/*void delete_Playlist(Playlist *Playlist){
    delete_Songs(Playlist);
    free(Playlist);
    Playlist = NULL;
    printf("\nDeleted Playlist!");
}*/
void print_Playlist(Playlist *playlist){
    Song *tmp = playlist->firstSong;
    if(playlist->firstSong == NULL){
        printf("\nPlaylist is empty!");
        return;
    }
    while(tmp->pnext != NULL){
        printf("\nTitle: %s, Artist: %s", tmp->songName, tmp->artist);
        tmp = tmp->pnext;
        if(tmp->pnext == NULL){
            printf("\nTitle: %s, Artist: %s", tmp->songName, tmp->artist);

        }
    }
    return;

}
void initPlaylist(Playlist *pplaylist){
    pplaylist = malloc(sizeof(pplaylist));
    pplaylist->firstSong = NULL;
    return;
}
int main(){
    /*Playlist myPlaylist;
    initPlaylist(&myPlaylist);
    addSong(&myPlaylist, "Crawling", "LinkingPark");
    addSong(&myPlaylist, "BlackParade", "MyChemicalRomance");
    addSong(&myPlaylist, "Creep", "Radiohead");
    addSong(&myPlaylist, "Killer Queen", "Queen");
    print_Playlist(&myPlaylist);
    delete_first_Song(&myPlaylist);
    print_Playlist(&myPlaylist);
    delete_first_Song(&myPlaylist);
    print_Playlist(&myPlaylist);
    delete_Songs(&myPlaylist);
    print_Playlist(&myPlaylist);*/
    Playlist myPlaylist;
    Playlist myPlaylist2;
    initPlaylist(&myPlaylist);
    initPlaylist(&myPlaylist2);

    addSong(&myPlaylist, "Crawling", "LinkingPark");
    print_Playlist(&myPlaylist);

    addSong(&myPlaylist, "Layla", "Eric Clapton");
    addSong(&myPlaylist, "Esperanto", "Max Herre");
    print_Playlist(&myPlaylist);

    

    delete_first_Song(&myPlaylist);
    print_Playlist(&myPlaylist);

    delete_Songs(&myPlaylist);
    //delete_Playlist(&myPlaylist);

    return 0;
}