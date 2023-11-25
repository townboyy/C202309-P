//231630 김도형 플레이리스트 프로젝트
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10
#define SONG_LEN 100
#define GENRE_NAME 100
#define GENRE_NUM 3

char genre[GENRE_NUM][GENRE_NAME] = { "POP", "발라드", "힙합" }; //장르를 저장하기 위한 2차원 배열
char songs[MAX_SONGS][SONG_LEN] = { "" }; // 노래 목록을 저장하기 위한 2차원 배열
int songCount = 0; // 노래의 수를 저장

void addSong(char song[], char songGenre[]) { // 노래를 목록에 추가하는 함수, 노래와 장르를 함께 저장
    printf("노래를 입력하세요: ");
    scanf_s("%s", song, (int)sizeof(song));
    strcpy_s(songs[songCount], sizeof(songs[songCount]), song);


    strcpy_s(genre[songCount], sizeof(genre[songCount]), songGenre);

    printf("'%s' 노래가 '%s' 장르에 추가되었습니다.\n\n", song, songGenre);

    songCount++;
}

void delsong(int delindex, int songCount) {
    printf("%d. %s : 노래를 삭제합니다.\n", delindex, songs[delindex - 1]);
    for (int i = delindex; i < songCount; i++) {
        strcpy_s(songs[i - 1], sizeof(songs[i]), songs[i]);
        strcpy_s(genre[i - 1], sizeof(genre[i]), genre[i]); //노래를 삭제하면 그 노래의 장르에서도 지움
    }
}

void printsonglist(int songCount) { // 재생목록을 출력하는 함수
    printf("재생목록:\n");
    for (int i = 0; i < songCount; i++) {
        printf("%d. %s (장르: %s)\n", i + 1, songs[i], genre[i]); //인덱스 제목 장르를 함께 출력
    }
    printf("\n");
}

void recommendSong(char inputgenre[]) { //장르 추천 함수 > 원하는 장르를 입력하면 같은 장르의 노래를 추천해줌
    printf("\n'%s'와 비슷한 장르의 노래를 추천합니다:\n", inputgenre);

    for (int i = 0; i < songCount; i++) {
        if (strcmp(inputgenre, genre[i]) == 0) {
            printf("'%s' 추천 노래: %s (장르: %s)\n", inputgenre, songs[i], genre[i]);
        }
    }
}

int main() {
    int choice = 0; // 사용자 입력 메뉴를 저장하기 위한 변수
    int end = 0;
    int delindex = -1;
    char ch;
    int modifyindex = 0;
    char inputgenre[GENRE_NAME] = "";

    printf("음악 플레이리스트 시작!\n");

    while (1) {
        printf("------------------\n");
        printf("메뉴를 입력해주세요.\n");
        printf("1. 재생목록에 노래 추가\n2. 노래 삭제\n3. 재생목록\n4. 종료\n5. 노래 수정\n6. 비슷한 노래 둘러보기\n");
        printf("현재 노래 수 = %d\n", songCount);
        printf("------------------\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("노래의 장르를 입력하세요 (POP, 발라드, 힙합): ");
            scanf_s("%s", inputgenre, (int)sizeof(inputgenre));
            addSong(songs[songCount], inputgenre); // 노래 추가 함수 호출
            break;

        case 2:
            printf("삭제할 노래의 인덱스를 입력하세요 : ");
            scanf_s("%d", &delindex);
            if (delindex > songCount || delindex <= 0) {
                printf("삭제할 노래가 없습니다.\n");
            }
            else {
                delsong(delindex, songCount);
                songCount -= 1;
            }
            break;

        case 3:
            printsonglist(songCount); // 재생목록 출력 함수 호출
            break;

        case 4:
            end = 1;
            break;

        case 5:
            printf("수정할 노래의 번호를 입력해주세요. (1부터 시작): ");
            scanf_s("%d", &modifyindex);
            ch = getchar();
            printf("새롭게 추가할 노래를 입력해주세요: ");
            scanf_s("%s", songs[modifyindex - 1], (int)sizeof(songs[modifyindex - 1]));
            printf("새로운 노래가 추가되었습니다: %d. %s (장르: %s)\n", modifyindex, songs[modifyindex - 1], genre[modifyindex - 1]);
            break;

        case 6:
            printf("선호하는 장르를 입력하세요 (POP, 발라드, 힙합): ");
            scanf_s("%s", inputgenre, (int)sizeof(inputgenre));
            recommendSong(inputgenre); //장르추천 함수 호출
            break;

        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        if (end == 1) {
            printf("재생목록을 종료합니다.\n");
            break;
        }
        if (songCount == 10) {
            printf("노래가 %d개로 다 찼습니다.\n", songCount);
            break;
        }
    }
    return 0;
}

