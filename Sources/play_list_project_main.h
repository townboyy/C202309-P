//231630 김도형 플레이리스트 프로젝트 헤더파일

#ifndef PLAY_LIST_PROJECT_MAIN_H
#define PLAY_LIST_PROJECT_MAIN_H

#define MAX_SONGS 10
#define SONG_LEN 100
#define GENRE_NAME 100
#define GENRE_NUM 3
#define PERSON_COUNT 5

typedef struct {
    char title[SONG_LEN];
    char genre[GENRE_NAME];
} Song;

typedef struct {
    char name[50];
    Song favoriteSongs[MAX_SONGS];
    int songCount;
    char favoriteGenre[GENRE_NAME];
} Person;

extern Person people[PERSON_COUNT];
extern char genre[GENRE_NUM][GENRE_NAME];
extern int coupon_answer;

void addSong(int personIndex);
void delSong(int personIndex);
void printSongList(int personIndex);
void recommendSong(char* inputGenre);
void printPopularGenre();
void customerCenter();

#endif 
