#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void addRecord();
void viewRecord();
void deleteRecord();
void delay(int);

struct diary
{
    char date[15];
    char time[10];
    char place[25];
    char msg[500];
} d1;

void main()
{
    char choice;
top:
    system("cls");
    printf("\n\n\n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 22);
    }
    printf("\n\t\t P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M\n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 22);
    }
    printf("\n\t\t\t\t PRESS[1]:Add Record");
    printf("\n\t\t\t\t PRESS[2]:View Record");
    printf("\n\t\t\t\t PRESS[3]:Delete Record");
    printf("\n\t\t\t\t PRESS[4]:Exit\n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 22);
    }
    printf("\n\t\t            P R E S S  Y O U R  C H O I C E  K E Y\n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 22);
    }
    printf("\n");
    fflush(stdin);
    choice = getch();
    switch (choice)
    {
    case '1':
        addRecord();
        goto top;
        break;
    case '2':
        viewRecord();
        goto top;
        break;
    case '3':
        deleteRecord();
        goto top;
        break;
    case '4':
        printf("\n\nCloasing the system...\n");
        for (int j = 0; j < 50; j++)
        {
            for (int i = 0; i < 11111111; i++)
            {
            }
            printf("%c", 22);
        }
        for (int j = 0; j < 50; j++)
        {
            printf("%c", 22);
        }
        system("cls");
        break;
    default:
        system("cls");
        printf("\n\n\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 22);
        }
        printf("\n\t\t P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 22);
        }
        printf("\n\n\t\t\t\t     [X]:Invalid Input :(\n\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 22);
        }
        printf("\n\t\t            P R E S S  Y O U R  C H O I C E  K E Y\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 22);
        }
        printf("\n");
        delay(7);
        goto top;
        break;
    }
}

void delay(int a)
{
    for (int i = 0; i < 100000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int m = 0; m < a; m++)
            {
                /* code */
            }
        }
    }
}

void addRecord()
{
    FILE *fp;
    fp = fopen("Diary.dat", "ab");
    if (fp == NULL)
    {
        printf("\nFile is not found");
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t%c P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M  :)\n\t", 2);
    printf("\n\t # Enter_Date(dd/mm/yyyy)     : ");
    fflush(stdin);
    gets(d1.date);
    printf("\n\t # Enter_Time(hh:mm am/pm)    : ");
    fflush(stdin);
    gets(d1.time);
    printf("\n\t # Enter_Location(place name) : ");
    fflush(stdin);
    gets(d1.place);
    printf("\n\t # Enter_Message : ");
    fflush(stdin);
    gets(d1.msg);
    printf("\n\nSaving...\n");
    fwrite(&d1, sizeof(d1), 1, fp);
    for (int j = 0; j < 50; j++)
    {
        for (int i = 0; i < 11111111; i++)
        {
        }
        printf("%c", 22);
    }
    for (int j = 0; j < 50; j++)
    {
        printf("%c", 22);
    }
    fclose(fp);
}

void viewRecord()
{
    FILE *fp;
    int ch, j = 1;
    fp = fopen("Diary.dat", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tFile is not found");
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t%c P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M  :)\n", 2);
    for (int i = 1; fread(&d1, sizeof(d1), 1, fp) != 0; i++)
    {
        printf("\n\t   # Record %d) : %s \t %s \t %s", i, d1.date, d1.time, d1.place);
    }
    fclose(fp);
    printf("\n\n\t  Which record you want to see from above?\n\t   Enter record number : ");
    scanf("%d", &ch);
    fp = fopen("Diary.dat", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tFile is not found");
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t%c P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M  :)\n", 2);
    for (j; fread(&d1, sizeof(d1), 1, fp) != 0; j++)
    {
        if (j == ch)
        {
            printf("\n\t\t                              Date : %s", d1.date);
            printf("\n\t\t                              Time : %s", d1.time);
            printf("\n\t\t                          Location : %s", d1.place);
            printf("\n# Record,\n   %s", d1.msg);
            break;
        }
    }
    fclose(fp);
    if (j != ch)
    {
        printf("\n\t     The record is not match, please cheack and try again.");
    }
    printf("\n\n\t\t\t\tPress any key..!");
    getch();
}

void deleteRecord()
{
    int flage = 0, ch;
    FILE *fp, *tptr;
    fp = fopen("Diary.dat", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tFile is not found");
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t%c P E R S O N A L  D I A R Y  M A N A G E M E N T  S Y S T E M  :)\n", 2);
    for (int i = 1; fread(&d1, sizeof(d1), 1, fp) != 0; i++)
    {
        printf("\n\t\t# Record %d) : %s     %s     %s", i, d1.date, d1.time, d1.place);
    }
    printf("\n\n\t   Which record you want to delete from above?\n\t   Enter record number : ");
    scanf("%d", &ch);
    fclose(fp);
    fp = fopen("Diary.dat", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tFile is not found");
        exit(1);
    }
    tptr = fopen("temp.dat", "ab");
    for (int i = 1; fread(&d1, sizeof(d1), 1, fp) != 0; i++)
    {
        if (ch != i)
        {
            fwrite(&d1, sizeof(d1), 1, tptr);
        }
        else
        {
            flage = 1;
        }
    }
    fclose(fp);
    fclose(tptr);
    remove("Diary.dat");
    rename("temp.dat", "Diary.dat");
    if (flage == 0)
    {
        printf("\n\n\t\tRecord is not found..!");
    }
    else
    {
        printf("\n\t    *Record deleted successfully, press any key...");
    }
    getch();
}