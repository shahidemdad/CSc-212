/*
Editor: MdShahid Bin Emdad
File: sequence3.cpp
Professor: George Wolberg
*/

#include <assert.h>
#include "node1.h"
#include "sequence3.h"

namespace main_savitch_5 {
    /* CLASS INVARIANT
        1. The items in the bag are stored in a linked list
        2. The head pointer of the list is stored in the member variable head_ptr
        3. The total number of items in the list is stored in the member variable m_nodeCount */

//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
    sequence::sequence( ) {
      // O(1) - constant time
        head_ptr = NULL;
        tail_ptr = NULL;
        currentItem_ptr = NULL;
        prevItem_ptr = NULL;
        m_nodeCount = 0;
    }

    sequence::sequence(const sequence& source) {
      // O(N) - linear time, copies nodes one at a time
        list_copy(source.getHead(), head_ptr, tail_ptr);
        list_copy(source.getCur(), currentItem_ptr, prevItem_ptr);
        m_nodeCount = source.size();
	  }

    sequence::~sequence( ) {
      // O(1) - constant time
        list_clear(head_ptr);
    }

//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).

    void sequence::start( ) {
      // O(1) - constant time
        currentItem_ptr = getHead();
        prevItem_ptr = NULL;
    }

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.

    void sequence::advance( ) {
      // O(1) - constant time
        assert(is_item());
        prevItem_ptr = getCur();
        currentItem_ptr = currentItem_ptr->link();
    }

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

    void sequence::insert(const value_type& entry) {
      // O(1) - constant time
        if(is_item()) {
            if((prevItem_ptr == NULL)) {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } else {
                list_insert(prevItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } if(!is_item()) {
            list_head_insert(head_ptr, entry);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } m_nodeCount++;
    }

//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

    void sequence::attach(const value_type& entry) {
      // O(1) -  constant time
        if(is_item()) {
            prevItem_ptr = getCur();
            list_insert(currentItem_ptr, entry);
            currentItem_ptr = currentItem_ptr->link();
        } if(!is_item()) {
            if((prevItem_ptr == NULL)) {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } else {
                currentItem_ptr = list_locate(head_ptr, list_length(head_ptr));
                list_insert(currentItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } m_nodeCount++;
    }

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.

    void sequence::remove_current( ) {
      // O(1) - constant time
        assert(is_item());
        if(currentItem_ptr == getHead()) {
            list_head_remove(head_ptr);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } else {
            currentItem_ptr = currentItem_ptr->link();
            list_remove(getPrev());
        } m_nodeCount--;
    }

// void operator=(const sequence& source);
//   Postcondition: The bag that activated this function has the same items
//   and capacity as source.

    void sequence::operator = (const sequence& source) {
      // O(N) - linear time
        if(this == &source) return;
        else {
            list_clear(head_ptr);
            list_copy(source.getHead(), head_ptr, tail_ptr);
            if(source.getPrev() == NULL) {
                if(source.getCur() == NULL) {
                    currentItem_ptr = NULL;
                    prevItem_ptr = NULL;
                } else {
                    currentItem_ptr = getHead();
                    prevItem_ptr = NULL;
                }
            } else {
                node *tmp_ptr = getHead();
                node *source_ptr = source.getHead();
                while(source_ptr != source.getPrev()) {
                    source_ptr = source_ptr->link();
                    tmp_ptr = tmp_ptr->link();
                }
                currentItem_ptr = tmp_ptr->link();
                prevItem_ptr = tmp_ptr;
            } m_nodeCount = source.size();
        }
    }

//   size_t size( ) const
//     Postcondition: The return value is the number of items on the sequence.

    sequence::size_type sequence::size( ) const {
      // O(1) - constant time
        return m_nodeCount;
    }

//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.

    bool sequence::is_item( ) const {
      // O(1)  - constant time
        return ((getCur() != NULL) && (size() > 0));
    }

//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.

    sequence::value_type sequence::current( ) const {
      // O(1)  - constant time
        assert(is_item());
        return currentItem_ptr->data();
    }

// node* getHead( ) const;
//   Postcondition: head pointer is returned

    node* sequence::getHead( ) const {
      // O(1)  - constant time
      return head_ptr;
    }

// node* getTail( ) const;
//   Postcondition: tail pointer is returned

    node* sequence::getTail( ) const {
      // O(1)  - constant time
      return tail_ptr;
    }

// node* getCur( ) const;
//   Postcondition: current item pointer is returned

    node* sequence::getCur( ) const {
      // O(1)  - constant time
      return currentItem_ptr;
    }

// node* getPrev( ) const;
//   Postcondition: previous item pointer is returned

    node* sequence::getPrev( ) const {
      // O(1)  - constant time
      return prevItem_ptr;
    }
}
