#include <stdio.h>
#include <stdlib.h>

//自己参照構造体
typedef struct CELL
{
	int val;
	CELL *next;
}CELL;

//最後尾にセルを追加する関数
void Create(CELL *endCell,int val);
//リストの一覧を表示する関数
void Index(CELL *endCell);

int main()
{
	int val;
	//先頭に内容が空のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%d", &val);
		//最後尾にセルを追加
		Create(&head, val);
		//リスト一覧を表示
		Index(&head);
	}

	return 0;
}

void Create(CELL *endCell, int val)
{
	/*Step1.新規にセルを追加*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
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
		printf("%d", endCell->val);
		if (endCell->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
}