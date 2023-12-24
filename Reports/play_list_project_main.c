//231630 �赵�� �÷��̸���Ʈ ������Ʈ �ҽ�����

#include "play_list_project_main.h"
#include <stdio.h>
#include <string.h>

Person people[PERSON_COUNT];
char genre[GENRE_NUM][GENRE_NAME] = { "POP", "�߶��", "����" };
int coupon_answer = 231630;

void addSong(int personIndex) {
    printf("��� ��Ͽ� �߰��� �뷡�� �Է��ϼ���: ");
    scanf_s("%s", people[personIndex].favoriteSongs[people[personIndex].songCount].title, SONG_LEN);

    for (int i = 0; i < people[personIndex].songCount; i++) {
        if (strcmp(people[personIndex].favoriteSongs[i].title, people[personIndex].favoriteSongs[people[personIndex].songCount].title) == 0) {
            printf("�̹� �����Ͽ� �ִ� �뷡�Դϴ�. �ٽ� �Է����ּ���.\n");
            return;
        }
    }

    printf("�Է��� �뷡�� �帣�� �Է��ϼ��� (POP, �߶��, ���� ��): ");
    scanf_s("%s", people[personIndex].favoriteSongs[people[personIndex].songCount].genre, GENRE_NAME);

    strcpy_s(people[personIndex].favoriteGenre, GENRE_NAME, people[personIndex].favoriteSongs[people[personIndex].songCount].genre);

    printf("'%s'�� '%s' �帣�� �߰��Ǿ����ϴ�.\n\n",
        people[personIndex].favoriteSongs[people[personIndex].songCount].title,
        people[personIndex].favoriteSongs[people[personIndex].songCount].genre);

    people[personIndex].songCount++;
}

void delSong(int personIndex) {
    printf("������ �뷡�� �ε����� �Է��ϼ��� : ");
    int delIndex;
    scanf_s("%d", &delIndex);

    if (delIndex > people[personIndex].songCount || delIndex <= 0) {
        printf("������ �뷡�� �����ϴ�.\n");
    }
    else {
        printf("%d. %s : �뷡�� �����Ͽ��� �����մϴ�.\n", delIndex, people[personIndex].favoriteSongs[delIndex - 1].title);

        for (int i = delIndex; i < people[personIndex].songCount; i++) {
            people[personIndex].favoriteSongs[i - 1] = people[personIndex].favoriteSongs[i];
        }

        people[personIndex].songCount--;
    }
}

void printSongList(int personIndex) {
    printf("%s�� ������ (�뷡 �� : %d) :\n", people[personIndex].name, people[personIndex].songCount);

    for (int i = 0; i < people[personIndex].songCount; i++) {
        printf("%d. %s (�帣: %s)\n", i + 1, people[personIndex].favoriteSongs[i].title, people[personIndex].favoriteGenre);
    }

    printf("\n");
}

void recommendSong(char* inputGenre) {
    printf("\n'%s'�帣�� �뷡�� ��õ�մϴ�:\n", inputGenre);

    for (int i = 0; i < PERSON_COUNT; i++) {
        if (strcmp(inputGenre, people[i].favoriteGenre) == 0) {
            for (int j = 0; j < people[i].songCount; j++) {
                printf("'%s'�帣 ��õ �뷡 for %s: %s (�帣: %s)\n",
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
        printf("�뷡�� �Է����� �ʾҽ��ϴ�. �޴�1�� ������ �뷡�� �Է����ּ���.\n");
    }
    else {
        int popularIndex = 0;

        for (int i = 1; i < GENRE_NUM; i++) {
            if (genreCount[i] > genreCount[popularIndex]) {
                popularIndex = i;
            }
        }

        printf("���� �α��ִ� �帣: %s\n", genre[popularIndex]);
    }
}
void customerCenter() {
    printf("---------------------------------------------------\n");
    printf("<������>.\n\n������ �ʿ��Ͻø� 1, �ʿ� ���ٸ� 2�� �Է����ּ��� :\n ");
    printf("---------------------------------------------------\n");

    int select;
    scanf_s("%d", &select);

    if (select == 2) {
        printf("�����͸� �����մϴ�\n");
    }
    else if (select == 1) {
        printf("---------------------------------------------------\n");
        printf("<������ �޴�>\n\n1.���� ��û\n2.���� ���\n3.�÷��̸���Ʈ ��뼳��\n");
        printf("---------------------------------------------------\n");

        int center_select;
        printf("������ �޴��� �������ּ��� : ");
        scanf_s("%d", &center_select);

        if (center_select == 1) {
            printf("�̿���� �����մϴ�.\n");
        }
        else if (center_select == 2) {
            printf("������ ����մϴ�. ���� ��ȣ�� �Է����ּ��� : ");

            int coupon;
            scanf_s("%d", &coupon);

            if (coupon == coupon_answer) {
                printf("������ Ȯ�� �Ǿ����ϴ�. �� �� ���� ������ �����Ǿ����ϴ�.\n");
            }
            else if (coupon != coupon_answer) {
                printf("���� ��ȣ�� Ʋ�Ƚ��ϴ�.\n");
            }
        }
        else if (center_select == 3) {
            printf("<�÷��̸���Ʈ ��� ���>\n");
            printf("����� �̸� �Է� \n");
            printf("�޴� 1 : �뷡 �߰� - ����ڸ� �����ϰ�, �Է��� �뷡�� �帣�� ������ �Է�.\n");
            printf("�޴� 2 : �뷡 ���� - �뷡�� ���� �� ����ڸ� ������, ������ �뷡�� �ε����� �Է�.\n");
            printf("�޴� 3 : ������ ��� - �Է¹��� ������� �����ϰ� �뷡 �� �� �����.\n");
            printf("�޴� 4 : ���α׷� ����\n");
            printf("�޴� 5 : �뷡 ���� - �Է¹��� ������� ������ �뷡 �ε����� �Է��ϰ�, ���� �߰��� �뷡�� �Է�.\n");
            printf("�޴� 6 : ������ �뷡 - ��ȣ�ϴ� �帣�� �Է��� ��, �׿� ���� �帣�� �뷡���� ��� ���.\n");
            printf("�޴� 7 : �α� �帣 - ���� ���� �Է¹��� �帣�� ���.\n");
            printf("�޴� 8 : ������ - �̿� ������, ���� ���, ��뼳��\n");
        }
       
            
        

        else {
            printf("�߸� �Է��ϼ̽��ϴ�\n");
        }
    }
}
