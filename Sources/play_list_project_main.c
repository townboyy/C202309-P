//231630 김도형
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 10 
#define SONG_LEN 100 
#define GENRE_NAME 100 
#define GENRE_NUM 3 
#define PERSON_COUNT 5 

char genre[GENRE_NUM][GENRE_NAME] = { "POP", "발라드", "힙합" }; 
char songs[MAX_SONGS][SONG_LEN] = { "" }; 
int songCount[PERSON_COUNT] = { 0 }; 

char peopleNames[PERSON_COUNT][50]; 
char peopleFavoriteGenres[PERSON_COUNT][GENRE_NAME]; 
char*** peopleFavoriteSongs; 

void addSong(char* song, char* songGenre, int personIndex, int delIndex) {
    printf("재생 목록에 추가할 노래를 입력하세요: ");
    scanf_s("%s", song, SONG_LEN);

    for (int i = 0; i < songCount[personIndex]; i++) {
        if (strcmp(peopleFavoriteSongs[personIndex][i], song) == 0) {
            printf("이미 재생목록에 있는 노래입니다. 다시 입력해주세요.\n");
            for (int j = delIndex; j < songCount[personIndex]; j++) {
                strcpy_s(peopleFavoriteSongs[personIndex][j - 1], SONG_LEN, peopleFavoriteSongs[personIndex][j]);
            }
            songCount[personIndex]--;
        }
    }
    strcpy_s(peopleFavoriteSongs[personIndex][songCount[personIndex]], SONG_LEN, song);

   
    strcpy_s(peopleFavoriteGenres[personIndex], GENRE_NAME, songGenre);

    printf("'%s'가 '%s' 장르에 추가되었습니다.\n\n", song, songGenre);

    songCount[personIndex]++;
}

void delSong(int delIndex, int personIndex) {
    printf("%d. %s : 노래를 재생목록에서 삭제합니다.\n", delIndex, peopleFavoriteSongs[personIndex][delIndex - 1]);
    for (int i = delIndex; i < songCount[personIndex]; i++) {
        strcpy_s(peopleFavoriteSongs[personIndex][i - 1], SONG_LEN, peopleFavoriteSongs[personIndex][i]);
    }
    songCount[personIndex]--;
}

void printSongList(int personIndex) {
    printf("%s의 재생목록 (노래 수 : %d) :\n", peopleNames[personIndex], songCount[personIndex]);
    for (int i = 0; i < songCount[personIndex]; i++) {
        printf("%d. %s (장르: %s)\n", i + 1, peopleFavoriteSongs[personIndex][i], peopleFavoriteGenres[personIndex]);
    }
    printf("\n");
}

void recommendSong(char* inputGenre) {
    printf("\n'%s'장르의 노래를 추천합니다:\n", inputGenre);

    for (int i = 0; i < PERSON_COUNT; i++) {
        if (strcmp(inputGenre, peopleFavoriteGenres[i]) == 0) {
            for (int j = 0; j < songCount[i]; j++) {
                printf("'%s'장르 추천 노래 for %s: %s (장르: %s)\n", inputGenre, peopleNames[i], peopleFavoriteSongs[i][j], inputGenre);
            }
        }
    }
}

