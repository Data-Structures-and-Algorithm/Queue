#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node_t;

Node_t *front, *rear;


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
	front = rear = NULL;
}


int isEmpty(void)
{
	return (front == NULL);

}



int size(void)
{
	Node_t *p = front;

	int count = 0;

	while (p) {
		count++;
		p = p->next;
	}
	
	return count;

}


int peek(void)
{
	if (isEmpty()) {
		printf("Queue Empty...\n");
		return -1;
	}

	return front->data;
	

}


void enqueue(int item)
{

	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

	temp->data = item;

	temp->next = NULL;

	if (front == NULL) {
		front = temp;
	} else {
		rear->next = temp;
	}

	rear = temp;

}


int dequeue(void)
{
	int removed_item;

	Node_t *temp = front;

	if (isEmpty()) {
		printf("Empty Queue...");
		return -1;
	}

	removed_item = temp->data;

	front = front->next;

	free(temp);

	return removed_item;
}


void display(void)
{
	if (isEmpty()) {
		printf("Empty Queue...\n");
		return;
	}

	Node_t *p = front;

	while (p) {
		printf("%d --> ", p->data);
		p = p->next;
	}

	printf("\n");

}





















