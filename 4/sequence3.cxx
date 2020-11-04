//Name: Catherine Matta
/* Invariants:
head_ptr, this is a pointer to our head of the linked list
tail_ptr, this is a pointer to our tail of the linked list
cursor, which node we are currently looking at
pre_cursor, is a pointer to one node "before" the cursor
node_count, how many nodes we have
Functions used from node1.h:
list_clear
list_copy
link()
list_insert
list_remove
list_remove_head
list_head_insert*/


#include "sequence3.h"
#include <cassert>

namespace main_savitch_5
{
	sequence::sequence() //default consturctor
	{
		head_ptr=NULL;
		tail_ptr=NULL;
		cursor=NULL;
		pre_cursor=NULL;
		node_count=0;
		//post condition: empty sequnce
		//Big O: O(1)

	}
	sequence::sequence(const sequence& source) // we have a preexisting
	{
		list_copy(source.head_ptr,head_ptr,tail_ptr); //from node1
		node_count=source.node_count;
		start();
		node* temp_ptr; //create a temporary traversal pointer
		for(temp_ptr=source.head_ptr;temp_ptr!=NULL;temp_ptr=temp_ptr->link())
		{
			if(temp_ptr==source.cursor)
				return;
			pre_cursor=cursor;
			cursor=cursor->link();
		}
		//Big O:O(n)
	}
    sequence::~sequence( ) // desturctor 
    {
    	list_clear(head_ptr);
    	//Big O: O(n) as list clear goes through a lopp
    }
// MODIFICATION MEMBER FUNCTIONS
    void sequence::start( )
    {
    	cursor=head_ptr; //cursor points to start/head of list
    	pre_cursor=NULL; // precursor is null bc there's nothing yet
    	//Big O: O(1)
    }
    void sequence::advance( )
    {
    	//pre: is_item returns true
    	assert(is_item());
    	pre_cursor=cursor; // make the precursor point to what we are currently pointing to
    	cursor=cursor->link(); // the advance part
    	//Post: our precursor is the same as the cursor, and cursor moves forward
    	//Big O: O(1)

    }
    void sequence::insert(const value_type& entry)
    {
    	if(is_item() &&pre_cursor!=NULL) // cursor is pointing at somethin
    	{
    		list_insert(pre_cursor,entry);
    		cursor=pre_cursor->link();
    	}
    	else // cursor points to head ptr
    	{
    		list_head_insert(head_ptr,entry);
    		start();
    	}
    	node_count++;
    	//Big O:O(1)
    }
    void sequence::attach(const value_type& entry)
    {
    	if(is_item()) //something is there
    	{
    		list_insert(cursor,entry);
    		pre_cursor=cursor;
    		cursor=cursor->link();
    	}
    	else // cursor @ null
    	{
    		if(pre_cursor==NULL)// cursor is @ head
    		{ 
    			list_head_insert(head_ptr,entry);
    			start(); // start, cursor=headptr, precursor=null	
    		}
    		else
    		{
    			list_insert(pre_cursor,entry);
    			cursor=pre_cursor->link();

    		}
    	}
    	node_count++;
    	//Big O:O(1)
    }
    void sequence::remove_current( )
    {
    	assert(is_item());
    	if(cursor==head_ptr)
    	{
    		list_head_remove(head_ptr);
    		start();
    	}
    	else
    	{
    		cursor=cursor->link();
    		list_remove(pre_cursor);
    	}
    	node_count--;
    	//Big O: O(1)
    }
    void sequence::operator =(const sequence& source)
    {
    	if(this==&source) // self-check
    		return;
    	else
    	{
    		list_clear(head_ptr); // clears original list
    		list_copy(source.head_ptr,head_ptr,tail_ptr);
    		node_count=source.node_count;
    		cursor=head_ptr;
    		pre_cursor=NULL;
    		node* traverse= source.head_ptr;
    		while(traverse!=NULL &&traverse!=source.cursor) // copying
    		{
    			pre_cursor=cursor; // move the precursor
    			cursor=cursor->link(); // move the cursor
                traverse=traverse->link(); // like traverse ++

    		}
    	}
    	//Big O: O(n)
    }
}