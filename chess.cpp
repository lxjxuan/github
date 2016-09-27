#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//棋盘覆盖函数的声明
void chessBoard(int**,int, int, int, int, int);
int main()
{
	int k,row,col;                               //棋盘的规格是2^k*2^k,特殊方格位于棋盘【row】【col】的位置

	printf("Please input k = \n");
	scanf("%d",&k);

	printf("Please input row = \n");
	scanf("%d", &row);

	printf("Please input col = \n");
	scanf("%d", &col);

	int n = (int)pow(2.0,k);                                 //棋盘的大小是n*n

	int **chess = (int **)malloc(sizeof(int *)*n);           //给棋盘动态分配空间
	for (int i = 0; i < n; i++)                              //将棋盘的每一个格初始化为-1，特殊方格为0
	{
		chess[i] = (int *)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++)
		{
			chess[i][j] = -1;
		}
	}
	chess[row][col] = 0;
	chessBoard(chess,0, 0, row, col, n);                     //调用覆盖棋盘的函数，函数参数是初始化好的棋盘、特殊方格的位置以及棋盘的大小
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", chess[i][j]);                      //将经过L形骨牌覆盖后的棋盘结果输出
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
**chess是初始化好的棋盘
br是棋盘左上角横坐标
bc是棋盘左上角纵坐标
dr是特殊方格的横坐标
dc是特殊方格的纵坐标 
size是棋盘的大小
*/

void chessBoard(int** chess,int br, int bc, int dr, int dc, int size)
{
	if (size == 1)                                           //当棋盘递归到只有一个方格时，退出递归过程
	{
		return;
	}
	int s = size / 2;
	static int d = 0;
	int t = ++d;

	if (dr < br + s && dc < bc + s) //特殊方格在左上角子棋盘
	{
		chessBoard(chess,br, bc, dr, dc, s);
	}
	else   // 如果特殊方格不在此棋盘，将此棋盘右下角设为相应的骨牌号
	{
		chess[br + s - 1][bc + s - 1] = t;
		chessBoard(chess,br, bc, br + s - 1, bc + s - 1, s);    //将新标号的方格作为特殊方格，并将其行列号传人函数
	}

	if (dr >= br + s && dc >= bc + s) //特殊方格在右下角子棋盘
	{
		chessBoard(chess,br + s, bc + s, dr, dc, s);
	}
	else   // 如果特殊方格不在此棋盘，将此棋盘左上角设为相应的骨牌号
	{
		chess[br + s][bc + s] = t;
		chessBoard(chess,br + s, bc+ s, br + s, bc + s, s);    //将新标号的方格作为特殊方格，并将其行列号传人函数
	}

	if (dr < br + s && dc >= bc + s)//特殊方格在右上角子棋盘
	{
		chessBoard(chess, br, bc + s, dr, dc, s);
	}
	else   // 如果特殊方格不在此棋盘，将此棋盘左下角设为相应的骨牌号
	{
		chess[br + s - 1][bc + s] = t;
		chessBoard(chess, br, bc + s,br+s-1,bc+s,s );       //将新标号的方格作为特殊方格，并将其行列号传人函数
	}
	if (dr >= br + s && dc < bc + s)//特殊方格在左下角子棋盘
	{
		chessBoard(chess ,br + s, bc,dr,dc, s);
	}
	else  // 如果特殊方格不在此棋盘，将此棋盘右上角设为相应的骨牌号
	{
		chess[br + s][bc + s - 1] = t;
		chessBoard(chess, br + s, bc, br + s, bc + s - 1, s);      //将新标号的方格作为特殊方格，并将其行列号传人函数
	}

}
