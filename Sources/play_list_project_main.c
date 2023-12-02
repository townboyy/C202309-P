//231630 �赵�� �÷��̸���Ʈ ������Ʈ
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10 //�÷��̸���Ʈ �뷡 ���� 10�� ����
#define SONG_LEN 100 //�뷡 ���� ���� 
#define GENRE_NAME 100 //�帣 �̸�
#define GENRE_NUM 3 //�帣 ����
#define PERSON_COUNT 5 //�̿��� ��




char genre[GENRE_NUM][GENRE_NAME] = { "POP", "�߶��", "����" }; //�ϴ� �帣 3���� ����
char songs[MAX_SONGS][SONG_LEN] = { "" }; //�뷡������ �Է¹޴� 2���� �迭
int songCount[PERSON_COUNT] = { 0 }; //�̿��� 5���� �뷡 ���� ���� ����

char peopleNames[PERSON_COUNT][50]; //�̿����� �̸��� �Է¹޴� ����
char peopleFavoriteGenres[PERSON_COUNT][GENRE_NAME]; //�̿����� ��ȣ�ϴ� �帣�� �Է¹޴� 2���� �迭
char peopleFavoriteSongs[PERSON_COUNT][MAX_SONGS][SONG_LEN]; //������� ��ȣ�뷡�� �Է¹޴� 3���� �迭


void addSong(char song[], char songGenre[], int personIndex, int delIndex) {
    printf("�뷡�� �Է��ϼ���: ");
    scanf_s("%s", song, (int)sizeof(song));
    
for(int i = 0;i<songCount[personIndex];i++){

    if (strcmp(peopleFavoriteSongs[personIndex][i], song)==0) {
        printf("�̹� �����Ͽ� �ִ� �뷡�Դϴ�. �ٸ� �뷡�� �Է��ϼ���\n");
        for (int i = delIndex; i < songCount[personIndex]; i++) {
            strcpy_s(peopleFavoriteSongs[personIndex][i - 1], sizeof(peopleFavoriteSongs[personIndex][i]), peopleFavoriteSongs[personIndex][i]);
        }
        songCount[personIndex]--;
    }
}
    strcpy_s(peopleFavoriteSongs[personIndex][songCount[personIndex]], sizeof(peopleFavoriteSongs[personIndex][songCount[personIndex]]), song);

    // �Է��� �뷡�� �帣�� ����ڰ� ��ȣ�ϴ� �帣�� ����
    strcpy_s(peopleFavoriteGenres[personIndex], sizeof(peopleFavoriteGenres[personIndex]), songGenre);

    printf("'%s' �뷡�� '%s' �帣�� �߰��Ǿ����ϴ�.\n\n", song, songGenre);

    songCount[personIndex]++;
}

void delSong(int delIndex, int personIndex) {
    printf("%d. %s : �뷡�� �����մϴ�.\n", delIndex, peopleFavoriteSongs[personIndex][delIndex - 1]);
    for (int i = delIndex; i < songCount[personIndex]; i++) {
        strcpy_s(peopleFavoriteSongs[personIndex][i - 1], sizeof(peopleFavoriteSongs[personIndex][i]), peopleFavoriteSongs[personIndex][i]);
    }
    songCount[personIndex]--;
}

void printSongList(int personIndex) {
    printf("������ for %s:\n", peopleNames[personIndex]);
    for (int i = 0; i < songCount[personIndex]; i++) {
        printf("%d. %s (�帣: %s)\n", i + 1, peopleFavoriteSongs[personIndex][i], peopleFavoriteGenres[personIndex]);
    }
    printf("\n");
}

void recommendSong(char inputGenre[]) {
    printf("\n'%s'�� ����� �帣�� �뷡�� ��õ�մϴ�:\n", inputGenre);

    

    for (int i = 0; i < PERSON_COUNT; i++) {
      
        if (strcmp(inputGenre, peopleFavoriteGenres[i]) == 0) {
           
            for (int j = 0; j < songCount[i]; j++) {
                printf("'%s' ��õ �뷡 for %s: %s (�帣: %s)\n", inputGenre, peopleNames[i], peopleFavoriteSongs[i][j], inputGenre);
            }
        }
    }

   
}














