/*
Name:
Date:
Description:
Sample i/p:
Sample o/p:
*/

#include<stdio.h>
#include <time.h>

char name[20];
int deposit,amount = 1000,acc_no, with_draw,tf_amount;

void menu();
void with_Draw();
void Transfeer_the_money();
void Account_details();
void Transcation_Details();
void divider()
{
    for(int i= 0;i < 50;i++)
    {
	printf("-");
    }
}
int main()
{
    int choice;
    printf("Enter Your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your acc_no ");
    scanf("%d",&acc_no);
    while(1)
    {
    menu();
    printf("Enter the number: ");
    scanf("%d",&choice);
   
    switch(choice)
    {
	case 1:

	    system("clear");
	    Deposit();
	    break;
	case 2:

	    system("clear");

	    with_Draw();
	    break;
	case 3:

	    system("clear");
	    Transfeer_the_money();
	    break;
	case 4:

	    system("clear");
	    Account_details();
	    break;
	case 5:

	    system("clear");
	    Transcation_Details();
	    break;
	case 6:

	    system("clear");
	    Last_blance();
	    exit(0);

	default:
	    printf("INVALID OPTION\n");
		break;
    }
    }

	   

}
void menu()
{
    printf("\n\nMAIN MENU\n");
    divider();
    printf("\n1.Deposit_the_amount \n");
    printf("2.Withdraw_the_amount \n");
    printf("3.Transfer_the_moneys \n");
    printf("4.Account_Details \n");
    printf("5.Transcation_Details \n");
    printf("6.Last_blance\n");
}

void Deposit()
{
    time_t tm;
    time(&tm);
   FILE *fptr = fopen("acount_data.txt","a");
   if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }


    printf("DEPPOSIT THE MONEY \n");
    printf("enter your deposit  the money: ");
    scanf("%d",&deposit);
    amount += deposit;
    printf("***************************DEPOSITE THE AMOUNT SUCESSFULLY*******************\n");
    divider();

    printf("\nCURRENT BLANCE: %d\n",amount);

   fprintf(fptr,"rupes: %dDeposit the amount\n",deposit);

   fprintf(fptr,"Date /Tim of the transcation %s",ctime(&tm));


    // Ensure the data is written to the file
    fflush(fptr);

    // Close the file
    fclose(fptr);

   getchar();


}
void with_Draw()
{ 

    time_t tm;
    time (&tm);

    FILE *fptr = fopen("acount_data.txt","a");
    if(fptr == NULL)
    {
	printf("The file is not exist: \n");
	return;
    }


    printf("ENTER THE WITHDRAW MONEY: ");
    scanf("%d",&with_draw);
    amount -= with_draw;
    printf("WITHDRAW SUCESSFULLY: \n");
    divider();
    printf("\nCURRENT BLANCE: %d\n",amount);
    fprintf(fptr,"rupes %dwithdraw the money: \n",with_draw);
      fprintf(fptr, "Date/Time of the withdrawal: %s", ctime(&tm)); // Corrected format
       // Ensure the data is written to the file
    fflush(fptr);

    // Close the file
    fclose(fptr);

    getchar();
}
void Transfeer_the_money()
{
    time_t tm;
    time(&tm);
    FILE  *fptr = fopen("acount_data.txt","a");

    
   int ac;
   printf("ENTER THE  AMOUNT: ");
   scanf("%d",&tf_amount);
   printf("Enter the  account number: ");
   scanf("%d",&ac);
   if(amount < tf_amount)
   {
       printf("SORRY ITS insuffinciant funds\n");
   }
   else
   {
       amount -= tf_amount;
   
      printf("transfer the amounnt succesfully.new blance: %d\n",amount);
   
       fprintf(fptr,"rupes %dttarasfer amount \n",tf_amount);
       fprintf(fptr,"date/time  of  the transfdwer amount:%s",ctime(&tm));
       fflush(fptr);
       
   }
   fclose(fptr);

}
void Account_details()
{

    printf("account details\n");
   
    for(int i=0;i<50;i++)
    {
	printf("-");
    }
    printf("\n");
    printf("ACCOUNT USER: %s\n",name);
    printf("Account no: %d\n",acc_no);
    printf("Total ammount: %d\n",amount);


}

void Transcation_Details()
{

    printf("view your transcation details:\n");
    FILE *fptr = fopen("acount_data.txt","r");

    if(fptr ==  NULL)
    {
	printf("file does not exist\n");
    }

	char c = fgetc(fptr);
    if (c == EOF) {
        printf("No transaction details available.\n");
    } else {

        do {
            printf("%c", c);
            c = fgetc(fptr);
        } while (c != EOF);

    }

    fclose(fptr); // Close the file
    printf("\nTransaction details displayed successfully.\n");


}
void Last_blance()
{
    printf("ACCOUNT USER: %s\n",name);
	printf("account no:%d\n",acc_no);
	printf("current amount: %d",amount);

    
}
    




