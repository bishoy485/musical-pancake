#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

/*Members of the team
Name:  استقلال شاك ریاك كاى Section: 01 B:N: 27 
Name: بیشوي اسامھ سلیمان ناروز Section: 01 B:N: 45
Name:  منھ یاسر حسن محمد سعودى Section: 04 B:N: 26 
*/

int size_N = 1000; // small size
//int size_N = 10000; // medium size
//int size_N = 100000; // Large size
struct student{
    char student_name[20];
    int student_id;
    int student_birth_day;
    int student_birth_month;
    int student_birth_year;
    int student_last_score;
};

int CurrentSize=0; //counter for array elements.
int N ;
struct student *Arr ;
//////Make array consisting of N students/////
void MakeArr()
{
    Arr  = (struct student*)malloc(N*sizeof(struct student)) ;
    for(int i=1;i< N ;i++)
     Arr[i].student_birth_day=-1; //intialize birthday with -1 to indicate a free element in the Array.
}
/////InsertFront for Array/////
clock_t InsertFrontArr(struct student s) //Returns time taken for insertion.
{
    clock_t t =clock();
    int i = 0;
    struct student temp=s; // insert student at first position.
    temp=Arr[i];
    Arr[i]=s;
    while(Arr[i+1].student_birth_day!=-1) //shift the rest of elements by 1 position
    {
        s=Arr[i+1];
        Arr[i+1]=temp;
        temp=s;
        i++;
    }
    Arr[i+1]=temp;
    CurrentSize++;
    printf("time taken = %ld\n",clock()-t);
    return clock()-t;
}
/////InsertEnd for Array /////
clock_t InsertEndArr(struct student s)//Returns time taken.
{
    clock_t t = clock();
    Arr[CurrentSize]=s;
    CurrentSize++;
    printf("time taken = %ld\n",clock()-t);
    return clock()-t;
}
/////Insert Middle for Array /////
clock_t InsertMiddleArr(struct student  s,int position)//Returns time taken
{
    clock_t t = clock();
    int i = position; //insert the student in the desired position.
    struct student temp=s;
    temp=Arr[i];
    Arr[i]=s;
    while(Arr[i+1].student_birth_day!=-1) //shift the next students by 1 position.
    {
        s=Arr[i+1];
        Arr[i+1]=temp;
        temp=s;
        i++;
    }
    Arr[i+1]=temp;
    CurrentSize++;
    printf("time taken = %ld\n",clock()-t);
    return clock()-t;
}

void print()
{

    for(int i=0; i < CurrentSize ; i++)
    {
        printf("Student %dth data :\n",i);
        printf("Name %s\n",Arr[i].student_name);
        printf("birth date : %d/%d/%d\n",Arr[i].student_birth_day,Arr[i].student_birth_month,Arr[i].student_birth_year);
        printf("ID : %d\n",Arr[i].student_id);
    }
}

// Creating linkedlist

struct Node {
    struct student Info;
    struct Node* next;
};


// function to create and return a node
struct Node* createNode()
{
    // allocating space
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // inserting the required data
    strcpy(newNode->Info.student_name, "Estecklal");
    newNode->Info.student_id=1;
    newNode->Info.student_birth_day= 24;
    newNode->Info.student_birth_month= 06;
    newNode->Info.student_birth_year=1996;
    newNode->Info.student_last_score=99;
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
    printf("\n Size taken by structure in the memory %zu\n", sizeof(struct student));
    printf("\n Size taken by one Node in the linked list = %zu\n\n",sizeof(struct Node));

    /*struct student s1,s2,s3,s4,s5,s6;
    s1.student_birth_day=1;
    s1.student_birth_month=1;
    s1.student_birth_year=1;
    s1.student_id=1;
    s1.student_last_score=1;
    strcpy(s1.student_name,"s1");

    s2.student_birth_day=2;
    s2.student_birth_month=2;
    s2.student_birth_year=2;
    s2.student_id=2;
    s2.student_last_score=2;
    strcpy(s2.student_name,"s2");

    s3.student_birth_day=3;
    s3.student_birth_month=3;
    s3.student_birth_year=3;
    s3.student_id=3;
    s3.student_last_score=3;
    strcpy(s3.student_name,"s3");

    s4.student_birth_day=4;
    s4.student_birth_month=4;
    s4.student_birth_year=4;
    s4.student_id=4;
    s4.student_last_score=4;
    strcpy(s4.student_name,"s4");

    s5.student_birth_day=5;
    s5.student_birth_month=5;
    s5.student_birth_year=5;
    s5.student_id=5;
    s5.student_last_score=5;
    strcpy(s5.student_name,"s5");

    s6.student_birth_day=6;
    s6.student_birth_month=6;
    s6.student_birth_year=6;
    s6.student_id=6;
    s6.student_last_score=6;
    strcpy(s6.student_name,"s6");

    N= 10;
    MakeArr();

    InsertEndArr(s1);
    //print(Arr);
    InsertEndArr(s2);
    //print(Arr);
    InsertFrontArr(s3);
    InsertEndArr(s4);
    //print(Arr);
    InsertMiddleArr(s5,2);
    //print(Arr);
    InsertFrontArr(s6);
    print(Arr);*/

    // Time parameters
    int start=0;
    int finish = 0;

    //printf("Student at the Head\n");
    struct Node * Head= createNode();
    //printf("\nStudent at the Tail\n");
    struct Node * Tail= createNode();
    Head->next = Tail;
    Tail->next = NULL;

    start = clock();
    for ( int i =1; i<=size_N; i++)
        {
            insertAtBegin(&Head);
        }
    finish = clock();
    printf("\nTime Taken inserting elements at the START = %f \n", (double)(finish-start)/CLOCKS_PER_SEC);

        start = clock();
    for ( int i =1; i<=size_N; i++)
        {
            insertAtMiddle(Head);
        }
    finish = clock();
    printf("\nTime Taken inserting elements in the middle = %f \n", (double)(finish-start)/CLOCKS_PER_SEC);

        start = clock();
    for ( int i =1; i<=size_N; i++)
        {
            insertAtEnd(&Head);
        }
    finish = clock();
    printf("\nTime Taken inserting elements at END = %f \n", (double)(finish-start)/CLOCKS_PER_SEC);



   // displayLL(Head);


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
       // printf("Name: %s", tmp->Info.student_name);
        printf(" Name: ");
        for (int j = 0; j < 9; j++)
            {
                printf("%c", tmp->Info.student_name[j]);
            }
        printf("\n ID number: %d", tmp->Info.student_id);
        printf("\n Birth date/Month/Year : %d/%d/%d",tmp->Info.student_birth_day,tmp->Info.student_birth_month,tmp->Info.student_birth_year);
        printf("\n Last score: %d", tmp->Info.student_last_score);
        tmp = tmp->next;
        i=i+1;
    }
    printf("\n");
};
