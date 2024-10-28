#include <stdio.h>

int squ[100][100] = { 0 }; //도화지
int dot[100][2] = { 0 }; //색종이를 붙인 위치
//[0]=x좌표 [1]=y좌표

void fill(int x, int y); //색종이가 있는 영역 표시
int search(void); //직사각형이 만들어질 수 있는 경우의 수
int cal(int x1, int x2, int y1, int y2); //직사각형의 넓이 계산
int main(void)
{
    int n, i, result;

    scanf(" %d", &n); //색종이의 수

    for (i = 0; i < n; i++)
    {
        scanf(" %d %d", &dot[i][0], &dot[i][1]); //색종이를 붙인 위치
        fill(dot[i][0], dot[i][1]); //색종이가 있는 영역 표시
    }

    result = search();

    printf("%d", result);

    return 0;
}
void fill(int x, int y) //색종이가 있는 영역 표시
{
    int i, j;

    for (i = x; i < (x + 10); i++)
    {
        for (j = y; j < (y + 10); j++)
            squ[i][j] = 1; //1로 채우기
    }
}
int search(void) //직사각형이 만들어질 수 있는 경우의 수
{
    int x1, x2, y1, y2, max = 100, sum;

    for (x1 = 0; x1 < 100; x1++)
    {
        for (y1 = 0; y1 < 100; y1++)
        {
            if (squ[x1][y1] == 1) //사각형의 시작점을 찾았을 때
            {
                for (x2 = x1; x2 < 100; x2++)
                {
                    for (y2 = y1; y2 < 100; y2++)
                    {
                        if (squ[x2][y2] == 1)
                        {
                            //x1부터 x2까지 y1부터 y2까지 모두 1이라고 가정한 넓이가
                            //현재 최대값보다 작거나 같을 경우
                            //cal 함수를 실행하지 않아도 된다. 
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
int cal(int x1, int x2, int y1, int y2) //직사각형의 넓이 계산
{
    int i, j, sum = 0;

    for (i = x1; i <= x2; i++)
    {
        for (j = y1; j <= y2; j++)
        {
            if (squ[i][j] == 0) //사각형이 끊기면 0반홤
                return 0;

            sum++; //사각형의 넓이
        }
    }

    return sum;
}