int main() {
    int choice = 0; //�޴� �Է¹��� ����
    int end = 0; //���� ����
    int delIndex = -1; //������ ���� ����
    char ch; //���� ����..?
    int modifyIndex = 0; //������ ���� ����
    char inputGenre[GENRE_NAME] = "";//�帣�̸��� �Է¹��� ����
    int genreCount[GENRE_NUM] = { 0 }; // �� �帣�� ���� Ƚ���� �����ϴ� �迭

    

    

    // �� �̿����� ���� �Է�
    for (int i = 0; i < PERSON_COUNT; i++) {
        printf("����� %d, �̸��� �Է��ϼ���: ", i + 1);
        scanf_s("%s", peopleNames[i], (int)sizeof(peopleNames[i]));
    }
        printf("���� �÷��̸���Ʈ ����!\n");
    
    while (1) {
        printf("------------------\n");
        printf("�޴��� �Է����ּ���.\n");
        printf("1. �����Ͽ� �뷡 �߰�\n2. �뷡 ����\n3. ������\n4. ����\n5. �뷡 ����\n6. ����� �뷡 �ѷ�����\n7.���� �α��ִ� �帣\n");
        printf("���� �뷡 �� = %d\n", songCount[0]);  // ���⼭�� ù ��° ����� �뷡 ���� ǥ��

        printf("------------------\n");
        scanf_s("%d", &choice); //������ �޴� �Է¹���

        switch (choice) { //�Է¹޴� CHOICE�� ���� �ϴ� ���� ���ǹ��� ���� �з�
        case 1:
            printf("����ڸ� �����ϼ��� (1~5): ");
            int personIndex;
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            printf("�뷡�� �帣�� �Է��ϼ��� (POP, �߶��, ����): ");
            scanf_s("%s", inputGenre, (int)sizeof(inputGenre));
            addSong(peopleFavoriteSongs[personIndex - 1][songCount[personIndex - 1] % MAX_SONGS], inputGenre, personIndex - 1, delIndex);

            break;

        case 2:
            printf("����ڸ� �����ϼ��� (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            printf("������ �뷡�� �ε����� �Է��ϼ��� : ");
            scanf_s("%d", &delIndex);
            if (delIndex > songCount[personIndex - 1] || delIndex <= 0) {
                printf("������ �뷡�� �����ϴ�.\n");
            }
            else {
                delSong(delIndex, personIndex - 1);
            }
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
            end = 1;
            break;

        case 5:
            printf("����ڸ� �����ϼ��� (1~5): ");
            scanf_s("%d", &personIndex);

            if (personIndex <= 0 || personIndex > PERSON_COUNT) {
                printf("�߸��� �����Դϴ�.\n");
                break;
            }

            printf("������ �뷡�� ��ȣ�� �Է����ּ���. (1���� ����): ");
            scanf_s("%d", &modifyIndex);
            ch = getchar();
            printf("���Ӱ� �߰��� �뷡�� �Է����ּ���: ");
            scanf_s("%s", peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], (int)sizeof(peopleFavoriteSongs[personIndex - 1][modifyIndex - 1]));
            printf("���ο� �뷡�� �߰��Ǿ����ϴ�: %d. %s (�帣: %s)\n", modifyIndex, peopleFavoriteSongs[personIndex - 1][modifyIndex - 1], genre[modifyIndex - 1]);
            break;

        case 6:
            printf("��ȣ�ϴ� �帣�� �Է��ϼ��� (POP, �߶��, ����): ");
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

            // ���� �α� �ִ� �帣�� ���
            printf("���� �α��ִ� �帣: %s\n", genre[popularIndex]);
            break;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }

        if (end == 1) {
            printf("�������� �����մϴ�.\n");
            break;
        }
        if (songCount[0] == MAX_SONGS) {
            printf("�뷡�� %d���� �� á���ϴ�.\n", songCount[0]);
            break;
        }
       
        

       
     
    }
   
    
    
    return 0;
   
}
