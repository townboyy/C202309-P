//231630 김도형 플레이리스트 프로젝트
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10 //플레이리스트 노래 개수 10개 제한
#define SONG_LEN 100 //노래 제목 길이 
#define GENRE_NAME 100 //장르 이름
#define GENRE_NUM 3 //장르 개수
#define PERSON_COUNT 5 //이용자 수




char genre[GENRE_NUM][GENRE_NAME] = { "POP", "발라드", "힙합" }; //일단 장르 3개로 제한
char songs[MAX_SONGS][SONG_LEN] = { "" }; //노래제목을 입력받는 2차원 배열
int songCount[PERSON_COUNT] = { 0 }; //이용자 5명의 노래 개수 세는 변수

char peopleNames[PERSON_COUNT][50]; //이용자의 이름을 입력받는 변수
char peopleFavoriteGenres[PERSON_COUNT][GENRE_NAME]; //이용자의 선호하는 장르를 입력받는 2차원 배열
char peopleFavoriteSongs[PERSON_COUNT][MAX_SONGS][SONG_LEN]; //사용자의 선호노래를 입력받는 3차원 배열


void addSong(char song[], char songGenre[], int personIndex, int delIndex) {
    printf("노래를 입력하세요: ");
    scanf_s("%s", song, (int)sizeof(song));
    
for(int i = 0;i<songCount[personIndex];i++){

    if (strcmp(peopleFavoriteSongs[personIndex][i], song)==0) {
        printf("이미 재생목록에 있는 노래입니다. 다른 노래를 입력하세요\n");
        for (int i = delIndex; i < songCount[personIndex]; i++) {
            strcpy_s(peopleFavoriteSongs[personIndex][i - 1], sizeof(peopleFavoriteSongs[personIndex][i]), peopleFavoriteSongs[personIndex][i]);
        }
        songCount[personIndex]--;
    }
}
    strcpy_s(peopleFavoriteSongs[personIndex][songCount[personIndex]], sizeof(peopleFavoriteSongs[personIndex][songCount[personIndex]]), song);

    // 입력한 노래의 장르를 사용자가 선호하는 장르로 저장
    strcpy_s(peopleFavoriteGenres[personIndex], sizeof(peopleFavoriteGenres[personIndex]), songGenre);

    printf("'%s' 노래가 '%s' 장르에 추가되었습니다.\n\n", song, songGenre);

    songCount[personIndex]++;
}

void delSong(int delIndex, int personIndex) {
    printf("%d. %s : 노래를 삭제합니다.\n", delIndex, peopleFavoriteSongs[personIndex][delIndex - 1]);
    for (int i = delIndex; i < songCount[personIndex]; i++) {
        strcpy_s(peopleFavoriteSongs[personIndex][i - 1], sizeof(peopleFavoriteSongs[personIndex][i]), peopleFavoriteSongs[personIndex][i]);
    }
    songCount[personIndex]--;
}

void printSongList(int personIndex) {
    printf("재생목록 for %s:\n", peopleNames[personIndex]);
    for (int i = 0; i < songCount[personIndex]; i++) {
        printf("%d. %s (장르: %s)\n", i + 1, peopleFavoriteSongs[personIndex][i], peopleFavoriteGenres[personIndex]);
    }
    printf("\n");
}

void recommendSong(char inputGenre[]) {
    printf("\n'%s'와 비슷한 장르의 노래를 추천합니다:\n", inputGenre);

    

    for (int i = 0; i < PERSON_COUNT; i++) {
      
        if (strcmp(inputGenre, peopleFavoriteGenres[i]) == 0) {
           
            for (int j = 0; j < songCount[i]; j++) {
                printf("'%s' 추천 노래 for %s: %s (장르: %s)\n", inputGenre, peopleNames[i], peopleFavoriteSongs[i][j], inputGenre);
            }
        }
    }

   
}














int main() {
    int choice = 0; //메뉴 입력받을 변수
    int end = 0; //종료 변수
    int delIndex = -1; //삭제를 위한 변수
    char ch; //버퍼 제거..?
    int modifyIndex = 0; //수정을 위한 변수
    char inputGenre[GENRE_NAME] = "";//장르이름을 입력받을 변수
    int genreCount[GENRE_NUM] = { 0 }; // 각 장르의 등장 횟수를 저장하는 배열

    

    

    // 각 이용자의 정보 입력
    for (int i = 0; i < PERSON_COUNT; i++) {
        printf("사용자 %d, 이름을 입력하세요: ", i + 1);
        scanf_s("%s", peopleNames[i], (int)sizeof(peopleNames[i]));
    }
        printf("음악 플레이리스트 시작!\n");
    
    while (1) {
        printf("------------------\n");
        printf("메뉴를 입력해주세요.\n");
        printf("1. 재생목록에 노래 추가\n2. 노래 삭제\n3. 재생목록\n4. 종료\n5. 노래 수정\n6. 비슷한 노래 둘러보기\n7.가장 인기있는 장르\n");
        printf("현재 노래 수 = %d\n", songCount[0]);  // 여기서는 첫 번째 사람의 노래 수를 표시

        printf("------------------\n");
        scanf_s("%d", &choice); //실행할 메뉴 입력받음

        switch (choice) { //입력받는 CHOICE에 따라 하는 일을 조건문을 통해 분류
        case 1:
            printf("사용자를 선택하세요 (1~5): ");
            int personIndex;
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printf("노래의 장르를 입력하세요 (POP, 발라드, 힙합): ");
            scanf_s("%s", inputGenre, (int)sizeof(inputGenre));
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
            scanf_s("%s", peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], (int)sizeof(peopleFavoriteSongs[personIndex - 1][modifyIndex - 1]));
            printf("새로운 노래가 추가되었습니다: %d. %s (장르: %s)\n", modifyIndex, peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], genre[modifyIndex - 1]);
            break;

        case 6:
            printf("선호하는 장르를 입력하세요 (POP, 발라드, 힙합): ");
            scanf_s("%s", inputGenre, (int)sizeof(inputGenre));
            recommendSong(inputGenre);
            break;

        case 7:
            for (int i = 0; i < PERSON_COUNT; i++) {
                for (int j = 0; j < GENRE_NUM; j++) {
                    if (strcmp(peopleFavoriteGenres[i], genre[j]) == 0) {
                        genreCount[j]++;
                    }
                }
            }

           
            int popularIndex = 0;
            for (int i = 1; i < GENRE_NUM; i++) {
                if (genreCount[i] > genreCount[popularIndex]) {
                    popularIndex = i;
                }
            }

            // 가장 인기 있는 장르를 출력
            printf("가장 인기있는 장르: %s\n", genre[popularIndex]);
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
   
    
    
    return 0;
   
}
