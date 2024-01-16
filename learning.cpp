#include<bits/stdc++.h>


int capa = 5;

int indx = 0;

int current_capa=10;

typedef struct Data
{
    char name[20];
    int id;
    float mark;
}StudentData;

StudentData* insertDataAtLast(StudentData * PassedData)
{
    printf("Enter student name: ");
    scanf("%s",PassedData[indx].name);
    printf("Enter student id: ");
    scanf("%d",&PassedData[indx].id);
    printf("Enter obtained mark: ");
    scanf("%f",&PassedData[indx].mark);

    indx++;
    if(indx>current_capa){
        current_capa+=10;
        PassedData=(StudentData*) realloc(PassedData, current_capa*sizeof(StudentData));
    }
    return PassedData;
}

StudentData* insertDataAtFirst(StudentData * PassedData)
{
    for(int i=indx; i>=0; i--){
        PassedData[i]=PassedData[i-1];
    }
    printf("Enter student name: ");
    scanf("%s",PassedData[0].name);
    printf("Enter student id: ");
    scanf("%d",&PassedData[0].id);
    printf("Enter obtained mark: ");
    scanf("%f",&PassedData[0].mark);

    indx++;
    if(indx>current_capa){
        current_capa+=10;
        PassedData=(StudentData*) realloc(PassedData, current_capa*sizeof(StudentData));
    }
    return PassedData;
}

StudentData* insertDataAtAny(StudentData * PassedData)
{
    int ind;
    printf("Which index do you want to insert the data? (Current size is %d)\n",indx);
    scanf("%d",&ind);
    ind=ind-1;
    for(int i=indx; i>ind; i--){
        PassedData[i]=PassedData[i-1];
    }
    printf("Enter student name: ");
    scanf("%s",PassedData[ind].name);
    printf("Enter student id: ");
    scanf("%d",&PassedData[ind].id);
    printf("Enter obtained mark: ");
    scanf("%f",&PassedData[ind].mark);

    indx++;
    if(indx>current_capa){
        current_capa+=10;
        PassedData=(StudentData*) realloc(PassedData, current_capa*sizeof(StudentData));
    }
    return PassedData;
}

StudentData* deleteDataAtLast(StudentData * PassedData)
{
    indx--;
    return PassedData;
}

StudentData* deleteDataAtAny(StudentData * PassedData)
{
    int ind;
    printf("What is the index of the data you want to delete? (Current size is %d)\n",indx);
    scanf("%d",&ind);
    ind=ind-1;
    for(int i=ind;i<indx-1;i++){
        PassedData[i]=PassedData[i+1];
    }
    indx=indx-1;
    return PassedData;
}

StudentData* deleteDataAtFirst(StudentData * PassedData)
{
    for(int i=0;i<indx-1;i++){
        PassedData[i]=PassedData[i+1];
    }
    indx--;
    return PassedData;
}

void searchByName(StudentData* PassedData, char nm[]){
    int k=-1;
    for(int i=0;i<indx;i++){
        if(strcmp((PassedData[i].name),nm)==0){
            k=i;
        }
    }
    if(k==-1){
        printf("Student not found.\n");
    }
    else{
        printf("Name: %s\n",PassedData[k].name);
        printf("ID: %d\n",PassedData[k].id);
        printf("Marks: %f\n",PassedData[k].mark);
    }
}

void printData(StudentData * PassedData)
{
    int i;
    printf("-------------------------------------------\n");
    printf("\t\tStudent Data\n");
    printf("-------------------------------------------\n");

    for (i = 0; i < indx ; i++ )
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
    StudentData * cse21 = (StudentData*) malloc(current_capa*sizeof(StudentData));


    printf("1. Enter Student Data At First Position\n");
    printf("2. Enter Student Data At A Given Position\n");
    printf("3. Enter Student Data At Last Position\n");
    printf("4. Show Student Data\n");
    printf("5. Delete Student Data At First Position\n");
    printf("6. Delete Student Data At A Given Position\n");
    printf("7. Delete Student Data At Last Position\n");
    printf("8. Search by student name\n");
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
        else if(userChoice==8){
            char nm[50];
            printf("Enter the name of the student you want to find. ");
            scanf("%s",nm);
            searchByName(cse21,nm);
        }
        printf("Enter your choice: ");
    }

    free(cse21);
    return 0;
}
