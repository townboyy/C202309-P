//231630 �赵�� �÷��̸���Ʈ ������Ʈ ��������

#include <stdio.h>
#include <stdlib.h>
#include "play_list_project_main.h"

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

