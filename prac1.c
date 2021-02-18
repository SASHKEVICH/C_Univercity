#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct Node {
	int number; // область данных
	struct Node *next; // ссылка на следующий узел
};
typedef struct Node *PNode;
PNode CreateNode (PNode Head, float newNumber)
{
	PNode NewNode = (PNode)malloc(sizeof(struct Node)); // указатель на новый узел
	NewNode->number = newNumber; // записать число
	NewNode->next = NULL; // следующего узла нет
	if (Head == NULL) return NewNode;
	PNode temp = Head;
	while (temp->next) temp = temp->next;
	temp->next = NewNode;
	return Head; // результат функции - адрес узла
}
void AddAfter (PNode p, PNode NewNode)
{
	NewNode->next = p->next;
	p->next = NewNode;
}
void ReadNode (PNode Head) {
	int path;
	PNode q = Head;
	while (q != NULL) {
		printf ("%8d", q->number);
		q = q->next;
	}
}
PNode FindNeg (PNode Head)
{
	PNode q = Head;
	while (q && q->number >= 0) {
		if (!q->next) break;
		q = q->next;
	}
	if (q->number < 0) return q;
	else return;
}
void DeleteNode(PNode *Head, PNode OldNode)
{
	PNode q = *Head;
	if (*Head == OldNode)
	*Head = OldNode->next; // удаляем первый элемент
	else {
	while (q && q->next != OldNode) // ищем элемент
	q = q->next;
	if ( q == NULL ) return; // если не нашли, выход
	q->next = OldNode->next;
	}
	free (OldNode); // освобождаем память
}
void createFile (char *name, int n) {
	int i;
	FILE *f = fopen (name, "wb");
	if (f == NULL){
		printf ("Ошибка создания файла. \n");
		system ("pause");
		return;
	}
	fwrite(&n, sizeof(int), 1, f);
	for (i = 0; i < n; i++) {
		float z = rand()%200-rand()%70;
		fwrite(&z, sizeof(float), 1, f);
	}
	fclose(f);
}
void readFileInList (char *name) {
	FILE *f = fopen(name, "rb");
	if (f == NULL) {
		printf ("Файл не найден. \n");
		system ("pause");
		return;
	}
	int i = 0;
	float z;
	int n;
	fread(&n, sizeof(int), 1, f);
	while (!feof(f)) {
		if (fread(&z, sizeof(float), 1, f) != 1) break;
		printf("%8.3f", z);
		i++;
	}
	fclose(f);
}
void Warning (int p, int count) {
	if (p != count) {
		printf("Ошибка ввода значений!");
		system ("pause");
		return;
	}
}
int main () {
	system ("chcp 1251 >0");
	srand(time(NULL));
	printf ("\nВариант 25.\n");
	PNode *L = NULL;
	PNode Head = NULL;
	int i, p, num;
	char Fname[30];
	printf ("\nВведите имя создаваемого файла: ");
	p = scanf ("%s", Fname);
	Warning (p, 1);
	printf ("\nВведите количество элементов списка: \n");
	p = scanf ("%d", &num);
	if (num <= 0) {
		printf("Ошибка ввода значений!");
		system ("pause");
		return 1;
	}
	Warning (p, 1);
	createFile (Fname, num);
	for (i = 0; i < num; i++) {
		int temp;
		FILE *f = fopen(Fname, "rb");
		if (f == NULL) {
			printf ("Файл не найден. \n");
			system ("pause");
			return;
		}
		float z;
		int u = sizeof(int);
 		fseek(f, u,SEEK_SET);
		while (!feof(f)) {
			if (fread(&z, sizeof(float), 1, f) != 1) break;
			Head = CreateNode (Head, z);
			i++;
		}
		fclose(f);
	}
	printf ("\nВсе элементы начального списка: \n");
	ReadNode (Head);
	PNode delNode = FindNeg (Head);
	L = &Head;
	DeleteNode (L, delNode);
	Head = *L;
	printf ("\nИзменённый список: \n");
	ReadNode (Head);
	printf ("\nВыполнил Стародубцев Игорь, 420-4\n");
	system ("pause");
	return 0;
}
