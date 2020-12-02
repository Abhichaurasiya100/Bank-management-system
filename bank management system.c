#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char **sepstr(const char *buf, const char *sep){
    int i = 0, j = 0, k = 0, l = 0, stringCount = 0;

    /* If separator > buffer, return NULL */
    while (buf[i]) i++;
    while (sep[j]) j++;
    if (j > i) return NULL;

    char **strings = malloc(0);

    /* While we're not at the end of the buffer */
    while (*(buf+k)){
        /* If the characters match, check to see if it is the separator */
        if (*(buf+k) == *(sep)){
            for (l = 0; l < j; l++){
                /* If it isn't the separator, break */
                if (*(buf+k+l) != *(sep+l)) break;
                /* If it is the separator and the separator isn't the
                    beginning, add buf to buf+k bytes as a string */
                if (l == j-1 && k != 0){
                    strings = realloc(strings, (stringCount+1)*sizeof (char *));
                    strings[stringCount] = malloc(k+1);
                    memcpy(strings[stringCount++], buf, k);
                    buf += (j + k), k = -1;
                /* If it is the separator, but it's the beginning
                    of the string, skip it */
                } else if (l == j-1 && k == 0) {
                    buf += j, k = -1;
                }
            }
        }
        k++;
    }

    /* Add a string for the left over bytes if sep isn't the end */
    if (i != k && *(buf)){
        while (buf[l]) l++;
        strings = realloc(strings, (stringCount+1) * sizeof (char *));
        strings[stringCount] = malloc(l+1);
        memcpy(strings[stringCount++], buf, l);
    }

    /* Append NULL to array of strings */
    strings = realloc(strings, (stringCount+1) * sizeof (char *));
    strings[stringCount] = malloc(sizeof NULL);
    strings[stringCount] = NULL;

    return strings;
}
struct account_details
{
  char name[20];
  char address[100];
  char email[50];
  char account_no[15];
  long long balance;
  char mobile_no[10];
  struct account_details * next;
}*account_details;
struct account_details * head=NULL;
void fetch();
void remove_account();
void clear()
{
  system("cls");
}
void admin();
void add_account()
{


  char name[20];
  char address[100];
  char email[50];
  char mobile_no[10];
  char account_no[15]="319301023";
  long long balance;
   int postfix;
  char end[5];
  int j=0,i=0;
  int size=0;
 struct account_details **head1=&head;
 struct account_details *head2=*head1;
  while(head2!=NULL){
size=0;
char check[15];
strcpy(check,head2->account_no);
    while (check[size] != '\0') {
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
      ++i;
head2=head2->next;
}
  if(i==0)
    {
      postfix=1;
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
      struct account_details **head1=&head;
      struct account_details *head2=*head1;
      for(int i=0;i<j;i++)
      {
        head2=head2->next;
      }
      char dupli[15];
      strcpy(dupli,head2->account_no);

      char **selection=sepstr(dupli, "319301023");
      strcpy(end,*(selection));
      postfix=atoi(end);

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
  printf("\nEnter email ID :-  ");
  scanf("%s",email);
  printf("\nEnter mobile number :-  ");
  scanf("%s",mobile_no);
  printf("\nEnter opening balance :-  ");
  scanf("%ld",&balance);

printf("\n\n--->The below account is added");

printf("\n name :-  %s",name);
printf("\n address :-  %s",address);
printf("\n email ID :-  %s",email);
printf("\n mobile number :-  %s",mobile_no);
printf("\n account no :-  %s",account_no);
printf("\nEnter opening balance :- %ld",balance);
  FILE *file=fopen("account_details.csv","a+");
  fprintf(file,"%s,%s,%s,%s,%s,%ld\n",name,address,email,mobile_no,account_no,balance);
  fclose(file);
head=NULL;
  fetch();
  int z;
  printf("\n\n--->Enter 1 to add another account \nEnter 2 to reach main menu \nEnter '0' to exit\n :--> ");
  scanf("%d",&z);
  if(z==1)
  {clear();add_account();}
  else if(z==2)
  {clear();admin();}
  else if(z==3)
  {exit(0);}

}
void remove_account()
{

  int j=0;
  char account_no[15];
  char compare[15];
  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  printf("Enter account number which is going to be closed : ");
  scanf("%s",account_no);
int i=0;
  while(head2!=NULL)
  {
    strcpy(compare,head2->account_no);
    if(strcmp(account_no,compare)==0)
    {
      if(head2==NULL)
      {break;}
    }

    else
    {
      j=1;

      if(i==0)
      {
        FILE *file=fopen("account_details.csv","w+");
        fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head2->name,head2->address,head2->email,head2->mobile_no,head2->account_no,head2->balance);
        fclose(file);
        ++i;
        if(head2==NULL)
        {break;}
      }
      else
      {
        FILE *file=fopen("account_details.csv","a");
        fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head2->name,head2->address,head2->email,head2->mobile_no,head2->account_no,head2->balance);
        fclose(file);
        if(head2==NULL)
        {break;}
      }
    }
    head2=head2->next;
  }

  if(j==0)
  {
    FILE *file=fopen("account_details.csv","w");
    fclose(file);
  }
int z;
head=NULL;
fetch();
  printf("\n\n--->Enter 1 to remove another account \n--->>Enter 2 to reach main menu \n--->>Enter '0' to exit\n :--> ");
  scanf("%d",&z);
  clear();
  if(z==1)
  {clear();remove_account();}
  else if(z==2)
  {clear();admin();}
  else if(z==3)
  {exit(0);}

}
void upadte_details()
{

  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  char account_no[15];
  char compare[15];
  int choice=0;
  int i=0;
  printf("Enter account no for which you want to update details : ");
  scanf("%s",account_no);
  while(head2!=NULL)
  {
    strcpy(compare,head2->account_no);
    if(strcmp(compare,account_no)==0)
    {
      break;
    }
    head2=head2->next;
  }
  while(1){
  printf("follow the following steps\n ");
  printf("--->> Enter '1' if you want to update name <<---\n");
  printf("--->> Enter '2' if you want to update address <<---\n");
  printf("--->> Enter '3' if you want to update email ID <<---\n");
  printf("--->> Enter '4' if you want to update mobile number <<---\n");
  printf("Enter Choice : ");
  scanf("%d",&choice);
  if(choice==1||choice==2||choice==3||choice==4)
  {break;}
}

switch(choice){
case 1: printf("Enter new name for this account : ");scanf("%s",head2->name);break;
case 2: printf("Enter new address for this account : ");scanf("%s",head2->address);break;
case 3: printf("Enter new email for this account : ");scanf("%s",head2->email);break;
case 4: printf("Enter new mobile number for this account : ");scanf("%s",head2->mobile_no);break;
}
struct account_details **head3=&head;
struct account_details *head4=*head3;
while(head4!=NULL)
{
  if(i==0)
  {
    FILE *file=fopen("account_details.csv","w+");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);
    i=1;
  }
  else
  {

    FILE *file=fopen("account_details.csv","a");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);

}

