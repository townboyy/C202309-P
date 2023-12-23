//231630 김도형 플레이리스트 프로젝트 메인파일

#include <stdio.h>
#include <stdlib.h>
#include "play_list_project_main.h"

int main() {
    for (int i = 0; i < PERSON_COUNT; i++) {
        printf("사용자 %d, 이름을 입력하세요: ", i + 1);
        scanf_s("%s", people[i].name, 50);
    }

    while (1) {
        printf("-----------------------메뉴------------------------\n");
        printf("1. 노래 추가\n2. 노래 삭제\n3. 재생목록\n4. 프로그램 종료\n5. 노래 수정\n6. 유사한 노래\n7. 인기 장르\n8. 고객센터\n");
        printf("---------------------------------------------------\n");
        printf("메뉴를 입력해주세요 : ");

        int choice;
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

            addSong(personIndex - 1);
            break;

        case 2:
            printf("사용자를 선택하세요 (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            delSong(personIndex - 1);
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
            printf("재생목록을 종료합니다.\n");
            return 0;

        case 5:
            printf("사용자를 선택하세요 (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("잘못된 선택입니다.\n");
                break;
            }

            printf("수정할 노래의 번호를 입력해주세요. (1부터 시작): ");
            int modifyIndex;
            scanf_s("%d", &modifyIndex);

            printf("새롭게 추가할 노래를 입력해주세요: ");
            scanf_s("%s", people[personIndex - 1].favoriteSongs[modifyIndex - 1].title, SONG_LEN);

            printf("새로운 노래가 추가되었습니다: %d. %s (장르: %s)\n", modifyIndex,
                people[personIndex - 1].favoriteSongs[modifyIndex - 1].title,
                genre[modifyIndex - 1]);
            break;

        case 6:
            printf("선호하는 장르를 입력하세요 (POP, 발라드, 힙합): ");
            char inputGenre[GENRE_NAME];
            scanf_s("%s", inputGenre, GENRE_NAME);
            recommendSong(inputGenre);
            break;

        case 7:
            printPopularGenre();
            break;

        case 8:
            customerCenter();
            break;

        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}

