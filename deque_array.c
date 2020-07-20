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
void enqueue_front(int item);
void enqueue_rear(int item);
int dequeue_front(void);
int dequeue_rear(void);
void display(void);


void clrscr(void);


int main() {

	int n;
	Queue_Init();


	while (1) {

        printf("1. Display\n2. Enqueue Front\n3. Enqueue Rear"
			   "\n4. Dequeue Front\n5. Dequeue Rear\n6. Peek\n"
               "7. Size\n8. Quit\nEnter your choice: ");
        scanf("%d", &n);


        switch (n) {
            case 1:
                display();
                break;
            case 2: {
                int data;
                printf("Enter a no: ");
                scanf("%d", &data);
                enqueue_front(data);
                break;
            }
            case 3: {
                int data;
                printf("Enter a no: ");
                scanf("%d", &data);
                enqueue_rear(data);
                break;
            }
            case 4:
                printf("Popped %d\n", dequeue_front());
                break;
            case 5:
                printf("Popped %d\n", dequeue_rear());
                break;
            case 6:
                printf("Peek =  %d\n", peek());
                break;
            case 7:
                printf("Size =  %d\n", size());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice...\n");
        }

		

        printf("\nPress any key to continue...");
        
		getchar();

		while (getchar() != '\n');

		clrscr();
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


void enqueue_rear(int item)
{
	if (isFull()) {
		printf("Queue Full...\n");
		return;
	}

	Queue[rear] = item;

	rear = (rear + 1) % MAX_SIZE;
}




void enqueue_front(int item)
{
	if (isFull()) {
		printf("Queue Full...\n");
		return;
	}

	front = (front + MAX_SIZE - 1) % MAX_SIZE;

	Queue[front] = item;
}



int dequeue_front(void)
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



int dequeue_rear(void)
{
	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}


	rear = (rear + MAX_SIZE - 1) % MAX_SIZE;

	return Queue[rear];
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



void clrscr(void)
{
    system("clear");
}


















