//231630 �赵�� �÷��̸���Ʈ ������Ʈ
#include <stdio.h>
#define MAX_SONGS 10
#define SONG_LEN 100
#include <string.h>

char songs[MAX_SONGS][SONG_LEN] = { "" }; // �뷡 ����� �����ϱ� ���� 2���� �迭
int songCount = 0; // �뷡�� ���� ����

void addSong(char song[]) { //�뷡�� ��Ͽ� �߰��ϴ� �Լ�
    printf("�뷡�� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
    scanf_s("%s", song, (int)sizeof(song));
    strcpy_s(songs[songCount], sizeof(songs[songCount]), song);
    printf("�뷡 ""%s""�� �߰��Ǿ����ϴ�\n\n", song);
}


 void printsonglist(int songCount){ //�������� ����ϴ� �Լ�

     for (int i = 0; i < songCount; i++) {
         printf("%d. %s \n", i + 1, songs[i]);
     }
 printf("\n");

 }
int main() {
    printf("���� �÷��̸���Ʈ ����! \n");

    while (1) {
        int choice = 0; // ����� �Է� �޴��� �����ϱ� ���� ����

        // ����ڿ��� �޴��� ����ϰ�, �޴��� �Է¹ޱ�
        printf("------------------\n");
        printf("�޴��� �Է����ּ���.\n");
        printf("1. �����Ͽ� �뷡 �߰�\n2. �뷡 ����\n3. ������\n4. ����\n5. �뷡 ����\n");
        printf("���� �뷡 �� = %d\n", songCount);
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
            printf("������ \n");
            printsonglist(songCount);
            break;
       
        case 4:
            end = 1;
            break;
       
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }

        if (end == 1) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        if (songCount == 10) {
            printf("�뷡�� %d���� �� á���ϴ�.", songCount);
            break;
        }
    }
    return 0;
}
