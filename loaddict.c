/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdbool.h>
#include<cs50.h>

//#include "dictionary.h"



typedef struct node
{
    bool isword;
    struct node* next[27];
    
}node;

node* head;



/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
int main()//(const char *dictionary)
{
    //declaration
    char c,path; 
    //string word=malloc(50*sizeof(char));
    int x,i=0;
    
    //const for ppinting to the root----->head
    head=malloc(sizeof(node));
    
    printf("size of node is%lu\n",sizeof(node));
    
    //declaring a shifting pointer
    node* shift=head;
    node *prev;
    
    //read file to load dictionary in
    FILE *infile=fopen("large","r");
    
    
    //iterate till end of file is not reached, checking by return value of string by string 
    while(true)
    {
        
        //iterating for each character of a word
       while(true)
       {
           //get character
           c=fgetc(infile);
           
           if(c==-1)
       {
           printf("%i",i);
           return 1;
       }
           
           if(c=='\n')
           {
               break;
           }
           
           else if(c=='\'')
           {
               path=0;
               x=(int) path;
           }
           else
           {
               path=c-96;
               x=(int) path;
           }
           
           if(shift->next[x]==NULL)
           {
               node* new1=malloc(sizeof(node));
               
               //points the alphabet of that node(current=shift) to a new empty node
               shift->next[x]=new1;
               
               //points the node(prev) to  current node
               prev=shift;
               
               //points shift to the new empty node
               shift=new1;
           }
           else
           {
               shift=shift->next[x];
           }
           
           
       }
       i++;
       //switching from null to true because character found is '\0'
       prev->isword=true;
       
       //pointing shift back to root
       shift=head;
       
       
       
        
    }
   
    
    return 0;
    
}

