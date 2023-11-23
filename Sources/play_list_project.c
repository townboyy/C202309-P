//231630 �赵�� �÷��̸���Ʈ ������Ʈ
#include <stdio.h>
#define MAX_SONGS 10
#define SONG_LEN 100
#include <string.h>

char songs[MAX_SONGS][SONG_LEN] = { "" }; // �뷡 ����� �����ϱ� ���� 2���� �迭
int songCount = 0; // �뷡�� ���� ����

void addSong(char song[]) { //�뷡�� ��Ͽ� �߰��ϴ� �Լ�
    printf("�뷡�� �Է��ϼ��� : ");
    scanf_s("%s", song, (int)sizeof(song));
    strcpy_s(songs[songCount], sizeof(songs[songCount]), song);
    printf("�뷡 ""%s""�� �߰��Ǿ����ϴ�\n\n", song);


}

void delsong(int delindex, int songCount) {
    printf("% d. % s : �뷡�� �����մϴ�.\n", delindex, songs[delindex - 1]);
    for (int i = delindex; i < songCount + 1; i++) {

        strcpy_s(songs[i - 1], sizeof(songs[i]), songs[i]);
    }
}


 void printsonglist(int songCount){ //�������� ����ϴ� �Լ�

     for (int i = 0; i < songCount; i++) {
         printf("%d. %s \n", i + 1, songs[i]);
     }
 printf("\n");

 }
int main() {
    printf("���� �÷��̸���Ʈ ����!@#$$% \n");

    while (1) { //1�� �׻� �� > �׻� �ݺ�
        int choice = 0; // ����� �Է� �޴��� �����ϱ� ���� ����

        // ����ڿ��� �޴��� ����ϰ�, �޴��� �Է¹ޱ�
        printf("------------------\n");
        printf("�޴��� �Է����ּ���.\n");
        printf("1. �����Ͽ� �뷡 �߰�\n2. �뷡 ����\n3. ������\n4. ����\n5. �뷡 ����\n");
        printf("���� �뷡 �� = %d\n", songCount);
        printf("------------------\n");
        scanf_s("%d", &choice);

        int end = 0;
        int delindex = -1;
        char ch;
        int modifyindex = 0;
        
        switch (choice) {// �Է¹޴� choice�� ���� �� �� ������
        case 1:
            addSong(songs[songCount]); //�뷡�߰� �Լ� ȣ��
            songCount++;
            break;

        case 2:
           
            printf("������ �뷡�� �ε����� �Է��ϼ��� : ");
            scanf_s("%d", &delindex);
            if (delindex > songCount || delindex <= 0) {
                printf("���� ������ ������ϴ�.\n");
            }
            else {
                delsong(delindex, songCount);
                songCount -= 1;
            }
            break;

        case 3:
            printf("������ \n");
            printsonglist(songCount);//����������Լ� ȣ��
            break;
       
        case 4: //���� ����
            end = 1;
            break;
        
        case 5:
            printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
            scanf_s("%d", &modifyindex);
            ch = getchar();
            printf("���ο� �� ���� �Է����ּ���");
            scanf_s("%s", songs[modifyindex - 1], (int)sizeof(songs[modifyindex - 1]));
            printf("���ο� �� ���� �߰��Ǿ����ϴ�: %d. %s\n", modifyindex, songs[modifyindex - 1]);
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
