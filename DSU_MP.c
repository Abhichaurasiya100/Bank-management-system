#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct account_details
{
  char name[20];
  char address[100];
  char mobile_no[10];
  char email[20];
  char account_no[15];
}account_details[10];
void clear()
{
  system("cls");
}
void add_account()
{
  char name[20];
  char address[100];
  char mobile_no[10];
  char email[20];
  char account_no[15]="319301023";
  int postfix;
  char end[5];
  int j=0,i;
  int size=0;
  for(i=0;i<10;i++)
  { //printf("%s",account_details[i].account_no);
  //  char compare[15]="\0";
size=0;
    while (account_details[i].account_no[size] != '\0') {
        ++size;
      }
    if(size==0)
    {
        break;
    }
      else
      {
         j=i;
      }
    }

printf("%d",j);
  if(i==0)
    {
      postfix=0001;
      itoa(postfix,end,10);
      int l,m=0;
      l=0;
      while (account_no[l] != '\0') {
          ++l;
        }
        for (m = 0; end[m] != '\0'; ++m, ++l) {
          account_no[l] = end[m];
        }
    }
    else
    {
      char dupli[15];
      strcpy(dupli,account_details[j].account_no);
    //  printf("%s",dupli);
      char *selection;
      selection=strtok("3193010237","319301023");
      printf("%s",selection);
      strcpy(end,selection);
      postfix=atoi(end);
      //printf("%s",end);
      ++postfix;
      itoa(postfix,end,10);
      int l,m=0;
      l=0;
      while (account_no[l] != '\0') {
          ++l;
        }
        for (m = 0; end[m] != '\0'; ++m, ++l) {
          account_no[l] = end[m];
        }
    }


  printf("Enter name :-  ");
  scanf("%s",name);
  printf("\nEnter address :-  ");
  scanf("%s",address);
  printf("\nEnter mobile number :-  ");
  scanf("%s",mobile_no);
  printf("\nEnter email ID :-  ");
  scanf("%s",email);

  printf(" name :-  %s",name);
  printf(" address :-  %s",address);
  printf(" mobile number :-  %s",mobile_no);
  printf(" email ID :-  %s",email);
  printf(" account no :- %s",account_no);
}
void remove_account()
{

}
void upadte_details()
{

}
void view_details()
{

}
void withdrawal()
{

}
void deposit()
{

}
void mark_active()
{

}
void mark_inactive()
{

}
void view_transction()
{

}
void admin()
{
  int choice;
  while(choice!=27){
  printf("--->> Enter '1' to open new account <<---\n");
  printf("--->> Enter '2' to close account <<---\n");
  printf("--->> Enter '3' to update account details <<---\n");
  printf("--->> Enter '4' view all acount <<---\n");
  printf("--->> Enter '5' to make withdrawal entry <<---\n");
  printf("--->> Enter '6' to make deposit entry <<---\n");
  printf("--->> Enter '7' to mark an account active <<---\n");
  printf("--->> Enter '8' to mark an account inactive <<---\n");
  printf("--->> Enter '9' view transction <<---\n");
  printf("--->> Enter '10' if you exit <<---\n");
  printf("\nEnter choice: ");
  scanf("%d",&choice);
  if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7||choice==8||choice==9||choice==10)
  {
    break;
  }
  else
  {
    clear();
    printf("Wrong Option Try again ! \n\n\n\n");
  }
  }
  switch (choice) {
    case 1: add_account();  break;
    case 2: remove_account();  break;
    case 3: upadte_details();  break;
    case 4: view_details();  break;
    case 5: withdrawal();  break;
    case 6: deposit();  break;
    case 7: mark_active();  break;
    case 8: mark_inactive(); break;
    case 9: view_transction(); break;
    case 10: exit(0);
  }
}
void main_menu()
{
  int choice;
  while(1)
  {
  printf("--->> Enter '1' if you are Admin <<---\n");
  printf("--->> Enter '2' if you want to exit <<---\n");
  printf("\n\n Enter your choice :-  ");
  scanf("%d",&choice);
  if(choice==1||choice==2)
  {
    break;
  }
  else
  {
    clear();
    printf(" Wrong option! \n");
  }
  }
  switch (choice)
  {
    case 1:clear();admin(); break;
    case 2:clear();exit(0);

  }
}
void fetch();
int main()
{
  printf("                                                                       Bank Management System\n");
  printf("\n\n\n\n\n\n\n                                                      --->> Please select appropriate option to move further <<---\n");
  fetch();  main_menu();

printf("%s",account_details[1].name);
}
void fetch()
{ char temp[300];
  FILE *file=fopen("account_details.csv","r");
/*  while(fgets(temp,sizeof(temp),file)!=NULL)
  {*/
fgets(temp,sizeof(temp),file);
    char *selection;
    selection=strtok(temp,",");
    strcpy(account_details[0].name,selection);

    selection=strtok(NULL,",");
    strcpy(account_details[0].address,selection);

    selection=strtok(NULL,",");
    strcpy(account_details[0].email,selection);

    selection=strtok(NULL,",");
    strcpy(account_details[0].mobile_no,selection);

    selection=strtok(NULL,"\n");
    strcpy(account_details[0].account_no,selection);



  /*}*/
}
/*void user_account_holder()
{

authenticate_account_holder();

}
int authenticate_account_holder()
{
  printf("Hi\nPlease enter your Username and Password which is given to you. \n\n");
  char user_name[10];
  char password[10];
  printf("Enter your Username :- ");
  scanf("%s",user_name);
  printf("Enter your Password :- ");
  scanf("%s",password);
  int result=0;
  int i,j;
    char temp[100];
  FILE *file=fopen("user_account_holder.csv","r+");
  char user[10];
  char pass[10];
  while(fgets(temp,sizeof(temp),file)!=NULL){
  char *text;
  text = strtok(temp, ",");
      strcpy(user,text);
     text = strtok(NULL, "");
  strcpy(pass,text);
  i=strcmp(user,user_name);
  printf("%s\t%s",user,pass);

    if(i==0)
    { printf("correct\n");
      result=1;
      break;

    }
    else
    {printf("incorrect\n");
      result=0;
    }
  }
}
*/
