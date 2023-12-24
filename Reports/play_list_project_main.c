//231630 김도형 플레이리스트 프로젝트 소스파일

#include "play_list_project_main.h"
#include <stdio.h>
#include <string.h>

Person people[PERSON_COUNT];
char genre[GENRE_NUM][GENRE_NAME] = { "POP", "발라드", "힙합" };
int coupon_answer = 231630;

void addSong(int personIndex) {
    printf("재생 목록에 추가할 노래를 입력하세요: ");
    scanf_s("%s", people[personIndex].favoriteSongs[people[personIndex].songCount].title, SONG_LEN);

    for (int i = 0; i < people[personIndex].songCount; i++) {
        if (strcmp(people[personIndex].favoriteSongs[i].title, people[personIndex].favoriteSongs[people[personIndex].songCount].title) == 0) {
            printf("이미 재생목록에 있는 노래입니다. 다시 입력해주세요.\n");
            return;
        }
    }

    printf("입력한 노래의 장르를 입력하세요 (POP, 발라드, 힙합 등): ");
    scanf_s("%s", people[personIndex].favoriteSongs[people[personIndex].songCount].genre, GENRE_NAME);

    strcpy_s(people[personIndex].favoriteGenre, GENRE_NAME, people[personIndex].favoriteSongs[people[personIndex].songCount].genre);

    printf("'%s'가 '%s' 장르에 추가되었습니다.\n\n",
        people[personIndex].favoriteSongs[people[personIndex].songCount].title,
        people[personIndex].favoriteSongs[people[personIndex].songCount].genre);

    people[personIndex].songCount++;
}

void delSong(int personIndex) {
    printf("삭제할 노래의 인덱스를 입력하세요 : ");
    int delIndex;
    scanf_s("%d", &delIndex);

    if (delIndex > people[personIndex].songCount || delIndex <= 0) {
        printf("삭제할 노래가 없습니다.\n");
    }
    else {
        printf("%d. %s : 노래를 재생목록에서 삭제합니다.\n", delIndex, people[personIndex].favoriteSongs[delIndex - 1].title);

        for (int i = delIndex; i < people[personIndex].songCount; i++) {
            people[personIndex].favoriteSongs[i - 1] = people[personIndex].favoriteSongs[i];
        }

        people[personIndex].songCount--;
    }
}

void printSongList(int personIndex) {
    printf("%s의 재생목록 (노래 수 : %d) :\n", people[personIndex].name, people[personIndex].songCount);

    for (int i = 0; i < people[personIndex].songCount; i++) {
        printf("%d. %s (장르: %s)\n", i + 1, people[personIndex].favoriteSongs[i].title, people[personIndex].favoriteGenre);
    }

    printf("\n");
}

void recommendSong(char* inputGenre) {
    printf("\n'%s'장르의 노래를 추천합니다:\n", inputGenre);

    for (int i = 0; i < PERSON_COUNT; i++) {
        if (strcmp(inputGenre, people[i].favoriteGenre) == 0) {
            for (int j = 0; j < people[i].songCount; j++) {
                printf("'%s'장르 추천 노래 for %s: %s (장르: %s)\n",
                    inputGenre, people[i].name, people[i].favoriteSongs[j].title, inputGenre);
            }
        }
    }
}
void printPopularGenre() {
    int genreCount[GENRE_NUM] = { 0 };
    int totalSongs = 0;

    for (int i = 0; i < PERSON_COUNT; i++) {
        if (people[i].songCount > 0) {
            for (int j = 0; j < GENRE_NUM; j++) {
                if (strcmp(people[i].favoriteGenre, genre[j]) == 0) {
                    genreCount[j]++;
                }
            }
            totalSongs += people[i].songCount;
        }
    }

    if (totalSongs == 0) {
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
}
void customerCenter() {
    printf("---------------------------------------------------\n");
    printf("<고객센터>.\n\n도움이 필요하시면 1, 필요 없다면 2를 입력해주세요 :\n ");
    printf("---------------------------------------------------\n");

    int select;
    scanf_s("%d", &select);

    if (select == 2) {
        printf("고객센터를 종료합니다\n");
    }
    else if (select == 1) {
        printf("---------------------------------------------------\n");
        printf("<고객센터 메뉴>\n\n1.해지 신청\n2.쿠폰 등록\n3.플레이리스트 사용설명서\n");
        printf("---------------------------------------------------\n");

        int center_select;
        printf("고객센터 메뉴를 선택해주세요 : ");
        scanf_s("%d", &center_select);

        if (center_select == 1) {
            printf("이용권을 해지합니다.\n");
        }
        else if (center_select == 2) {
            printf("쿠폰을 등록합니다. 쿠폰 번호를 입력해주세요 : ");

            int coupon;
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
       
            
        

        else {
            printf("잘못 입력하셨습니다\n");
        }
    }
}
