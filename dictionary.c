/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdbool.h>
#include<cs50.h>
#include <ctype.h>


#include "dictionary.h"



typedef struct node
{
    bool isword;
    struct node* next[27];
    
}node;

node* head;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node* shift=head,*prev;
    int i=0,x,c;
    while(word[i]!='\0')
    {
        c=tolower(word[i]);
        
        x=c-96;
        
        if(shift->next[x]==NULL)
        {
            return false;
        }
        
        //assign shift to prev
        prev=shift;
        
        //assign adress of a new (latest)node to shift
        shift=shift->next[x];
        
        i++;
    }
    
    if(prev->isword==true)
    {
        return true;
    }
    
    
    
    
    return false;
}







/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //declaration
    char c,path; 
    //string word=malloc(50*sizeof(char));
    int x;
    
    //const for ppinting to the root----->head
    head=malloc(sizeof(node));
    
    //declaring a shifting pointer
    node* shift=head;
    node *prev;
    
    //read file to load dictionary in
    FILE *infile=fopen(dictionary,"r");
    
    
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
               return true;
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
       //switching from null to true because character found is '\0'
       prev->isword=true;
       
       //pointing shift back to root
       shift=head;
       
        
    }
    
    
    return false;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void)
{
    // TODO
    return 0;
}




void cut(node *shift);
/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    //node* shift=head;
    cut(head);
    //free(head);
    return true;
}


void cut(node *shift)
{
    for(int i=0;i<27;i++)
    {
        if(shift->next[i]!=NULL)
        {
            return cut(shift->next[i]);
        }
    }
    
    free(shift);
}