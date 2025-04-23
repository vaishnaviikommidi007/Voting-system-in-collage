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
		return false;
	 	}
	}	
void insertnode(Node*& head,long long int id)
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
		bool enterthechoice(Node* head)
		{
			cout<<"enter the user id\n";
		    cin>>id;
			if(findplicate(head,id))
			{
				return false;
			}
			else
			{
			cout<<"enter the choice of our requried:\n";
			cout<<"(1 for varun),(2 for nithya),(3 for deepthi),(any other number for nota)";
			cin>>choice;
			cout<<"Your vote is succefully registered.\n";
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
	User user[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter "<<i+1<<"member vote:\n";
		if(user[i].enterthechoice(idlist))
		{
			findplicate(idlist,user[i].choice);
			mystack.push(user[i].choice);
			cout<<"The top of the list contains the choice: \n"<<mystack.top();
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
	cout<<"Hence the no.of votes for the following canditates are:";
	cout<<"varun votes are= "<<varunvotes;
	cout<<"nitya votes are= "<<nityavotes;
	cout<<"deepthi votes are= "<<deepthivotes;
	cout<<"the nota votes are= "<<nota;
	if(varunvotes>nityavotes)
	{
		if(varunvotes>deepthivotes)
		{
			if(varunvotes>nota)
			{
				cout<<"varun is winnner";
			}
			else
			{
				cout<<"no need of leader";
			}
		}
		else
		{
			if(deepthivotes>nota)
			{
				cout<<"deepthi is winner";
			}
			else
			{
				cout<<"no need of leader";
			}
		}
	}
	else
	{
		if(nityavotes>deepthivotes)
		{
			if(nityavotes>nota)
			{
				cout<<"nitya is winner";
			}
			else
			{
				cout<<"there is no wanted a leader";
			}
		}
		else
		{
			if(deepthivotes>nota)
			{
				cout<<"deepthi is winner";
			}
			else
			{
				cout<<"no requried of leader:";
			}
		}
	}
}
