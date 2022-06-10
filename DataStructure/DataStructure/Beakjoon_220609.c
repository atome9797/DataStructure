#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int day(int A, int B , int V)
{

	V = V - A;

	if (V <= 0)
	{
		return 1;
	}

	return 1 + day(A , B, V + B);

}

int main()
{
	int A = 0;
	int B = 0;
	int V = 0;

	//scanf("%d %d %d", &A, &B, &V);

	//int count = 1;
	//while (1)
	//{
	//	V = V - A;

	//	if (V <= 0)
	//	{
	//		break;
	//	}

	//	V = V + B;
	//	count++;

	//}

	//int sum = (V - A) / (A - B);
	//int sum2 = (V - A) % (A - B);
	//if (sum2 != 0) {
	//	sum++;
	//}

	//printf("%d\n", sum + 1);

	//printf("%d", count);


	/*int result = day(A, B, V);
	printf("%d", result);*/


	//10250
	//int T = 0;
	//scanf("%d", &T);
	//
	////T개수 만큼 반복
	//for (int i = 0; i < T; i++)
	//{
	//	int H;
	//	int W;
	//	int N;
	//	scanf("%d %d %d", &H, &W, &N);

	//	//1 ~ 6 : 1
	//	//6 6 
	//	//나머지
	//	int num1 = N / H; //1
	//	int num2 = N % H; //0


	//	if (N / H == 0) {
	//		num1 = num1 + 1;
	//	}
	//	else if (N / H != 0 && num2 != 0) {
	//		num1 = num1 + 1;
	//	}

	//	if (num2 == 0) {
	//		num2 = H;
	//	}


	//	int sum = num2 * 100;
	//	sum = sum + num1;

	//	printf("%d\n", sum);
	//}


	//부녀 회장
	//입력
	// 1. 테스트 캐이스와 테스트 케이스에 따른 k층과 n호를 입력 받는다.
	int test_case = 0;
	scanf("%d", &test_case);

	//처리
	// 1.  
	for (int i = 0; i < test_case; i++)
	{
		int k = 0;
		int n = 0;

		scanf("%d", &k);
		scanf("%d", &n);

		if (k == 0) {
			printf("%d\n", n);
			continue;
		}

		int department[14][14];
		for (int i = 1; i <= 14; i++)
		{
			department[0][i] = i; //0층
		}



		for (int i = 0; i <= 14; i++)
		{
			for (int j = 0; j <= 14; j++)
			{
				for (int k = 0; k < j; k++)
				{
					department[i][j] += department[i][k];
				}
			}
		}

	}
	//출력


	return 0;
}