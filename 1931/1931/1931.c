#include<stdio.h>
#include<stdlib.h>

struct arr {
	int start;
	int fin;
	struct arr *next;
};

int main() {
	int N = 0;
	int check = 0;
	int count = 1;

	scanf("%d", &N);
	struct arr *head = (struct arr *)malloc(sizeof(struct arr));
	struct arr *temp;

	for (int i = 0; i < N; i++) {
		struct arr *NODE = (struct arr *)malloc(sizeof(struct arr));
		check = 0;
		temp = head;
		scanf("%d %d", &NODE->start, &NODE->fin);
		NODE->next = NULL;
		for (int j = 0; j < i; j++) {
			if (temp->next->fin > NODE->fin) {
				NODE->next = temp->next;
				break;
			}
			temp = temp->next;
		}
		temp->next = NODE;		
	}
	
	int finT = head->next->fin;
	temp = head->next->next;
	for (int i = 1; i < N; i++) {
		if (finT < temp->start) {
			count++;
			finT = temp->fin;
		}
		temp = temp->next;
	}

	printf("%d", count);

	return 0;
}


