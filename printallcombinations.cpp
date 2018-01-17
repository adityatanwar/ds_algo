/*If user gives input 123,then abc,aw,lc should be printed*/
#include <iostream>
using namespace std;
void print(char a[],int start,char output[],int index)
{
	if(a[start]=='\0')
	{	
		cout<<output<<"\n";
		return;
	}
	int firstdigit=a[start]-'0'; //this converts character to integer
    char ch=a[start] - '1' +'A';
    output[index]=ch;
    output[index+1]='\0';
    print(a,start+1,output,index+1);
    if(a[start+1]!='\0')
    {
    	int seconddigit=a[start+1]-'0';
    	int finaldigit=firstdigit*10+seconddigit;
    	if(finaldigit<=26)
    	{
    		char ch='A'+(finaldigit-1);
    		output[index]=ch;
    		output[index+1]='\0';
    		print(a,start+2,output,index+1);
    	}

    }
}
int main()
{
  char a[1000],output[1000];
  cin>>a;
  print(a,0,output,0);
}