#include <stdio.h>

int num_count(int a, int b, int d, int n);
int main(void)
{
    int a, b, d, n;
    int num;
    //a=성체가 되는 날  b=더이상 개체를 만들어내지 않는 날 d=죽는 날 n=날짜

    scanf(" %d %d %d %d", &a, &b, &d, &n);

    num = num_count(a, b, d, n);

    printf("%d", num % 1000);

    return 0;
}
int num_count(int a, int b, int d, int n)
{
    int cnt = 2, adult, birth[10001] = { 0 };
    int i, k;

    birth[1] = 1; //첫째날 태어난 짚신벌레
    birth[a + 1] = 1; //a번째 날 태어난 짚신 벌레
    k = a + 2; //birth배열 방번호
    adult = 1; //현재 성체 수

    for (i = a + 2; i <= (n + 1); i++)
    {
        if (k > d)
            k = 1;

        //짚신벌레 죽음 
        if (i > d)
        {
            cnt -= birth[k] % 1000;
            birth[k] = 0;
        }

        //성체가 된 짚신 벌레
        if (k > a)
        {
            adult += birth[k - a] % 1000;
        }
        else
        {
            adult += birth[d - (a - k)] % 1000;
        }

        //더이상 번식하지 않는 짚신벌레
        if (k > b && i >= b)
        {
            adult -= birth[k - b] % 1000;
        }
        else if (k <= b && i >= b)
        {
            adult -= birth[d - (b - k)] % 1000;
        }

        birth[k++] = adult % 1000; //새로 태어난 짚신 벌레

        cnt += adult % 1000; //짚신벌레 수 증가
    }


    //while(cnt>1000) cnt=cnt-1000;

    return cnt;
}