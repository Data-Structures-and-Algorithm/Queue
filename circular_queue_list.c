#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node_t;

Node_t *rear;


void Queue_Init(void);
int isEmpty(void);
int size(void);
int peek(void);
void enqueue(int item);
int dequeue(void);
void display(void);





int main() {

	int n;
	Queue_Init();


	while (1) {
        printf("1. Display\n2. Enqueue\n3. Dequeue\n4. Peek\n"
               "5. Size\n6. Quit\nEnter your choice: ");
        scanf("%d", &n);


        switch (n) {
            case 1:
                display();
                break;
            case 2: {
                int data;
                printf("Enter a no: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            }
            case 3:
                printf("Popped %d\n", dequeue());
                break;
            case 4:
                printf("Peek =  %d\n", peek());
                break;
            case 5:
                printf("Size =  %d\n", size());
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice...\n");
        }
        while (getchar() != '\n');

        printf("\n");

    }


	printf("\n");
	
	return 0;
}


void Queue_Init(void)
{
	rear = NULL;
}


int isEmpty(void)
{
	return (rear == NULL);

}



int size(void)
{
	if (isEmpty()) {
		return 0;
	}

	Node_t *p = rear->next;

	int count = 0;

	do {
		count++;
		p = p->next;
	} while (p != rear->next);
	
	return count;

}


int peek(void)
{
	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}

	return rear->next->data;
	

}


void enqueue(int item)
{

	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

	temp->data = item;

	//temp->next = NULL;

	if (isEmpty()) {
		temp->next = temp;
	} else {
		temp->next = rear->next;
		rear->next = temp;
	}

	rear = temp;

}


int dequeue(void)
{
	int removed_item;

	Node_t *temp;

	if (isEmpty()) {
		printf("Empty Queue...");
		return -1;
	}

	temp = rear->next;

	removed_item = temp->data;

	if (rear == rear->next) {
		rear = NULL;
	} else {
		rear->next = temp->next;
	}

	free(temp);

	return removed_item;
}


void display(void)
{
	if (isEmpty()) {
		printf("Empty Queue...\n");
		return;
	}

	Node_t *p = rear->next;

	do {
		printf("%d --> ", p->data);
		p = p->next;
	} while (p != rear->next);

	printf("\n");

}





















