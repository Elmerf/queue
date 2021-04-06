#include <stdio.h>
#include <stdlib.h>

typedef struct queue node;
struct queue {
	char data;
	node *next;
};

node *front = NULL, *rear = NULL, *p;

void alokasi();
void enqueue();
char dequeue();
void bebasNode(node *node);
char tampil();

int main(int argc, char *argv[]) {
	char pilihan;

	do {
		puts("Menu pilihan queue dengan Single Linked List");
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
			alokasi();
			enqueue();
			break;
		case '2':
			if (front == NULL) {
				puts("Data kosong! Tidak dapat dequeue lagi");
				break;
			}
			printf("Data yang terhapus : %c\n", dequeue());
			break;
		case '3':
			puts("Data dalam Queue");
			tampil();
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

void alokasi() {
	char c;

	printf("Data yang mau disimpan : ");
	scanf(" %c", &c);

	p = (node *)malloc(sizeof(node));
	if (p == NULL) {
		puts("Alokasi Gagal!");
		exit(0);
	} else {
		p->data = c;
		p->next = NULL;
	}
}

void enqueue() {
	if (front == NULL) {
		front = p;
	} else {
		rear = front;
		while (rear->next != NULL) {
			rear = rear->next;
		}
		rear->next = p;
		rear = rear->next;
	}
}

char dequeue() {
	char temp;

	p = front;
	if (front->next == NULL) {
		front = NULL;
		return p->data;
	} else {
		temp = p->data;
		front = p->next;
		bebasNode(p);
		return temp;
	}
}

void bebasNode(node *node) {
	free(node);
	node = NULL;
}

char tampil() {
	p = front;
	while (p != NULL) {
		printf("%c\n", p->data);
		p = p->next;
	}
}