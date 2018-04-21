#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

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

    Node *insertB(string s1,string s2,Node *temp)
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
            temp->left=insertB(s1,s2,temp->left);

        else if(temp->E1 == s1 && temp->E2 > s2)
            temp->left=insertB(s1,s2,temp->left);

        else if(temp->E1 == s1 || temp->E2 < s2)
            temp->right=insertB(s1,s2,temp->right);

        else if(temp->E1 < s1 )
            temp->right=insertB(s1,s2,temp->right);

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

public:
    Node *root=NULL;

    void insertE(vector<string> bill)
    {
        for (int i=0;i<bill.size();i++)
        {
            for (int j=i+1;j<bill.size();j++)
            {
                root=insertB(bill[i],bill[j],root);
            }
        }
    }

    void triverse()
    {
        Preorder(root);
    }


};





int main(){
    int n,qcheck=1,h;
    string s;
    inventor obj;

    while(qcheck)
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
