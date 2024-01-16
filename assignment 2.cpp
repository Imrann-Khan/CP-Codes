#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int capacity = 5;  /// This should be the initial capacity of the Dynamic array
                  /// Try to re-allocate the array when the capacity is full and increase the capacity correspondingly
int index = 0;

typedef struct Data
{
    char name[20];
    int id;
    float mark;
}StudentData;

StudentData* insertDataAtLast(StudentData * PassedData)
{
    printf("Enter student name: ");
    scanf("%s",PassedData[index].name);
    printf("Enter student id: ");
    scanf("%d",&PassedData[index].id);
    printf("Enter obtained mark: ");
    scanf("%f",&PassedData[index].mark);

    index++;
    PassedData = (StudentData*) realloc(PassedData, (index+1)*sizeof(StudentData));
    return PassedData;
}

StudentData* insertDataAtFirst(StudentData * PassedData)
{
    ///TODO
    index++;
    PassedData = (StudentData*) realloc(PassedData, (index+1)*sizeof(StudentData));
    for(int i=index-1;i>0;i--)
    {
        PassedData[i].name=PassedData[i-1].name;
        PassedData[i].id=PassedData[i-1].id;
        PassedData[i].mark=PassedData[i-1].mark;
    }
    *PassedData[0]=*PassedData;
    return PassedData;
}

StudentData* insertDataAtAny(StudentData * PassedData)
{
    ///TODO
    index++;
    PassedData = (StudentData*) realloc(PassedData, (index+1)*sizeof(StudentData));
    int pos;
    scanf("Enter position= %d",&pos);
    for(int i=index-1;i>pos;i--)
    {
        PassedData[i].name=PassedData[i-1].name;
        PassedData[i].id=PassedData[i-1].id;
        PassedData[i].mark=PassedData[i-1].mark;
    }
    *PassedData[pos-1]=*PassedData;
    index++;
    PassedData = (StudentData*) realloc(PassedData, (index+1)*sizeof(StudentData));
    return PassedData;
}

StudentData* deleteDataAtLast(StudentData * PassedData)
{
    ///TODO
    index--;
    PassedData = (StudentData*) realloc(PassedData, (index)*sizeof(StudentData));
    return PassedData;
}

StudentData* deleteDataAtAny(StudentData * PassedData)
{
    ///TODO
    int pos;
    scanf("Enter position= %d",&pos);
    for(int i=pos-1;i<index;i++)
    {
        PassedData[i].name=PassedData[i+1].name;
        PassedData[i].id=PassedData[i+1].id;
        PassedData[i].mark=PassedData[i+1].mark;
    }
    return PassedData;
}

StudentData* deleteDataAtFirst(StudentData * PassedData)
{
    ///TODO
    for(int i=0;i<index;i++)
    {
        PassedData[i].name=PassedData[i+1].name;
        PassedData[i].id=PassedData[i+1].id;
        PassedData[i].mark=PassedData[i+1].mark;
    }
    return PassedData;
}

void printData(StudentData * PassedData)
{
    int i;
    printf("-------------------------------------------\n");
    printf("\t\tStudent Data\n");
    printf("-------------------------------------------\n");

    for (i = 0; i < index ; i++ )
    {
        printf("Name: %s",PassedData[i].name);
        printf("\n");
        printf("ID: %d",PassedData[i].id);
        printf("\n");
        printf("Mark: %f",PassedData[i].mark);
        printf("\n\n");
    }

    printf("-------------------------------------------\n");
}


int main()
{
    StudentData * cse21 = (StudentData*) malloc(sizeof(StudentData));


    printf("1. Enter Student Data At First Position\n");
    printf("2. Enter Student Data At A Given Position\n");
    printf("3. Enter Student Data At Last Position\n");
    printf("4. Show Student Data\n");
    printf("5. Delete Student Data At First Position\n");
    printf("6. Delete Student Data At A Given Position\n");
    printf("7. Delete Student Data At Last Position\n");
    printf("0. END\n");


    int userChoice;

    printf("Enter your choice: ");
    while(scanf("%d",&userChoice), userChoice!=0)
    {
        if(userChoice == 1)
            cse21 = insertDataAtFirst(cse21);
        else if(userChoice == 2)
            cse21 = insertDataAtAny(cse21);
        else if(userChoice == 3)
            cse21 = insertDataAtLast(cse21);
        else if(userChoice == 4)
            printData(cse21);
        else if(userChoice == 5)
            cse21 = deleteDataAtFirst(cse21);
        else if(userChoice == 6)
            cse21 = deleteDataAtAny(cse21);
        else if(userChoice == 7)
            cse21 = deleteDataAtLast(cse21);

        printf("Enter your choice: ");
    }

    free(cse21);
    return 0;
}