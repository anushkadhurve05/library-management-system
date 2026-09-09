#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char name[50];
    int issued;
    char borrower[50];
    int issuedate;
    int returndate;
    
};
 struct Book books[100];
    int count = 0;
    int choice;



 void savebook()
   {
      FILE*fp;
      fp = fopen ("books.txt","w");

      if( fp == NULL)
      {
        printf("File cannot be opend\n");
        return;
      }

      int i;
      for(i = 0; i< count; i++)
      {
        fprintf(fp, "%d|%s|%d\n",
        books[i].id,
        books[i].name,
        books[i].issued);
      }
      fclose(fp);
    }

   void loadbook()
    {
      FILE*fp;
      fp = fopen ("books.txt","r");

      if(fp == NULL)
      {
         return;
      }
      count = 0;

      while(fscanf(fp,"%d|%[^|]|%d\n",
        &books[count].id,
        books[count].name,
        &books[count].issued)==3)
      {
         count++;
      }
      fclose(fp);
    }
    int main()
    {
        char username[20];
        char password[20];

        loadbook();

        printf("Enter Usename:\n");
        printf("Enter Password:\n");

        scanf("%s",username);
        scanf("%s",password);

        if(strcmp(username,"admin") == 0)
        {
            printf("Correct username\n");
        }
        else
        {
            printf("Invalid username\n");
        }

        if(strcmp(password,"12345") == 0)
        {
            printf("Correct Password\n");
        }
        else
        {
            printf("Invalid username\n");
        }


    do
    {
        int available = 0;
        int issued = 0;

        for(int i = 0; i < count; i++)
        {
            if(books[i].issued == 0)
            {
                available++;
            }
            else
            {
                issued++;
            }
        }

        printf("\n=====LIBRARY DASHBOARD=====\n");
        printf("Total Books :%d\n",count);
        printf("Available Book :%d\n",available);
        printf("Issued Books :%d\n",issued);


        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Upadate Book Detail\n");
        printf("6. Issue a Book\n");
        printf("7. Return a Book\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {          
                int found = 0;
           
                printf("Enter Book ID:");
                scanf("%d", &books[count].id);
                
                for(int i  =  0; i < count; i++)
                {
                    if(books[i].id == books[count].id )
                    {
                        found = 1;
                        break;
                    }
                }
                if(found == 1)
                {
                    printf("Book already exits\n");
                }
                else
                {
                    printf("Enter Book name:");
                    scanf(" %[^\n]", books[count].name);
                    books[count].issued = 0;
                    count++;
                    savebook();
                    printf("\nBook added succesfully!\n");
                } 
                break;
            
            }
            
            case 2:
                if(count == 0)
                {
                    printf("\nNo book available.\n");
                }
                else
                {
                    int i;

                    printf("\n======BOOK DETAIL======\n");

                    for(i = 0; i < count; i++)
                    {
                        printf("\nBOOK %d\n", i + 1);
                        printf("ID:%d\n", books[i].id);
                        printf("NAME:%s\n", books[i].name);
                        if(books[i].issued == 0)
                        {
                            printf("Status:Available\n");
                        }
                        else
                        {
                            printf("Status:issued\n");
                        }
                        printf("Borrower's Name: %s\n", books[i].borrower);
                        printf("Issueing Date: %s\n",books[i].issuedate);
                        printf("Return Date: %s\n",books[i].returndate);
                               
                    }
                }
                break;


            case 3:
                {
                    int searchID, found = 0;

                    printf("Enter Book ID to seach:");
                    scanf("%d", &searchID);

                    for(int i  =  0;i < count; i++)
                    {
                        if(books[i].id == searchID)
                        {
                            printf("\nBook Found!\n");
                            printf("Book ID: %d\n", books[i].id);
                            printf("Book Name: %s\n", books[i].name);
                            found = 1;
                            break;
                        }
                    }
                    
                    if(found == 0)
                    {
                        printf("Book Not Found!\n");
                    }
                } 
                break;

            case 4:
                 {
                    int  deletebook, found = 0 ;

                    printf("Enter Book ID to Delete\n");
                    scanf("%d", &deletebook);

                    for(int i = 0; i < count; i++)
                    {
                         if(books[i].id == deletebook)
                        {
                            found = 1;

                            for(int j = i; j < count - 1; j++)
                            {
                                books[j] = books[j + 1];
                            }
                            count--;
                            savebook();

                            printf("Book deleted succesfully\n");
                        break;
                        }
                    }    
                        
                          if (found == 0) 
                        {
                            printf("Book not found.\n");
                        }                
                
                 break;
                    } 
             case 5:
                {
                    int updatebook, found = 0;

                    printf("Enter book id t update\n");
                    scanf("%d", &updatebook);

                    for(int i  =  0;i < count; i++)
                    {
                        
                        if(books[i].id == updatebook)
                        {
                            printf("\nBook Found!\n");
                            printf("Book ID: %d\n", books[i].id);
                            printf("Book Name: %s\n", books[i].name);
                           
                            printf("Enter new book name: \n");
                            scanf(" %[^\n]", books[i].name);
                            savebook();

                            printf("Book updated sussesfully!\n");

                            found = 1;
                            break;
                        }
                    }
                    
                    if(found == 0)
                    {
                        printf("Book Not Found!\n");
                    }
                } 
                break;


                 case 6:
                 {
                    int issueID;
                    int found = 0;

                    printf("Enter Book ID to Issue:");
                    scanf("%d", &issueID);

                    for(int i = 0; i < count; i++)
                    {
                        if(books[i].id == issueID)
                        {
                            found = 1;

                            if(books[i].issued == 0)
                            {
                                books[i].issued = 1;
                                printf("Enter Borrower's Name:");
                                scanf(" %[^\n]",books[i].borrower);

                                printf("Enter Issueing Date:");
                                scanf(" %s",&books[i].issuedate);
                                savebook();

                                printf("Book Issued succesfully!\n");
                            }
                            else
                            {
                                printf("This book is already issued!\n");
                            }
                            break;
                        }
                    }
                    if(found == 0)
                    {
                        printf("Book Not Found!\n");
                    }
                    break;
                 }
                
               
                 case 7:
{
    int returnbook, found = 0;

    printf("Enter Book ID to return the book: ");
    scanf("%d", &returnbook);

    for(int i = 0; i < count; i++)
    {
        if(books[i].id == returnbook)
        {
            found = 1;

            if(books[i].issued == 1)
            {
                printf("Enter Return Day: ");
                scanf("%d", &books[i].returndate);

                int borrowedDays;
                int lateDays = 0;
                int fine = 0;

                borrowedDays = books[i].returndate - books[i].issuedate;

                if(borrowedDays > 7)
                {
                    lateDays = borrowedDays - 7;
                    fine = lateDays * 10;
                }

                printf("\n--- Fine Details ---\n");
                printf("Days Borrowed: %d\n", borrowedDays);
                printf("Late Days: %d\n", lateDays);
                printf("Total Fine: Rs.%d\n", fine);

                books[i].issued = 0;

                strcpy(books[i].borrower, "");

                books[i].issuedate = 0;
                books[i].returndate = 0;

                savebook();

                printf("\nBook returned successfully and is now available!\n");
            }
            else
            {
                printf("Book is already available in the library!\n");
            }

            break;
        }
    }

    if(found == 0)
    {
        printf("Book Not Found!\n");
    }

    break;
}

    

                 case 8:
                 {
                    printf("---thanku fr visiting---");
                 }
                 break;

            
                
             default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
} 

