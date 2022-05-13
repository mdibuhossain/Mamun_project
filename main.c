#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZEOF_MEDICINE 101
#define MAX_SIZEOF_COMPANY 101
#define MAX_SIZEOF_MFG 11
#define MAX_SIZEOF_EXP 11
#define MAX_SIZEOF_INFO 5001

typedef struct Medicine
{
    int id;
    int price;
    int quantity;
    char medicneName[MAX_SIZEOF_MEDICINE];
    char Company[MAX_SIZEOF_COMPANY];
    char Mfg_Date[MAX_SIZEOF_MFG];
    char Exp_Date[MAX_SIZEOF_EXP];
    char info[MAX_SIZEOF_INFO];
} Medicine;

Medicine m[100];
FILE *medicineData = NULL;

void openFile(char[]);
void closeFile();
void dataDisplayInterface(Medicine);
void SellMedicine(int);
void EnterInfoAboutMedicine(int);
void StockOfMedicine(int);
void KnowInfoAboutMedicine(int);
void AddMedicineinStore(int, struct Medicine m[]);
void DeleteMedicineStore(int);
int main()
{
    system("Color B4");

    int i, j, number = 0, c;
    char choice[50];
    do
    {
        system("cls");
        printf("**************************** WElCOME TO OUR STORE ************************");
        printf("\n******************************************************************************");
        printf("\n\nWhat do you Want?Press any option:\n");

        printf("\n\t1.Sell Medicine\n\t2.Give a Information about this Medicine\n\t3.Stock information of all Medicine\n\t4.A specific Medicine Information\n\t5.Add New Medicine \n\t6.Delete any Medicine\n");

        gets(choice);
        while (choice[0] != 49 && choice[0] != 50 && choice[0] != 51 && choice[0] != 52 && choice[0] != 53 && choice[0] != 54)
        {
            printf("Please Enter a Valid(1-6) Value: ");
            gets(choice);
        }
        switch (choice[0])
        {

        case 49:
        {
            SellMedicine(number + 1);
            break;
        }
        case 50:
        {
            EnterInfoAboutMedicine(number + 1);
            break;
        }
        case 51:
        {
            StockOfMedicine(number + 1);
            break;
        }
        case 52:
        {
            KnowInfoAboutMedicine(number + 1);
            break;
        }
        case 53:
        {
            ++number;
            AddMedicineinStore(number, m);
            break;
        }
        case 54:
        {
            DeleteMedicineStore(number + 1);
            break;
        }
        }

        printf("To Get Back in Main option press '0' Else any other number\n");
        scanf("%d", &c);
    } while (c == 0);
}
void openFile(char mode[])
{
    medicineData = fopen("data.bin", mode);
}
void closeFile()
{
    fclose(medicineData);
}
void dataDisplayInterface(Medicine tmpData)
{
    printf("%-20s= %d\n", "Id", tmpData.id);
    printf("%-20s= %s\n", "Medicine name", tmpData.medicneName);
    printf("%-20s= %d\n", "Price", tmpData.price);
    printf("%-20s= %d\n", "Available Quantity", tmpData.quantity);
    printf("%-20s= %s\n", "Company", tmpData.Company);
    printf("%-20s= %s\n", "Mfg Date", tmpData.Mfg_Date);
    printf("%-20s= %s\n", "Exp Date", tmpData.Exp_Date);
    if (strcmp(tmpData.info, "") != 0)
    {
        printf("%-20s= %s\n", "Review or Info", tmpData.info);
    }
    else
    {
        printf("%-20s= Not Available\n", "Review or Info");
    }
}
void SellMedicine(int number)
{
    int id, check, i, quantity, flag = 0;
    char name[100];
    printf("Enter 1 if you know ID else any other number to enter Name of Medicine\n");
    fflush(stdin);
    scanf("%d", &check);
    if (check == 1)
    {
        printf("Enter Id to Sell Medicine\n");
        fflush(stdin);
        scanf("%d", &id);
        for (i = 0; i < number; i++)
        {
            if (m[i].id == id)
            {
                flag = 1;
                int c;
                printf("These are the details of Medicine\n");
                printf("Name%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n", m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
                if (strcmp(m[i].info, "") == 0)
                {
                    printf("Medicine Review/Info=Not Available\n");
                }
                else
                {
                    printf("Medicine Review/Info=%s\n", m[i].info);
                }
                printf("Do you want to Sell %s \nIf Yes Enter 1 else any other number\n", m[i].medicneName);
                fflush(stdin);
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("Enter Quantity to Sell\n");
                    scanf("%d", &quantity);
                    if (m[i].quantity > quantity)
                    {
                        printf("Total Price to be paid=%d\n", quantity * m[i].price);
                    }
                    else
                    {
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            printf("Entered Id Not Found\n");
        }
    }
    else
    {
        printf("Enter Name to search and Sell\n");
        fflush(stdin);
        gets(name);
        for (i = 0; i < number; i++)
        {
            if (strcmp(m[i].medicneName, name) == 0)
            {
                flag = 1;
                int c;
                printf("These are the details of Medicine\n");
                printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n", m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
                if (strcmp(m[i].info, "") == 0)
                {
                    printf("Medicine Review/Info=Not Available\n");
                }
                else
                {
                    printf("Medicine Review/Info=%s\n", m[i].info);
                }
                printf("Do you want to Sell %s \nIf Yes Enter 1 else any other number\n", m[i].medicneName);
                fflush(stdin);
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("Enter Quantity to Sell\n");
                    scanf("%d", &quantity);
                    if (m[i].quantity > quantity)
                    {
                        printf("Total Price to be paid=%d\n", quantity * m[i].price);
                    }
                    else
                    {
                        printf("Please Enter quantity below Available Quantity\n");
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            printf("Entered Name of MEdicine Not Found\n");
        }
    }
}

void EnterInfoAboutMedicine(int number)
{
    int i, flag = 0, c;
    char name[100], info[100];
    printf("Enter Name of the medicine you want to Review or include Info\n");
    fflush(stdin);
    gets(name);
    for (i = 0; i < number; i++)
    {
        if (strcmp(m[i].medicneName, name) == 0)
        {
            flag = 1;
            printf("These are the details of Medicine\n");
            printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n", m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
            if (strcmp(m[i].info, "") != 0)
            {
                printf("Review Already Available!\nIf you want to Add a Review Enter 1 else Any other number\n");
                fflush(stdin);
                scanf("%d", &c);
            }
            else
            {
                printf("Give a short review(less than 100 Characters)\n");
                fflush(stdin);
                gets(m[i].info);
            }
            if (c == 1)
            {
                printf("Give a review(less than 100 Characters)\n");
                fflush(stdin);
                gets(info);
                strcat(m[i].info, "; ");
                strcat(m[i].info, info);
            }
        }
    }
    if (flag == 0)
    {
        printf("Entered Name of Medicine Not Found\n");
    }
}
void KnowInfoAboutMedicine(int number)
{
    openFile("rb");
    Medicine tmpM;
    int i, flag = 0;
    char name[MAX_SIZEOF_MEDICINE];
    printf("Enter Name of the medicine you want to see Review and Info\n");
    fflush(stdin);
    gets(name);
    while (fread(&tmpM, sizeof(Medicine), 1, medicineData) == 1)
    {
        if (strcmp(tmpM.medicneName, name) == 0)
        {
            flag = 1;
            printf("These are the details of Medicine\n");
            dataDisplayInterface(tmpM);
        }
    }
    if (flag == 0)
    {
        printf("Entered Name Not Found\n");
    }
    closeFile();
}
void StockOfMedicine(int number)
{
    openFile("rb");
    Medicine tmpData;
    int item = 0;
    if (medicineData != NULL)
    {
        printf("All Available Items are\n");
        while (fread(&tmpData, sizeof(Medicine), 1, medicineData) == 1)
        {
            puts("--------------------------------------------");
            dataDisplayInterface(tmpData);
            item++;
        }
        if (!item)
            printf("No Items/Medicines Available\n");
    }
    else
    {
        printf("No Items/Medicines Available\n");
    }
    closeFile();
}
void AddMedicineinStore(int number, struct Medicine m[])
{
    openFile("ab");
    if (medicineData != NULL)
    {
        printf("Enter Medicine Id\n");
        scanf("%d", &(m[number].id));
        fflush(stdin);
        printf("Enter Medicine Name\n");
        fflush(stdin);
        gets(m[number].medicneName);
        printf("Enter Company Name\n");
        fflush(stdin);
        gets(m[number].Company);
        printf("Enter Manufactured Date\n");
        fflush(stdin);
        gets(m[number].Mfg_Date);
        printf("Enter Expiry Date\n");
        fflush(stdin);
        gets(m[number].Exp_Date);
        printf("Enter Quantity\n");
        fflush(stdin);
        scanf("%d", &(m[number].quantity));
        printf("Enter Selling Price\n");
        fflush(stdin);
        scanf("%d", &(m[number].price));
        strcpy(m[number].info, "");
        printf("Medicine with id %d Added Successfully\n", m[number].id);
        fwrite(&m[number], sizeof(Medicine), 1, medicineData);
    }
    closeFile();
}

void DeleteMedicineStore(int number)
{
    int index = 0;
    int i = 0;
    Medicine *allMedicines = (Medicine *)calloc(1, sizeof(Medicine));
    openFile("rb");
    while (fread(&allMedicines[index], sizeof(Medicine), 1, medicineData) == 1)
    {
        allMedicines = (Medicine *)realloc(allMedicines, (index + 2) * sizeof(Medicine));
        index++;
    }
    closeFile();

    int id, flag = 0, num;
    printf("Enter Id to be deleted\n");
    fflush(stdin);
    scanf("%d", &id);
    openFile("wb");
    for (i = 0; i < index; i++)
    {
        if (id == allMedicines[i].id)
            flag = 1;
        else
            fwrite(&allMedicines[i], sizeof(Medicine), 1, medicineData);
    }
    if (flag == 1)
    {
        printf("Medicine with %d is Deleted Successfully\n", id);
    }
    closeFile();
}