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
    strftime(time_buffer, sizeof(time_buffer), "%a %b %d %H:%M:%S %Y", time_info);

    // �ð� ���
    printf("%s\n", time_buffer);

    return 0;
}
