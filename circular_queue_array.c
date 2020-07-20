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
	front = rear = 0;
}


int isEmpty(void)
{
	return (front == rear);

}


int isFull(void)
{
	return (front == ((rear + 1) % MAX_SIZE));
}


int size(void)
{

	return ((MAX_SIZE + (rear - front)) % MAX_SIZE);	

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

	Queue[rear] = item;

	rear = (rear + 1) % MAX_SIZE;
}


int dequeue(void)
{
	int removed_item;

	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}

	removed_item = Queue[front];

	front = (front + 1) % MAX_SIZE;

	return removed_item;
}


void display(void)
{
	if (isEmpty()) {
		printf("Empty Queue...\n");
		return;
	}

	for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
		printf("%d --> ", Queue[i]);
	}

	printf("\n");
}





















