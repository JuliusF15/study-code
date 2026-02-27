#include "include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    initPlaylist(&myPlaylist);

    addSong(&myPlaylist, "Crawling", "LinkingPark");
    addSong(&myPlaylist, "Fotoshop", "Apo Red");
    addSong(&myPlaylist, "Orangensaft", "Money Boy");
    print_Playlist(&myPlaylist);

    delete_first_Song(&myPlaylist);
    print_Playlist(&myPlaylist);

    delete_Songs(&myPlaylist);
    return 0;
}