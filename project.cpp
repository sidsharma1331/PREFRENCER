#include <iostream>
#include <vector>
#include <fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

void menu();

class inventor
{
private :
    class Node
    {
    public:
        int val;
        string E1,E2;
        Node *left,*right;

    	Node(string s1, string s2)
    	{
    		val = 0;
    		E1 = s1;
    		E2 = s2;
    		left =right = NULL;
    	}

    };

    Node *PinsertE(string s1,string s2,Node *temp)
    {
        if(temp ==NULL )
        {
        cout<<"in";
            Node *New = new Node(s1,s2);
            return New ;
        }

        else if(temp->E1==s1 && temp->E2==s2 )
            temp->val+=1;

        else if(temp->E1 > s1 )
            temp->left=PinsertE(s1,s2,temp->left);

        else if(temp->E1 == s1 && temp->E2 > s2)
            temp->left=PinsertE(s1,s2,temp->left);

        else if(temp->E1 == s1 || temp->E2 < s2)
            temp->right=PinsertE(s1,s2,temp->right);

        else if(temp->E1 < s1 )
            temp->right=PinsertE(s1,s2,temp->right);

        return(temp);
    }

    void Preorder(Node *temp)
    {
        if( temp != NULL)
        {
            cout<<"\t";
            cout<<temp->E1<<" "<<temp->E2<<" "<<temp->val<<"\n";
            Preorder(temp->left);

            Preorder(temp->right);
        }
    }

    int Plogin()
    {
        char password[]="swager",admin_name[]="vikrant";
        char str[20],pass[20],temp;
        cout <<"Enter the ADMIN NAME\n";
        cin >>str;
        system("cls");
        printf("Enter the Password\n");
        int i=0;
        while(1)
        {
            temp=getch();
            if(temp==13)
            {
                pass[i]='\0';
                break;
            }
            else if(temp==8)
            {
                if(i>0)
                i--;
            }
            else
            {
                pass[i]=temp;
                i++;
            }
            printf("*");

        }
        printf("\n");
        if(strcmp(str,admin_name)==0 && strcmp(pass,password)==0)
        menu();
        else
        cout<<"Invalid Mail Id or Password\n";
    }

public:
    Node *root=NULL;

    void insertE(vector<string> bill);
    void triverse();
    void login();


};

void menu()
{   int choice;
    system("cls");
    system("color F");
    cout<<"\t\t\t\tTHAPAR INVENTORY SYSTEM\n";
    cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout<<"\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;

    system("cls");
    /*switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }*/

}



int main(){
    int n,qcheck=1,h;
    string s;
    inventor obj;

    //obj.login();
    menu();
    /*while(qcheck)
    {
        vector<string> bill;
        vector<int> quantity;
        cout<<"HOW MANY ELEMENTS ARE THERE";
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>s;
            cin>>h;
            bill.push_back(s);
            quantity.push_back(h);
        }
        ofstream ptr;
        ptr.open("record.txt",ios_base::app);
        for (int i=0;i<n;i++)
        {
            ptr<<bill[i]<<" "<<quantity[i]<<" ";
        }
        ptr<<"\n";
        ptr.close();
    }
    /*obj.insertE(bill);
        obj.triverse();*/
}

void inventor::insertE(vector<string> bill)
{
    for (int i=0;i<bill.size();i++)
    {
        for (int j=i+1;j<bill.size();j++)
        {
            root=PinsertE(bill[i],bill[j],root);
        }
    }
}

void inventor::triverse()
{
    Preorder(root);
}

void inventor::login()
{
    Plogin();
}

