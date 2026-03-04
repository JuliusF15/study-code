#ifndef PLAYLIST_H
#define PLAYLIST_H
#define MAX_SONGS 50

typedef struct Song{
    char *songName;
    char *artist;
    struct Song *pnext;
}Song;

typedef struct Playlist{
    Song *firstSong;
    Song *current;
    int playlist_lenght;
}Playlist;

void addSong(Playlist *playlist, char *songName, char *artistName);

void delete_first_Song(Playlist *Playlist);

void delete_Songs(Playlist *Playlist);

void print_Playlist(Playlist *playlist);

void initPlaylist(Playlist *pplaylist);

Song* find_song_by_title(Playlist *playlist, const char *title);

int count_songs_recursive(const Song *current);

#endif