int main() {
    int choice = 0; 
    int end = 0; 
    int delIndex = -1; 
    char ch; 
    int modifyIndex = 0;
    char inputGenre[GENRE_NAME] = ""; 
    int genreCount[GENRE_NUM] = { 0 }; 
    int select = 0;
    int center_select = 0;
    int coupon = 0;
    int coupon_answer = 231630;

    
    for (int i = 0; i < PERSON_COUNT; i++) {
        printf("사용자 %d, 이름을 입력하세요: ", i + 1);
        scanf_s("%s", peopleNames[i], 50);
    }

    
    peopleFavoriteSongs = (char***)malloc(PERSON_COUNT * sizeof(char**));
    for (int i = 0; i < PERSON_COUNT; i++) {
        peopleFavoriteSongs[i] = (char**)malloc(MAX_SONGS * sizeof(char*));
        for (int j = 0; j < MAX_SONGS; j++) {
            peopleFavoriteSongs[i][j] = (char*)malloc(SONG_LEN * sizeof(char));
        }
    }

   

    while (1) {
        printf("---------------------------------------------------\n");
        printf("1. 노래 추가\n2. 노래 삭제\n3. 재생목록\n4. 프로그램 종료\n5. 노래 수정\n6. 유사한 노래\n7. 인기 장르\n8. 고객센터\n");
        printf("---------------------------------------------------\n");
        printf("메뉴를 입력해주세요 : \n");
        scanf_s("%d", &choice); 

        switch (choice) {
        case 1:
            printf("사용자를 선택하세요 (1~5): ");
            int personIndex;
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printf("노래의 장르를 입력하세요 (POP, 발라드, 힙합 등): ");
            scanf_s("%s", inputGenre, GENRE_NAME);
            addSong(peopleFavoriteSongs[personIndex - 1][songCount[personIndex - 1] % MAX_SONGS], inputGenre, personIndex - 1, delIndex);
            break;

        case 2:
            printf("사용자를 선택하세요 (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printf("삭제할 노래의 인덱스를 입력하세요 : ");
            scanf_s("%d", &delIndex);
            if (delIndex > songCount[personIndex - 1] || delIndex <= 0) {
                printf("삭제할 노래가 없습니다.\n");
            }
            else {
                delSong(delIndex, personIndex - 1);
            }
            break;

        case 3:
            printf("사용자를 선택하세요 (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printSongList(personIndex - 1);
            break;

        case 4:
            end = 1;
            break;

        case 5:
            printf("사용자를 선택하세요 (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printf("수정할 노래의 번호를 입력해주세요. (1부터 시작): ");
            scanf_s("%d", &modifyIndex);
            ch = getchar();
            printf("새롭게 추가할 노래를 입력해주세요: ");
            scanf_s("%s", peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], SONG_LEN);
            printf("새로운 노래가 추가되었습니다: %d. %s (장르: %s)\n", modifyIndex, peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], genre[modifyIndex - 1]);
            break;

        case 6:
            printf("선호하는 장르를 입력하세요 (POP, 발라드, 힙합): ");
            scanf_s("%s", inputGenre, GENRE_NAME);
            recommendSong(inputGenre);
            break;

        case 7:
            for (int i = 0; i < GENRE_NUM; i++) {
                genreCount[i] = 0;
            }
            int totalsongs = 0;
            for (int i = 0; i < PERSON_COUNT; i++) {
                if (songCount[i] > 0) {
                    for (int j = 0; j < GENRE_NUM; j++) {
                        if (strcmp(peopleFavoriteGenres[i], genre[j]) == 0) {
                            genreCount[j]++;
                        }
                    }
                    totalsongs += songCount[i]++;
                }
            }
            if (totalsongs == 0) {
                printf("노래를 입력하지 않았습니다. 메뉴1을 선택해 노래를 입력해주세요.\n");
            }
            else {


                int popularIndex = 0;
                for (int i = 1; i < GENRE_NUM; i++) {
                    if (genreCount[i] > genreCount[popularIndex]) {
                        popularIndex = i;
                    }
                }
                printf("가장 인기있는 장르: %s\n", genre[popularIndex]);
            }
            break;

        case 8:
            printf("---------------------------------------------------\n");
            printf("<고객센터>.\n\n도움이 필요하시면 1, 필요 없다면 2를 입력해주세요 :\n ");
            printf("---------------------------------------------------\n");
            scanf_s("%d", &select);
            if (select == 2) {
                printf("고객센터를 종료합니다\n");
            }
            else if (select == 1) {
                printf("---------------------------------------------------\n");
                printf("<고객센터 메뉴>\n\n1.해지 신청\n2.쿠폰 등록\n3.플레이리스트 사용설명서\n");
                printf("---------------------------------------------------\n");
                printf("고객센터 메뉴를 선택해주세요.\n");
                scanf_s("%d", &center_select);
                if (center_select == 1) {
                    printf("이용권을 해지합니다.\n");
                }
                else if (center_select == 2) {
                    printf("쿠폰을 등록합니다. 쿠폰 번호를 입력해주세요 : \n");
                    scanf_s("%d", &coupon);
                    if (coupon == coupon_answer) {
                        printf("쿠폰이 확인 되었습니다. 한 달 무료 쿠폰이 증정되었습니다.\n");
                    }
                    else if (coupon != coupon_answer) {
                        printf("쿠폰 번호가 틀렸습니다.\n");
                    }
                }
            
                else if (center_select == 3) {
                    printf("<플레이리스트 사용 방법>\n");
                    printf("사용자 이름 입력 \n");
                    printf("메뉴 1 : 노래 추가 - 사용자를 선택하고, 입력할 노래의 장르와 제목을 입력.\n");
                    printf("메뉴 2 : 노래 삭제 - 노래를 삭제 할 사용자를 선택후, 삭제할 노래의 인덱스를 입력.\n");
                    printf("메뉴 3 : 재생목록 출력 - 입력받은 사용자의 재생목록과 노래 수 를 출력함.\n");
                    printf("메뉴 4 : 프로그램 종료\n");
                    printf("메뉴 5 : 노래 수정 - 입력받은 사용자의 수정할 노래 인덱스를 입력하고, 새로 추가할 노래를 입력.\n");
                    printf("메뉴 6 : 유사한 노래 - 선호하는 장르를 입력한 후, 그와 같은 장르의 노래들을 모두 출력.\n");
                    printf("메뉴 7 : 인기 장르 - 가장 많이 입력받은 장르를 출력.\n");
                    printf("메뉴 8 : 고객센터 - 이용 해지와, 쿠폰 등록, 사용설명서\n");

                }
            }

            break;

        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        if (end == 1) {
            printf("재생목록을 종료합니다.\n");
            break;
        }
        if (songCount[0] == MAX_SONGS) {
            printf("노래가 %d개로 다 찼습니다.\n", songCount[0]);
            break;
        }
    }

    
    for (int i = 0; i < PERSON_COUNT; i++) {
        for (int j = 0; j < MAX_SONGS; j++) {
            free(peopleFavoriteSongs[i][j]);
        }
        free(peopleFavoriteSongs[i]);
    }
    free(peopleFavoriteSongs);

    return 0;
}