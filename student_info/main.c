#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
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
    int i=0;
    for(int i = 0; i < CurrentSize ; i++)
    {
        printf("Student %dth data :\n",i);
        printf("Name %s\n",Arr[i].student_name);
        printf("birth date : %d/%d/%d\n",Arr[i].student_birth_day,Arr[i].student_birth_month,Arr[i].student_birth_year);
        printf("ID : %d\n",Arr[i].student_id);
    }
}



int main()
{
    printf("Hello world!\n");   
    struct student s1,s2,s3,s4,s5,s6;
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
    print(Arr);
    return 0;
}
