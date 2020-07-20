#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node {
   int priority;
   int data;
   struct Node *next;
} Node_t;   


Node_t *front;

void Queue_Init(void);
void display(void);
void enqueue(int data, int priority);
int isEmpty(void);
int dequeue();


int main(void) 
{
	int n;

	Queue_Init();


    while (1) {
        printf("1. Display\n2. Enqueue\n3. Dequeue\n"
               "4. Quit\nEnter your choice: ");
        scanf("%d", &n);


        switch (n) {
            case 1:
                display();
                break;
            case 2: {
                int data;
				int priority;
                printf("Enter a no: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            }
            case 3:
                printf("Popped %d\n", dequeue());
                break;
            case 4:
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



void display(void)
{
	if (isEmpty()) {
		printf("List is empty\n");
		return;
	}

	Node_t *p = front;

	while (p) {

		printf("(%d, %d) --> ", p->priority, p->data);
		
		p = p->next;
	}

	printf("NULL\n");
}



void Queue_Init(void)
{
	front = NULL;
}



int isEmpty(void)
{
	return front == NULL;
}





int dequeue()
{
	if (isEmpty()) {
		printf("Empty Queue...\n");
		return -1;
	}

	int removed_item = front->data;

	free(front);

	front = front->next;

	return removed_item;

}

void enqueue(int data, int priority)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

	temp->data = data;

	temp->priority = priority;

	Node_t *p;

	if (isEmpty() || (priority < front->priority)) {
		temp->next = front;
		front = temp;
		return;
	}

	p = front;

	while (p->next != NULL && priority >= p->next->priority) {
		p = p->next;
	}

	temp->next = p->next;
	p->next = temp;
}