head4=head4->next;
}
int z;
printf("\n\n--->Enter 1 to update another account \n--->>Enter 2 to reach main menu \n--->>Enter '0' to exit\n :--> ");
scanf("%d",&z);
clear();
if(z==1)
{clear();upadte_details();}
else if(z==2)
{clear();admin();}
else if(z==3)
{exit(0);}

}
void view_details()
{
  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  printf("Name\tAddress\tMobile No.\tEmail ID\tAccount No.\tBalance\n");

  while(head2!=NULL){
    printf("************************************************************************\n");
  printf("%s\t",head2->name);
  printf("%s\t",head2->address);
  printf("%s\t",head2->mobile_no);
  printf("        %s\t",head2->email);
  printf("%s\t",head2->account_no);
  printf("%lu\t\n",head2->balance);
  printf("************************************************************************\n");
  head2=head2->next;
}
int z;
printf("\n\n--->>Enter 1 to reach main menu \n--->>Enter '2' to exit\n :--> ");
scanf("%d",&z);
clear();
if(z==1)
{clear();admin();}
else if(z==2)
{exit(0);}

}
void withdrawal()
{
  long long money;
  char account_no[15];
  char compare[15];
  int i=0;
  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  printf("Enter account number for which you want to make withdrawal entry: ");
  scanf("%s",account_no);
  while(head2!=NULL)
  {
    strcpy(compare,head2->account_no);
    if(strcmp(compare,account_no)==0)
    {
      break;
    }
    head2=head2->next;
  }
  printf("\nEnter amount which is withdrawn : ");
  scanf("%lu",&money);
head2->balance=head2->balance-money;
struct account_details **head3=&head;
struct account_details *head4=*head3;
while(head4!=NULL)
{
  if(i==0)
  {
    FILE *file=fopen("account_details.csv","w+");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);
    i=1;
  }
  else
  {

    FILE *file=fopen("account_details.csv","a");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);

}
head4=head4->next;

}
int z;
printf("\n\n--->Enter 1 to make withdrawal for another account \n--->>Enter 2 to reach main menu \n--->>Enter '0' to exit\n :--> ");
scanf("%d",&z);
clear();
if(z==1)
{clear();withdrawal();}
else if(z==2)
{clear();admin();}
else if(z==3)
{exit(0);}

}
void deposit()
{
  long long money;
  char account_no[15];
  char compare[15];
  int i=0;
  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  printf("Enter account number forr which you want to make deposit entry: ");
  scanf("%s",account_no);
  while(head2!=NULL)
  {
    strcpy(compare,head2->account_no);
    if(strcmp(compare,account_no)==0)
    {
      break;
    }
    head2=head2->next;
  }
  printf("\nEnter amount which is deposited : ");
  scanf("%lu",&money);
head2->balance=head2->balance+money;
struct account_details **head3=&head;
struct account_details *head4=*head3;
while(head4!=NULL)
{
  if(i==0)
  {
    FILE *file=fopen("account_details.csv","w+");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);
    i=1;
  }
  else
  {

    FILE *file=fopen("account_details.csv","a");
    fprintf(file,"%s,%s,%s,%s,%s,%ld\n",head4->name,head4->address,head4->email,head4->mobile_no,head4->account_no,head4->balance);
    fclose(file);

}
head4=head4->next;

}
int z;
printf("\n\n--->Enter 1 to make deposit for another account \n--->>Enter 2 to reach main menu \n--->>Enter '0' to exit\n :--> ");
scanf("%d",&z);
clear();
if(z==1)
{clear();deposit();}
else if(z==2)
{clear();admin();}
else if(z==3)
{exit(0);}

}
void admin()
{
  int choice;
  while(1){
  printf("                                             --->> Enter '1' to open new account <<---\n");
  printf("                                             --->> Enter '2' to close account <<---\n");
  printf("                                             --->> Enter '3' to update account details <<---\n");
  printf("                                             --->> Enter '4' view all acount <<---\n");
  printf("                                             --->> Enter '5' to make withdrawal entry <<---\n");
  printf("                                             --->> Enter '6' to make deposit entry <<---\n");
  printf("                                             --->> Enter '7' if you exit <<---\n");
  printf("\n   Enter choice: ");
  scanf("%d",&choice);
  if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7)
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
    case 1: clear();add_account();  break;
    case 2: clear();remove_account();  break;
    case 3: clear();upadte_details();  break;
    case 4: clear();view_details();  break;
    case 5: clear();withdrawal();  break;
    case 6: clear();deposit();  break;
    case 7: exit(0);
  }
}
void athenticate()
{
  int pass=1122;
  int p;
  int result=0;
  while(result!=1)
  {
  printf("--->> Enter Password <<---\n");
  printf("--->>> ");
  scanf("%d",&p);
  if(pass==p)
  {result=1;}
  }
  clear();
  admin();
}
int main()
{
  printf("                                                                       Bank Management System\n");
  printf("\n\n\n\n\n\n\n                                                      --->> Please select appropriate option to move further <<---\n");
  fetch();
  struct account_details **head1=&head;
  struct account_details *head2=*head1;
  athenticate();
}
void fetch()
{
  char temp[300];
  FILE *file=fopen("account_details.csv","r");
  while(fgets(temp,sizeof(temp),file)!=NULL){
  account_details=malloc(sizeof(struct account_details));
    char strtoint[15];
    char *selection;
    selection=strtok(temp,",");
    strcpy(account_details->name,selection);
    selection=strtok(NULL,",");
    strcpy(account_details->address,selection);
    selection=strtok(NULL,",");
    strcpy(account_details->email,selection);
    selection=strtok(NULL,",");
    strcpy(account_details->mobile_no,selection);
    selection=strtok(NULL,",");
    strcpy(account_details->account_no,selection);
    selection=strtok(NULL,",");
    strcpy(strtoint,selection);
    account_details->balance=atoi(strtoint);
    struct account_details **head1=&head;
    account_details->next=NULL;
    if(*head1==NULL)
    {
      *head1=account_details;
    }
    else
    {
      struct account_details *head2=*head1;
      while(head2->next!=NULL)
      {
        head2=head2->next;
      }
      head2->next=account_details;
    }
}
}
