#include <stdio.h>
#include <stdlib.h>
struct student{
    char student_name[10];
    int student_id;
    int student_birth_day;
    int student_birth_month;
    int student_birth_year;
    int student_last_score;
};
struct Node {
    struct student Info;
    struct Node* next;
};

// Creating linkedlist
// function to create and return a node
struct Node* createNode()
{
    // allocating space
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // inserting the required data
    printf("\nEnter student Information : \n");
    printf("Enter Student name: ");
    scanf ("%s", newNode->Info.student_name);
    printf("Enter Student ID: ");
    scanf("%d", &newNode->Info.student_id);
    printf("Enter Student birthday: ");
    scanf("%d", &newNode->Info.student_birth_day);
    printf("Enter birth month: ");
    scanf("%d", &newNode->Info.student_birth_month);
    printf("Enter birth Year: ");
    scanf("%d", &newNode->Info.student_birth_year);
    printf("Enter Last score: ");
    scanf("%d", &newNode->Info.student_last_score);
    newNode->next = NULL;
    return newNode;
}

void displayLL(struct Node* head);
void insertAtBegin(struct Node** head_ref);
void insertAtMiddle(struct Node* head);
void insertAtEnd(struct Node** head);
// main function
int main()
{
    printf("\n Welcome to the student information program !\n\n");
    printf("Student at the Head\n");
    struct Node * Head= createNode();
    printf("\nStudent at the Tail\n");
    struct Node * Tail= createNode();
    Head->next = Tail;
    Tail->next = NULL;
    //insertAtBegin(&Head);
    //insertAtMiddle(Head);
    //insertAtEnd(&Head);

    displayLL(Head);

    return 0;
}


//inserts a new node on the front of the list.
void insertAtBegin(struct Node** head_ref)
{
	/* 1. allocate node */
	struct Node* new_node = createNode();

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

// function to insert a node in the middle of a LL
void insertAtMiddle(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head->next;
    // Create the new node
    struct Node* newNode = createNode();

    // Get the pointer pointing to the middle node in the LL
    while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    struct Node* middleNodePtr = slow;

    newNode->next = middleNodePtr->next;
    middleNodePtr->next = newNode;
}



// function to push a node to the end of Linked List
void insertAtEnd(struct Node** head)
{
    // Check if head is NULL
    if (*head == NULL)
    {
        *head = createNode();
        return;
    } else {
        struct Node* tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        // Now, I have tmp pointing to the last node
        tmp->next = createNode();
    }
}



// function to display the linked list
void displayLL(struct Node* head)
{
    struct Node* tmp = head;
    printf("Linked List: ");
    int i=1;
    while (tmp != NULL) {

        printf("\n\n#####################################################################\n\n");
        printf("\nDisplaying information of student number : %d\n", i);
        printf("Name: %s", tmp->Info.student_name);
        printf("\n ID number: %d", tmp->Info.student_id);
        printf("\n Birth day: %d", tmp->Info.student_birth_day);
        printf("\n Birth month: %d",tmp->Info.student_birth_month);
        printf("\n Birth Year: %d", tmp->Info.student_birth_year);
        printf("\n Last score: %d", tmp->Info.student_last_score);

        tmp = tmp->next;
        i=i+1;
    }
    printf("\n");
};

