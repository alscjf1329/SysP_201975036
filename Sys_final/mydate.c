<<<<<<< HEAD
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_string[50];

    // ���� �ð� ������ ������
    time(&current_time);
    time_info = localtime(&current_time);

    // ����ȭ�� �ð� ���ڿ��� ��ȯ
    strftime(time_string, sizeof(time_string), "%c", time_info);

    // ���
    printf("%s\n", time_string);

    return 0;
}
=======
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_buffer[80];

    // ���� �ð� ��������
    current_time = time(NULL);

    // ���� �ð����� ��ȯ
    time_info = localtime(&current_time);

    // ����ȭ�� �ð� ���ڿ� ����
    strftime(time_buffer, sizeof(time_buffer), "%a %b %e %H:%M:%S KST %Y", time_info);

    // �ð� ���
    printf("%s\n", time_buffer);

    return 0;
}
>>>>>>> 34e2fa90470725649cb1da6c75524f1676c5e646
