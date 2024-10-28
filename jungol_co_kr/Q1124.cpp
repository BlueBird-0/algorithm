#include <stdio.h>

int squ[100][100] = { 0 }; //��ȭ��
int dot[100][2] = { 0 }; //�����̸� ���� ��ġ
//[0]=x��ǥ [1]=y��ǥ

void fill(int x, int y); //�����̰� �ִ� ���� ǥ��
int search(void); //���簢���� ������� �� �ִ� ����� ��
int cal(int x1, int x2, int y1, int y2); //���簢���� ���� ���
int main(void)
{
    int n, i, result;

    scanf(" %d", &n); //�������� ��

    for (i = 0; i < n; i++)
    {
        scanf(" %d %d", &dot[i][0], &dot[i][1]); //�����̸� ���� ��ġ
        fill(dot[i][0], dot[i][1]); //�����̰� �ִ� ���� ǥ��
    }

    result = search();

    printf("%d", result);

    return 0;
}
void fill(int x, int y) //�����̰� �ִ� ���� ǥ��
{
    int i, j;

    for (i = x; i < (x + 10); i++)
    {
        for (j = y; j < (y + 10); j++)
            squ[i][j] = 1; //1�� ä���
    }
}
int search(void) //���簢���� ������� �� �ִ� ����� ��
{
    int x1, x2, y1, y2, max = 100, sum;

    for (x1 = 0; x1 < 100; x1++)
    {
        for (y1 = 0; y1 < 100; y1++)
        {
            if (squ[x1][y1] == 1) //�簢���� �������� ã���� ��
            {
                for (x2 = x1; x2 < 100; x2++)
                {
                    for (y2 = y1; y2 < 100; y2++)
                    {
                        if (squ[x2][y2] == 1)
                        {
                            //x1���� x2���� y1���� y2���� ��� 1�̶�� ������ ���̰�
                            //���� �ִ밪���� �۰ų� ���� ���
                            //cal �Լ��� �������� �ʾƵ� �ȴ�. 
                            if ((x2 - x1 + 1) * (y2 - y1 + 1) <= max)
                                continue;

                            sum = cal(x1, x2, y1, y2);

                            if (sum > max)
                                max = sum;
                        }
                    }
                }
            }
        }
    }

    return max;
}
int cal(int x1, int x2, int y1, int y2) //���簢���� ���� ���
{
    int i, j, sum = 0;

    for (i = x1; i <= x2; i++)
    {
        for (j = y1; j <= y2; j++)
        {
            if (squ[i][j] == 0) //�簢���� ����� 0���c
                return 0;

            sum++; //�簢���� ����
        }
    }

    return sum;
}
