#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//自己参照構造体
typedef struct CELL
{
	char str[20];
	CELL *next;
}CELL;

//最後尾にセルを追加する関数
void Create(CELL *endCell, const char *buf, const int strSize);
//リストの一覧を表示する関数
void Index(CELL *endCell);

int main()
{
	const int strSize = 20;
	char str[strSize];
	//先頭に内容が空のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("好きなお寿司を入力してください\n_\n");
		scanf_s("%s", &str, 20);
		//最後尾にセルを追加
		Create(&head, str,strSize);
		//リスト一覧を表示
		Index(&head);
	}

	return 0;
}

void Create(CELL *endCell, const char *buf, const int strSize)
{
	/*Step1.新規にセルを追加*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, strSize, buf);
	newCell->next = nullptr;

	/*Step2.追加する前の最後尾を検索*/
	while (endCell->next !=NULL)
	{
		endCell = endCell->next;
	}

	/*Step3.追加する前の最後尾に新規セルのポインタを代入*/
	endCell->next = newCell;
}

void Index(CELL *endCell)
{
	printf("[");
	while (endCell->next != NULL)
	{
		//nextに何か値が入っている間出力
		endCell = endCell->next;
		printf("%s", endCell->str);
		if (endCell->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
}