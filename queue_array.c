#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 10	

int Queue[MAX_SIZE];

int rear, front;

void Queue_Init(void);
int isEmpty(void);
int isFull(void);
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
	front = rear = -1;
}


int isEmpty(void)
{
	return ((front == -1) || (front == rear + 1));

}


int isFull(void)
{
	return (rear == MAX_SIZE - 1);
}


int size(void)
{

	if (isEmpty()) {
		return 0;
	}

	return (rear - front + 1);	

}


int peek(void)
{
	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}

	return Queue[front];
	

}


void enqueue(int item)
{
	if (isFull()) {
		printf("Queue Full...\n");
		return;
	}

	if (front == -1) {
		front = 0;
	}

	Queue[++rear] = item;

}


int dequeue(void)
{
	int removed_item;

	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}

	removed_item = Queue[front++];

	if (isEmpty()) {
		front = rear = -1;
	}

	return removed_item;
}


void display(void)
{
	if (isEmpty()) {
		printf("Empty Queue...\n");
		return;
	}

	for (int i = front; i <= rear; i++) {
		printf("%d --> ", Queue[i]);
	}

	printf("\n");

}





















