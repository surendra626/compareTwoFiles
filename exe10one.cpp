

#include<iostream>
#include<stdexcept>

using namespace std;
int f1(int);
int fd(int);
void f222(double d);
int main()
{

char g[89];
int k=99;
//cin>>g;
//cout<<g<<"\n";
int f=k/10;
cout<<f;
f=isalpha(k);
cout<<"\n"<<f<<"     "<<(char) k<<"\n";

int fc=f1(2)+fd(3);

int e=1;
while(0<e)e++;
cout <<" e value after nagitive"<<e<<"\n";

int v[10];

int i=1;
v[i]=i++;
cout<<"  v[i]==  "<<v[i];
cout<<"\n"<<"\n"<<"strings example"<<"\n";

string s1="asdas  afafafa  ";
string s2="bcvxcvxv sfsfd";
const char* cd=(s1+s2).c_str();
cout<<"\n"<<s1;
cout<<"\n"<<s2;
cout<<"\n"<<cd;
cout<<"\n";

  f222(9876677887767343453.9877e+2);

}

void f222(double d)
{
char c=static_cast<char>(d);
double dd=static_cast<double>(c);
if(c!=dd)
throw  runtime_error("narrow_cast faile");

cout << " c=  " <<"\n";
}

int f1(int c)
{
cout<<"\n"<<c<<"  f1";
return c;
}
int fd(int c)
{
cout<<"\n"<<c<<"   fd"<<"\n";
return c;
}
