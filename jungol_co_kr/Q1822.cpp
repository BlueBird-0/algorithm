#include <stdio.h>

int num_count(int a, int b, int d, int n);
int main(void)
{
    int a, b, d, n;
    int num;
    //a=��ü�� �Ǵ� ��  b=���̻� ��ü�� ������ �ʴ� �� d=�״� �� n=��¥

    scanf(" %d %d %d %d", &a, &b, &d, &n);

    num = num_count(a, b, d, n);

    printf("%d", num % 1000);

    return 0;
}
int num_count(int a, int b, int d, int n)
{
    int cnt = 2, adult, birth[10001] = { 0 };
    int i, k;

    birth[1] = 1; //ù°�� �¾ ¤�Ź���
    birth[a + 1] = 1; //a��° �� �¾ ¤�� ����
    k = a + 2; //birth�迭 ���ȣ
    adult = 1; //���� ��ü ��

    for (i = a + 2; i <= (n + 1); i++)
    {
        if (k > d)
            k = 1;

        //¤�Ź��� ���� 
        if (i > d)
        {
            cnt -= birth[k] % 1000;
            birth[k] = 0;
        }

        //��ü�� �� ¤�� ����
        if (k > a)
        {
            adult += birth[k - a] % 1000;
        }
        else
        {
            adult += birth[d - (a - k)] % 1000;
        }

        //���̻� �������� �ʴ� ¤�Ź���
        if (k > b && i >= b)
        {
            adult -= birth[k - b] % 1000;
        }
        else if (k <= b && i >= b)
        {
            adult -= birth[d - (b - k)] % 1000;
        }

        birth[k++] = adult % 1000; //���� �¾ ¤�� ����

        cnt += adult % 1000; //¤�Ź��� �� ����
    }


    //while(cnt>1000) cnt=cnt-1000;

    return cnt;
}