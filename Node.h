

struct Node {                                      
  int ID,Score; // each listNode contains a character 
  struct Node *nextPtr;
  struct Node *pPtr; // pointer to next node
}; // end structure listNode                        

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode* LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr *sPtr, int value );
//int deletes( LLnode **sPtr, int value );

int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value1, int value2 );
//int insert( LLnode **sPtr, int value );

void printList( LLPtr currentPtr );
void printReverse( LLPtr currentPtr );

void instructions( void );


// display program instructions to user
void instructions( void )
{ 
  puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
      
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr *sPtr, int value1, int value2 )
{ 
  LLPtr newPtr; // pointer to new node
  LLPtr previousPtr; // pointer to previous node in list
  LLPtr currentPtr; // pointer to current node in list

  newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

  if ( newPtr != NULL ){ // is space available
    newPtr->ID = value1; // place value in node
    newPtr->Score = value2;
    newPtr->nextPtr = NULL; // node does not link to another node
    newPtr->pPtr = NULL;

    previousPtr = NULL;
    currentPtr = *sPtr;

    // loop to find the correct location in the list       
    while ( currentPtr != NULL && value1 > currentPtr->ID ) {
      previousPtr = currentPtr; // walk to ...               
      currentPtr = currentPtr->nextPtr; // ... next node 
    } // end while                                         

    // insert new node at beginning of list
    if ( previousPtr == NULL ) { 
        
      newPtr->nextPtr = *sPtr;
      if(*sPtr) (*sPtr)->pPtr=newPtr;

      *sPtr = newPtr;

    } // end if
    else { // insert new node between previousPtr and currentPtr
      previousPtr->nextPtr = newPtr;
      newPtr->pPtr=previousPtr;

      newPtr->nextPtr = currentPtr;
      if (currentPtr) currentPtr->pPtr=newPtr;

    } // end else
  } // end if
  else {
    printf("%d not inserted. No memory available.\n", value1);
  } // end else
} // end function insert

// delete a list element
int deletes( LLPtr *sPtr, int value )
{ 
  LLPtr previousPtr; // pointer to previous node in list
  LLPtr currentPtr; // pointer to current node in list
  LLPtr tempPtr; // temporary node pointer

  // delete first node
  if ( value == ( *sPtr )->ID ) { 
    tempPtr = *sPtr; // hold onto node being removed
    *sPtr = ( *sPtr )->nextPtr; // de-thread the node
    free( tempPtr ); // free the de-threaded node
    return value;
  } // end if
  else { 
    previousPtr = *sPtr;
    currentPtr = ( *sPtr )->nextPtr;

    // loop to find the correct location in the list
    while ( currentPtr != NULL && currentPtr->ID != value ) { 
      previousPtr = currentPtr; // walk to ...  
      currentPtr = currentPtr->nextPtr; // ... next node  
    } // end while

    // delete node at currentPtr
    if ( currentPtr != NULL ) { 
      tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      if(currentPtr->nextPtr) currentPtr->nextPtr->pPtr = previousPtr;
      free( tempPtr );
      return value;
    } // end if
  } // end else

  return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{ 
  return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{ 
  // if list is empty
  if ( isEmpty( currentPtr ) ) {
    puts( "List is empty.\n" );
  } // end if
  else { 
    puts( "The list is:" );

    // while not the end of the list
    while ( currentPtr != NULL ) { 
      printf( "ID: %d Score: %d --> ", currentPtr->ID, currentPtr->Score );
      currentPtr = currentPtr->nextPtr;   
    } // end while

    puts( "NULL\n" );
  } // end else
} // end function printList

void printReverse( LLPtr currentPtr ){
  LLPtr tempPtr,head;
  if ( !isEmpty( currentPtr ) ) {
    head = currentPtr->pPtr;
    while (currentPtr != NULL) {
    tempPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
    }
    while (tempPtr != NULL && tempPtr != head){
      printf( "ID: %d Score: %d --> ", tempPtr->ID, tempPtr->Score );
      tempPtr = tempPtr->pPtr;
    }
    printf(" NULL\n");
  }
}
