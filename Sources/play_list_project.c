//231630 김도형 플레이리스트 프로젝트
#include <stdio.h>
#define MAX_SONGS 10
#define SONG_LEN 100
#include <string.h>

char songs[MAX_SONGS][SONG_LEN] = { "" }; // 노래 목록을 저장하기 위한 2차원 배열
int songCount = 0; // 노래의 수를 저장

void addSong(char song[]) { //노래를 목록에 추가하는 함수
    printf("노래를 입력하세요 (공백 없이 입력하세요): ");
    scanf_s("%s", song, (int)sizeof(song));
    strcpy_s(songs[songCount], sizeof(songs[songCount]), song);
    printf("노래 ""%s""가 추가되었습니다\n\n", song);
}


 void printsonglist(int songCount){ //재생목록을 출력하는 함수

     for (int i = 0; i < songCount; i++) {
         printf("%d. %s \n", i + 1, songs[i]);
     }
 printf("\n");

 }
int main() {
    printf("음악 플레이리스트 시작! \n");

    while (1) {
        int choice = 0; // 사용자 입력 메뉴를 저장하기 위한 변수

        // 사용자에게 메뉴를 출력하고, 메뉴를 입력받기
        printf("------------------\n");
        printf("메뉴를 입력해주세요.\n");
        printf("1. 재생목록에 노래 추가\n2. 노래 삭제\n3. 재생목록\n4. 종료\n5. 노래 수정\n");
        printf("현재 노래 수 = %d\n", songCount);
        printf("------------------\n");
        scanf_s("%d", &choice);

        int end = 0;
       
        char ch;

        
        switch (choice) {
        case 1:
            addSong(songs[songCount]);
            songCount++;
            break;

        case 3:
            printf("재생목록 \n");
            printsonglist(songCount);
            break;
       
        case 4:
            end = 1;
            break;
       
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        if (end == 1) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        if (songCount == 10) {
            printf("노래가 %d개로 다 찼습니다.", songCount);
            break;
        }
    }
    return 0;
}
