#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
/*Info
svat.dat for sales vat file
 pvat.dat for purchase vat file
*/
// functions
void login()
{
    char username[20], passw[20];
    char lu[20] = "sara", lpw[20] = "cct";
    int la, i = 0, c = 0;
log:
    system("cls");
    printf("\n"); 
    printf("         **           **            **            **************    \n");
    printf("          **         **           **  **                **         \n");
    printf("            **      **           ********               **         \n");
    printf("             **    **           **      **              **         \n");
    printf("               ** **           **        **             **         \n");
    printf("                 *            *            *            **         \n");
    printf("\n");
    printf("       *******************************************************\n");
    printf("\n");
    printf("ENTER A VALID USERNAME AND PASSWORD TO GET ACCESS TO VAT MANAGEMENT SYSTEM \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n Enter Username:- \t");
    scanf("%s", &username);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n ENTER PASSWORD:- \t");
    while (i < 10)
    {
        passw[i] = getch();
        c = passw[i];
        if (c == 13)
            break;
        else
            printf("*");
        i++;
    }
    passw[i] = '\0';
    if (strcmp(lu, username) == 0 && strcmp(passw, lpw) == 0)
    {
    }
    else
    {

        printf("\n	You Have Entered Wrong Password ");

        printf("\n");

        printf(" Please contact to the Software Developer \n ");
        printf("COFFIN SOFTWARE COMPANY PRIVATE LIMITED \n");
        getch();
        exit(1);
    }
}
void sales(void);
void purchase(void);
void information(void);
void func_view_sales(void);
void func_modify_sales(void);
void func_delete_sales(void);
void func_view_purchase(void);
void func_modify_purchase(void);
void func_delete_purchase(void);
struct data
{
    int sid;
    int pid;
    long int amt;
    float vat;
    char d[30];
};
struct data a;
FILE *fp, *fptr;
int size = sizeof(a);
int choice;
int main()
{
    int co = 0;
    // main menu
    if (co == 0)
        login();
    co = co++;
again:
    system("cls");
    printf(" \n WELCOME TO THE VAT MANAGEMENT SYSYTEM \n\n");
    printf("********************************************************");
    printf("\n \n \n MAIN MENU\n");
    printf("\n 1. Sales Records");
    printf("\n 2. Purchase Records");
    printf(" \n 3. Information");
    printf(" \n 4. Exit");
    printf(" \n Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sales();
        break;
    case 2:
        purchase();
        break;
    case 3:
        information();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("wrong choice");
        getch();
    }
    goto again;
};
void sales(void)
{
    system("cls");
    printf("\n\t WELCOME TO THE SALES RECORDS\n");
    printf("\n*********************************");
    printf("\n\n\t SALES MENU");
    printf("\n 1. ADD Record");
    printf("\n 2. View Record");
    printf("\n 3. Modify Record");
    printf("\n 4. Delete Record");
    printf("\n 5. Return to Main Menu");
    printf("\n Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fp = fopen("svat.dat", "a+");
        printf("\n\n\n\t ENTER THE FOLLOWING DATA\n");
        printf("\nINVOICE NO.: ");
        scanf("%d", &a.sid);
        printf("\n DATE: ");
        scanf("%s", a.d);
        printf("\n SALES AMOUNT: ");
        scanf("%ld", &a.amt);
        a.vat = a.amt * 0.13;
        fwrite(&a, sizeof(a), 1, fp);
        printf("Record Added Successfully");
        fclose(fp);
        getch();
        break;
    /////////////////////////////////////////////////////////
    case 2:
        func_view_sales();
        break;
    /////////////////////////////////////////////////////////
    case 3:
        func_modify_sales();
        break;
    /////////////////////////////////////////////////////////
    case 4:
        func_delete_sales();
        break;
    /////////////////////////////////////////////////////////
    case 5:
        main();
        break;
    }
};
void func_view_sales(void)
{
    int f = 0;
    float ts = 0;
    fp = fopen("svat.dat", "r");
    printf("\n\n\n\t The Records is Displayed Below");
    printf("\n***********************************************");
    printf("\n\nINVOICE NO. \tDATE \t\tSALES AMOUNT\tSALES VAT\n");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        f = 1;
        printf("%d\t\t%s\t%ld\t\t%f", a.sid, a.d, a.amt, a.vat);
        printf("\n");
        ts = a.vat + ts;
    }
    printf("\n\n\t The Total Sales VAT=%f", ts);
    if (f == 0)
    {
        printf("\nrecord not found");
    }
    getch();
}
void func_modify_sales()
{
    fp = fopen("svat.dat", "r+");
    int mid, flag = 0;
    printf("\n\n Enter INVOICE NO. to Modify the Records: ");
    scanf("%d", &mid);
    while (fread(&a, sizeof(a), 1, fp) == 1)

        if (mid == a.sid)
        {
            flag = 1;
            printf("\nRecord Matched");
            printf("\nInvoice No: %d", a.sid);
            printf("\nDate: %s", a.d);
            printf("\nAmount: %ld", a.amt);
            {
                printf("\n\nEnter Data To Modify Record");
                printf("\n\nDate: ");
                scanf("%s", a.d);
                printf("\nAmount: ");
                scanf("%ld", &a.amt);
                a.vat = a.amt * 0.13;
                printf("\nRecord Modified");
                break;
            }
        }
    fseek(fp, -size, 1);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    getch();
    if (flag == 0)
    {
        printf("Record not found");
        getch();
    }
}
void func_delete_sales(void)        
{
    fp = fopen("svat.dat", "r+");
    int did, f = 0;
    fptr = fopen("stemp.dat", "w+");
    printf("\nDelete Record By Sales INVOICE NO.");
    printf("\nEnter INVOICE NO.: ");
    scanf("%d", &did);

    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        if (did == a.sid)
        {
            f = 1;
        }
        if (did != a.sid)
        {
            fwrite(&a, sizeof(a), 1, fptr);
        }
    }
    if (f == 1)
    {
        printf("\nRecord Deleted Successfully");
        getch();
    }
    else

    {
        printf("\nRecord not found");
        getch();
    }

    fclose(fp);
    fclose(fptr);
    remove("svat.dat");
    rename("stemp.dat", "svat.dat");
}
void purchase(void)
{
    system("cls");
    printf("\n\t WELCOME TO THE PURCHASE RECORDS\n");
    printf("\n**********************************************************");
    printf("\n\n\t PURCHASE MENU");
    printf("\n 1. ADD Record");
    printf("\n 2. View Record");
    printf("\n 3. Modify Record");
    printf("\n 4. Delete Record");
    printf("\n 5. Return to Main Menu");
    printf("\n Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fp = fopen("pvat.dat", "a+");
        printf("\n\n\n\t ENTER THE FOLLOWING DATA\n");
        printf("INVOICE NO.: ");
        scanf("%d", &a.pid);
        printf("\n DATE: ");
        scanf("%s", a.d);
        printf("\n PURCHASE AMOUNT: ");
        scanf("%ld", &a.amt);
        a.vat = a.amt * 0.13;
        fwrite(&a, sizeof(a), 1, fp);
        printf("Record Added Successfully");
        fclose(fp);
        getch;
        break;
    /////////////////////////////////////////////////////////////
    case 2:
        func_view_purchase();
        break;
    /////////////////////////////////////////////////////////////
    case 3:
        func_modify_purchase();
        break;
    //////////////////////////////////////////////////////////////////////
    case 4:
        func_delete_purchase();
        break;
    /////////////////////////////////////////////////////////////
    case 5:
        main();
        break;
    }
};
void func_view_purchase(void)
{
    int g = 0;
    float tp = 0;
    fp = fopen("pvat.dat", "r");
    if (fp == NULL)
    {
        printf("Error: File not opened correctly.\n");
        return;
    }
    printf("\n\n\n The Records is Displayed Below");
    printf("\n**************************************************");
    printf("\n\nINVOICE NO.\t DATE \t PURCHASE AMOUNT \t PURCHASE VAT\n");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        g = 1;
        printf("%d\t%s\t%ld\t\t%f", a.pid, a.d, a.amt, a.vat);
        printf("\n");
        tp = a.vat + tp;
    }
    printf("\n\n\t The Total purchase VAT=%f", tp);
    if (g == 0)
    {
        printf("\nrecord not found");
    }
    getch();
}
void func_modify_purchase()
{
    fp = fopen("pvat.dat", "r+");
    int mid, flag = 0;
    printf("\n\n Enter INVOICE NO. to Modify the Records: ");
    scanf("%d", &mid);
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        if (mid == a.pid)
        {
            flag = 1;
            printf("\nRecord Matched");
            printf("\nID: %d", a.pid);
            printf("\nDate: %s", a.d);
            printf("\nAmount: %ld", a.amt);
            printf("\n\nEnter Data To Modify Record");
            printf("\n\nDate: ");
            scanf("%s", a.d);
            printf("\nAmount: ");
            scanf("%ld", &a.amt);
            a.vat = a.amt * 0.13;
            printf("\nRecord Modified");
            break;
        }
    }
    fseek(fp, -size, 1);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    getch();
    if (flag == 0)
    {
        printf("Record not found");
        getch();
    }
}
void func_delete_purchase(void)
{
    fp = fopen("pvat.dat", "r+");
    int did, g = 0;
    fptr = fopen("ptemp.dat", "w+");
    printf("\nDelete Record By INVOICE NO.");
    printf("\nEnterINVOICE NO.: ");
    scanf("%d", &did);
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        if (did == a.pid)
        {
            g = 1;
        }
        if (did != a.pid)
        {
            fwrite(&a, sizeof(a), 1, fptr);
        }
    }
    if (g == 1)
    {
        printf("\nRecord Deleted Successfully");
        getch();
    }
    else
    {
        printf("\nRecord not found");
        getch();
    }
    fclose(fp);
    fclose(fptr);
    remove("pvat.dat");
    rename("ptemp.dat", "pvat.dat");
}
void information(void)
{
again:
    system("cls");
    printf("\n\n\t This Software is Prepared By\n");
    printf("\n 1. Ashok Rimal\n 2. Shishir Pandey\n 3. Rajan Gaire\n 4. Abishekh Nepal");
    printf("\nProject Work of C Programming");
    printf("\n Second Semester BCA");
    printf("\n Crimson College of Technology");
    printf("\n With The Help Of Teacher And Inspector By IT Coordinator.");
    printf("\n Some Basic Information About The Program.");
    printf("\n 1.In this program the user needs to just input the date and amount (purchase/sale and the program automatically calculates the VAT.");
    printf("\n 2.The VAT is calculated as per 13% of the amount which is as per the Nepalese Govt.");
    printf("\n 3.The records are kept on the daily basis as per the total purchase/sale in day irrespective of item name.");
    printf("\n 4.In the view menu the total VAT amount i.e. the sum of all the entered records is displayed making easy to know the total.");
    printf("\n 5.The user can modify the records entering the date of records to modify in case of error in the date or amount.");
    printf("\n 6.Since the delete of individual record was not possible due to some errors so user can modify the record instead of deleting or putting 0 in place.");
    printf("\n 7.To delete the entire record delete 'svat.dat' and 'pvat.dat' from the computer.");
    printf("\n 8.User can separate each month record by changing the name of svat.dat and pvat.dat through C programming.");
    printf("\n\n Press 1 To Go To Main Menu: ");
    switch (getch())
    {
    case '1':
        main();
        break;
    default:
        printf("Wrong Choice");
        getch();
    }
    goto again;
};
