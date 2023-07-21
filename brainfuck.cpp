#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;

string remove_comments(string s,int n)
{
    string news="";
    for(int i=0;i<n;i++)
    {
        switch(s[i])
        {
            case '>':
            news=news+s[i];
            break; 
            case '<':
            news=news+s[i];
            break;
            case '+':
            news=news+s[i];
            break; 
            case '-':
            news=news+s[i];
            break;
            case '.':
            news=news+s[i];
            break; 
            case ',':
            news=news+s[i];
            break;
            case '[':
            news=news+s[i];
            break; 
            case ']':
            news=news+s[i];
            break;
        }
    }
      return news;
}

int main()
{
    //TAKING INPUT----------------------------------------
    ifstream file;
    file.open("test.txt");
    if(file.fail())
    {
        cout<<"PLEASE NAME THE FILE AS test.txt";
        return 1;
    }
    stringstream buffer;
    buffer<<file.rdbuf();
    string code=buffer.str();
    int n=code.size();
    //------------------------------------------------------
    //CODE CLEANING-----------------------------------------
    code=remove_comments(code,n);
    n=code.size();
    //------------------------------------------------------ 
     //MEMORY MANAGEMENT  
    char brainFuck[30000];
    memset(brainFuck,0,sizeof(brainFuck));
    char *ptr=brainFuck+1;
    //-------------------------------------------------------  
      
    //IMPLEMENTATION
     for(int i=0;i<n;i++)
   {    
        if (code[i] == '>') 
        {
    ptr++;
    if (ptr - brainFuck == 30001)
        ptr = brainFuck;
    } 
    else if (code[i] == '<') 
    {

        ptr--;
        if (ptr - brainFuck == -1)
            ptr = brainFuck + 30000;
    } 
    else if (code[i] == '+')
    {
        *ptr = *ptr + 1;
        if((*ptr)>=256)
        *ptr=0;
    } 
    else if (code[i] == '-') 
    {
        *ptr = *ptr - 1;
        if((*ptr)<0)
        *ptr=255;
    } 
    else if (code[i] == '.') 
    {
        cout << (*ptr);
    } 
    else if (code[i] == ',') 
    {
        cin >> (*ptr);
    } 
    else if (code[i] == '[') 
    {
      if((*ptr)==0) 
      {
        int j=0;
        i++;
        while(i<n)
        {
            if(code[i]==']'&&j==0)
             break;
            else if(code[i]=='[')
            j++;
            else if(code[i]==']')
            j--;
            i++;
        }
      } 
      
    }
    else if(code[i]==']')
    {  
        if((*ptr)!=0) 
      {
        int j=0;
        i--;
        while(i>=0)
        {
            if(code[i]=='['&&j==0)
             break;
            else if(code[i]==']')
            j++;
            else if(code[i]=='[')
            j--;
            i--;
        }
      }
      
       
    }


}
     
     
       
      

    
}
