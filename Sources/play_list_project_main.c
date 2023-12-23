//231630 �赵�� �÷��̸���Ʈ ������Ʈ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        printf("������ �޴��� �������ּ���.");
        scanf_s("%d", &center_select);

        if (center_select == 1) {
            printf("�̿���� �����մϴ�.\n");
        }
        else if (center_select == 2) {
            printf("������ ����մϴ�. ���� ��ȣ�� �Է����ּ��� : \n");

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
    }
}


int main() {
    for (int i = 0; i < PERSON_COUNT; i++) {
        printf("����� %d, �̸��� �Է��ϼ���: ", i + 1);
        scanf_s("%s", people[i].name, 50);
    }

    while (1) {
        printf("-----------------------�޴�------------------------\n");
        printf("1. �뷡 �߰�\n2. �뷡 ����\n3. ������\n4. ���α׷� ����\n5. �뷡 ����\n6. ������ �뷡\n7. �α� �帣\n8. ������\n");
        printf("---------------------------------------------------\n");
        printf("�޴��� �Է����ּ��� : ");

        int choice;
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("����ڸ� �����ϼ��� (1~5): ");
            int personIndex;
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            addSong(personIndex - 1);
            break;

        case 2:
            printf("����ڸ� �����ϼ��� (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            delSong(personIndex - 1);
            break;

        case 3:
            printf("����ڸ� �����ϼ��� (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            printSongList(personIndex - 1);
            break;

        case 4:
            printf("�������� �����մϴ�.\n");
            return 0;

        case 5:
            printf("����ڸ� �����ϼ��� (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            printf("������ �뷡�� ��ȣ�� �Է����ּ���. (1���� ����): ");
            int modifyIndex;
            scanf_s("%d", &modifyIndex);

            printf("���Ӱ� �߰��� �뷡�� �Է����ּ���: ");
            scanf_s("%s", people[personIndex - 1].favoriteSongs[modifyIndex - 1].title, SONG_LEN);

            printf("���ο� �뷡�� �߰��Ǿ����ϴ�: %d. %s (�帣: %s)\n", modifyIndex,
                people[personIndex - 1].favoriteSongs[modifyIndex - 1].title,
                genre[modifyIndex - 1]);
            break;

        case 6:
            printf("��ȣ�ϴ� �帣�� �Է��ϼ��� (POP, �߶��, ����): ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }

    return 0;
}
