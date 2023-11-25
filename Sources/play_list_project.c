//231630 �赵�� �÷��̸���Ʈ ������Ʈ
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10
#define SONG_LEN 100
#define GENRE_NAME 100
#define GENRE_NUM 3

char genre[GENRE_NUM][GENRE_NAME] = { "POP", "�߶��", "����" }; //�帣�� �����ϱ� ���� 2���� �迭
char songs[MAX_SONGS][SONG_LEN] = { "" }; // �뷡 ����� �����ϱ� ���� 2���� �迭
int songCount = 0; // �뷡�� ���� ����

void addSong(char song[], char songGenre[]) { // �뷡�� ��Ͽ� �߰��ϴ� �Լ�, �뷡�� �帣�� �Բ� ����
    printf("�뷡�� �Է��ϼ���: ");
    scanf_s("%s", song, (int)sizeof(song));
    strcpy_s(songs[songCount], sizeof(songs[songCount]), song);


    strcpy_s(genre[songCount], sizeof(genre[songCount]), songGenre);

    printf("'%s' �뷡�� '%s' �帣�� �߰��Ǿ����ϴ�.\n\n", song, songGenre);

    songCount++;
}

void delsong(int delindex, int songCount) {
    printf("%d. %s : �뷡�� �����մϴ�.\n", delindex, songs[delindex - 1]);
    for (int i = delindex; i < songCount; i++) {
        strcpy_s(songs[i - 1], sizeof(songs[i]), songs[i]);
        strcpy_s(genre[i - 1], sizeof(genre[i]), genre[i]); //�뷡�� �����ϸ� �� �뷡�� �帣������ ����
    }
}

void printsonglist(int songCount) { // �������� ����ϴ� �Լ�
    printf("������:\n");
    for (int i = 0; i < songCount; i++) {
        printf("%d. %s (�帣: %s)\n", i + 1, songs[i], genre[i]); //�ε��� ���� �帣�� �Բ� ���
    }
    printf("\n");
}

void recommendSong(char inputgenre[]) { //�帣 ��õ �Լ� > ���ϴ� �帣�� �Է��ϸ� ���� �帣�� �뷡�� ��õ����
    printf("\n'%s'�� ����� �帣�� �뷡�� ��õ�մϴ�:\n", inputgenre);

    for (int i = 0; i < songCount; i++) {
        if (strcmp(inputgenre, genre[i]) == 0) {
            printf("'%s' ��õ �뷡: %s (�帣: %s)\n", inputgenre, songs[i], genre[i]);
        }
    }
}

int main() {
    int choice = 0; // ����� �Է� �޴��� �����ϱ� ���� ����
    int end = 0;
    int delindex = -1;
    char ch;
    int modifyindex = 0;
    char inputgenre[GENRE_NAME] = "";

    printf("���� �÷��̸���Ʈ ����!\n");

    while (1) {
        printf("------------------\n");
        printf("�޴��� �Է����ּ���.\n");
        printf("1. �����Ͽ� �뷡 �߰�\n2. �뷡 ����\n3. ������\n4. ����\n5. �뷡 ����\n6. ����� �뷡 �ѷ�����\n");
        printf("���� �뷡 �� = %d\n", songCount);
        printf("------------------\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�뷡�� �帣�� �Է��ϼ��� (POP, �߶��, ����): ");
            scanf_s("%s", inputgenre, (int)sizeof(inputgenre));
            addSong(songs[songCount], inputgenre); // �뷡 �߰� �Լ� ȣ��
            break;

        case 2:
            printf("������ �뷡�� �ε����� �Է��ϼ��� : ");
            scanf_s("%d", &delindex);
            if (delindex > songCount || delindex <= 0) {
                printf("������ �뷡�� �����ϴ�.\n");
            }
            else {
                delsong(delindex, songCount);
                songCount -= 1;
            }
            break;

        case 3:
            printsonglist(songCount); // ������ ��� �Լ� ȣ��
            break;

        case 4:
            end = 1;
            break;

        case 5:
            printf("������ �뷡�� ��ȣ�� �Է����ּ���. (1���� ����): ");
            scanf_s("%d", &modifyindex);
            ch = getchar();
            printf("���Ӱ� �߰��� �뷡�� �Է����ּ���: ");
            scanf_s("%s", songs[modifyindex - 1], (int)sizeof(songs[modifyindex - 1]));
            printf("���ο� �뷡�� �߰��Ǿ����ϴ�: %d. %s (�帣: %s)\n", modifyindex, songs[modifyindex - 1], genre[modifyindex - 1]);
            break;

        case 6:
            printf("��ȣ�ϴ� �帣�� �Է��ϼ��� (POP, �߶��, ����): ");
            scanf_s("%s", inputgenre, (int)sizeof(inputgenre));
            recommendSong(inputgenre); //�帣��õ �Լ� ȣ��
            break;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }

        if (end == 1) {
            printf("�������� �����մϴ�.\n");
            break;
        }
        if (songCount == 10) {
            printf("�뷡�� %d���� �� á���ϴ�.\n", songCount);
            break;
        }
    }
    return 0;
}

