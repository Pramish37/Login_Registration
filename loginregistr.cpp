#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c; 
    cout<<"\t\t\t\t________________________________________________\n\n\n\n";
    cout<<"\t\t\t\t        Welcome to the Login page                \n\n\n";
    cout<<"\t\t\t\t____________________MENU__________________________\n\n";
    cout<<"\t\t\t\t                                                   \n\n";
    cout<<"\t| Press 1 To Login                       |"<<endl;
    cout<<"\t| Press 2 To Registration                |"<<endl;
    cout<<"\t| Press 3 Tf you forgot you Password     |"<<endl;
    cout<<"\t| Press 4 If you wish to Exit            |"<<endl;
    cout<<"\t\t\t\t Please enter your choice : "<<endl;
    cin>>c;

    switch(c)
    {
        case 1:
            login();
            break;

        case 2:
             registration();
             break;

        case 3:
             forgot();
             break;
        case 4:
             cout<<"\t\t\t Thank you! \n\n";
             break;
        default:
             system("cls");
             cout<<"\t\t\t Your input is invalid! n\n\n"<<endl;
             main();
    }    

}

void login()
{
    int count; string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the Username and Password: "<<endl;
    cout<<"\t\t\t Username: "<<endl;
    cin>>userId;
    cout<<password;
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass == password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
        cout<<userId<<"\n Your login is successfull \n Thanks for loggin in! \n";
        main();
    }
    else{
        cout<<"\n Login error \n Please check your username and password\n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t enter the username: ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password: ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your identity by username: "<<endl;
    cout<<"Press 2 to go back to the main menu: "<<endl;
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;

    switch(option)
      {
          case 1:
          {
              int count=0;
              string suserId,sId,spass;
              cout<<"\n\t\t Enter the username which you remembered :";
              cin>>suserId;

              ifstream f2("records.txt");
              while(f2>>sId>>spass)
              {
                  if(sId==suserId)
                  {
                      count=1;
                  }
              }
              f2.close();
              if(count==1)
              {
                  cout<<"\n\n Your account is found! \n";
                  cout<<"\n\n Your password is : "<<spass;
                  main();

              }
              else{
                  cout<<"\n\t Sorry! Your account is not found! \n";
                  main();
              }
                 break;
          }
          case 2:
               {
                 main();
               }
             default:
                cout<<"\t\t\t Wrong choice! Please try again "<< endl;
                forgot();

      } 

}


