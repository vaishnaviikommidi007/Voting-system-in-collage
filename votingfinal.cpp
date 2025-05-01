#include<iostream>
#include<stack>
using namespace std;
class Node{
	public:
		long long int id;
		Node* next;
		Node(long long int val)
		{
			id=val;
			next=NULL;
		}
};
bool findplicate(Node* head,long long int id)
	{
		Node* temp=head;
		while(temp!=NULL)
		{
			if(temp->id==id)
			{
				return true;
			}
			temp=temp->next;
	 	}
	 	return false;
	}	
void insertNode(Node*& head,long long int id)
	{
		Node* newNode=new Node(id);
		newNode->next=head;
		head=newNode;
	}
class User{
	private:
		Node* head;
	public:	
	long long int id;
	int choice;
		bool enterthechoice(Node*& head)
		{
			cout<<"enter the user id\n";
		    cin>>id;
			if(findplicate(head,id))
			{
				cout<<"you are already voted before:";
				return false;
			}
			else
			{
			cout<<"enter the choice of our requried:\n";
			cout<<"(1 for varun),(2 for nithya),(3 for deepthi),(any other number for nota)";
			cin>>choice;
			cout<<"Your vote is succefully registered.\n";
			insertNode(head,id);
			return true;
			}
		}
					
};
int main()
{
	stack<int>mystack;
	Node* idlist=NULL;
	int n;
	cout<<"enter no.of user requried for voting:";
	cin>>n;
	User *user=new User[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter "<<i+1<<"member vote:\n";
		if(user[i].enterthechoice(idlist))
		{
			findplicate(idlist,user[i].choice);
			mystack.push(user[i].choice);
			cout<<"\nThe top of the list contains the choice: "<<mystack.top();
		}
		else
		{
			cout<<"Your vote is already registered:";
		}
	}
	int varunvotes=0;
	int nityavotes=0;
	int deepthivotes=0;
	int nota=0;
	while(!mystack.empty())
	{
		int vote=mystack.top();
		if(vote==1)
		{
			varunvotes++;
		}
		else if(vote==2)
		{
			nityavotes++;
		}
		else if(vote==3)
		{
			deepthivotes++;
		}
		else
		{
			nota++;
		}
		mystack.pop();
	}
	cout<<"\nHence the no.of votes for the following canditates are:";
	cout<<"\nvarun votes are= "<<varunvotes;
	cout<<"\nnitya votes are= "<<nityavotes;
	cout<<"\ndeepthi votes are= "<<deepthivotes;
	cout<<"\nthe nota votes are= "<<nota;
	if(varunvotes>nityavotes)
	{
		if(varunvotes>deepthivotes)
		{
			if(varunvotes>nota)
			{
				cout<<"varun is winnner\n";
			}
			else
			{
				cout<<"no need of leader\n";
			}
		}
		else
		{
			if(deepthivotes>nota)
			{
				cout<<"deepthi is winner\n";
			}
			else
			{
				cout<<"no need of leader\n";
			}
		}
	}
	else
	{
		if(nityavotes>deepthivotes)
		{
			if(nityavotes>nota)
			{
				cout<<"nitya is winner\n";
			}
			else
			{
				cout<<"there is no wanted a leader\n";
			}
		}
		else
		{
			if(deepthivotes>nota)
			{
				cout<<"deepthi is winner\n";
			}
			else
			{
				cout<<"no requried of leader:";
			}
		}
	}
	delete[] user;
	while(idlist!=NULL)
	{
		Node* temp=idlist;
		idlist=idlist->next;
		delete temp;
	}
	return 0;
}

