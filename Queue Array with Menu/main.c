#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
	char data[MAX];
	int front;
	int rear;
	int count;
} queue;

void inisialisasi(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void enqueue(char c, queue *q);
char dequeue(queue *q);
char tampil(queue *q, int offset);

int main(int argc, char *argv[]) {
	queue antrian;
	char x;
	char pilihan;

	inisialisasi(&antrian);
	do {
		puts("Menu pilihan queue dengan array");
		puts("1. Enqueue (memasukkan data)");
		puts("2. Dequeue (menghapus data)");
		puts("3. Menampilkan data");
		puts("4. Keluar");

		fflush(stdin);
		printf("Masukkan pilihan Anda : ");
		scanf(" %c", &pilihan);
		puts("");
		switch (pilihan) {
		case '1':
			fflush(stdin);
			printf("Elemen yang dimasukkan : ");
			scanf(" %c", &x);
			enqueue(x, &antrian);
			break;
		case '2':
			printf("Anda mengambil data : %c\n", dequeue(&antrian));
			break;
		case '3':
			puts("Data dalam Queue");
			for (int i = 0; i < antrian.count; i++) {
				printf("%c\n", tampil(&antrian, i));
			}
			break;
		case '4':
			exit(0);
			break;
		default:
			puts("Pilihan salah, mohon ulangi");
			break;
		}
		puts("");
	} while (pilihan != 4);
}

void inisialisasi(queue *q) {
	q->count = 0;
	q->front = 0;
	q->rear = 0;
}

int kosong(queue *q) {
	return q->count == 0;
}

int penuh(queue *q) {
	return q->count == MAX;
}

void enqueue(char c, queue *q) {
	if (penuh(q)) {
		puts("Data penuh! tidak dapat memasukkan data lagi ke dalam queue.");
	} else {
		q->data[q->rear] = c;
		q->rear = (q->rear + 1) % MAX;
		q->count++;
	}
}

char dequeue(queue *q)  {
	char temp;

	if (kosong(q)) {
		puts("Data kosong! tidak ada yang dapat di-dequeue");
		return '\0';
	} else {
		q->count--;
		temp = q->data[q->front];
		q->data[q->front] = '\0';
		q->front = (q->front + 1) % MAX;
		return temp;
	}
}

char tampil(queue *q, int offset) {
	if (kosong(q)) {
		puts("Data kosong! tidak ada yang dapat di-dequeue");
		return '\0';
	} else {
		if (q->front + offset >= MAX) {
			return q->data[(q->front + offset) % MAX];
		}
		return q->data[q->front + offset];
	}
}