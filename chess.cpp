#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//���̸��Ǻ���������
void chessBoard(int**,int, int, int, int, int);
int main()
{
	int k,row,col;                               //���̵Ĺ����2^k*2^k,���ⷽ��λ�����̡�row����col����λ��

	printf("Please input k = \n");
	scanf("%d",&k);

	printf("Please input row = \n");
	scanf("%d", &row);

	printf("Please input col = \n");
	scanf("%d", &col);

	int n = (int)pow(2.0,k);                                 //���̵Ĵ�С��n*n

	int **chess = (int **)malloc(sizeof(int *)*n);           //�����̶�̬����ռ�
	for (int i = 0; i < n; i++)                              //�����̵�ÿһ�����ʼ��Ϊ-1�����ⷽ��Ϊ0
	{
		chess[i] = (int *)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++)
		{
			chess[i][j] = -1;
		}
	}
	chess[row][col] = 0;
	chessBoard(chess,0, 0, row, col, n);                     //���ø������̵ĺ��������������ǳ�ʼ���õ����̡����ⷽ���λ���Լ����̵Ĵ�С
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", chess[i][j]);                      //������L�ι��Ƹ��Ǻ�����̽�����
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		free(chess[i]);
	}
	free(chess);
	return 0;
}
/*
**chess�ǳ�ʼ���õ�����
br���������ϽǺ�����
bc���������Ͻ�������
dr�����ⷽ��ĺ�����
dc�����ⷽ��������� 
size�����̵Ĵ�С
*/

void chessBoard(int** chess,int br, int bc, int dr, int dc, int size)
{
	if (size == 1)                                           //�����̵ݹ鵽ֻ��һ������ʱ���˳��ݹ����
	{
		return;
	}
	int s = size / 2;
	static int d = 0;
	int t = ++d;

	if (dr < br + s && dc < bc + s) //���ⷽ�������Ͻ�������
	{
		chessBoard(chess,br, bc, dr, dc, s);
	}
	else   // ������ⷽ���ڴ����̣������������½���Ϊ��Ӧ�Ĺ��ƺ�
	{
		chess[br + s - 1][bc + s - 1] = t;
		chessBoard(chess,br, bc, br + s - 1, bc + s - 1, s);    //���±�ŵķ�����Ϊ���ⷽ�񣬲��������кŴ��˺���
	}

	if (dr >= br + s && dc >= bc + s) //���ⷽ�������½�������
	{
		chessBoard(chess,br + s, bc + s, dr, dc, s);
	}
	else   // ������ⷽ���ڴ����̣������������Ͻ���Ϊ��Ӧ�Ĺ��ƺ�
	{
		chess[br + s][bc + s] = t;
		chessBoard(chess,br + s, bc+ s, br + s, bc + s, s);    //���±�ŵķ�����Ϊ���ⷽ�񣬲��������кŴ��˺���
	}

	if (dr < br + s && dc >= bc + s)//���ⷽ�������Ͻ�������
	{
		chessBoard(chess, br, bc + s, dr, dc, s);
	}
	else   // ������ⷽ���ڴ����̣������������½���Ϊ��Ӧ�Ĺ��ƺ�
	{
		chess[br + s - 1][bc + s] = t;
		chessBoard(chess, br, bc + s,br+s-1,bc+s,s );       //���±�ŵķ�����Ϊ���ⷽ�񣬲��������кŴ��˺���
	}
	if (dr >= br + s && dc < bc + s)//���ⷽ�������½�������
	{
		chessBoard(chess ,br + s, bc,dr,dc, s);
	}
	else  // ������ⷽ���ڴ����̣������������Ͻ���Ϊ��Ӧ�Ĺ��ƺ�
	{
		chess[br + s][bc + s - 1] = t;
		chessBoard(chess, br + s, bc, br + s, bc + s - 1, s);      //���±�ŵķ�����Ϊ���ⷽ�񣬲��������кŴ��˺���
	}

}
