#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
  // dynamically allocate a new array list becauase hey
  // we can
  arrayList* array = (arrayList*)malloc(sizeof(arrayList));
  
  // set the array sizes
  array->numElements = 0;
  array->arraySize = 4;
  array->type = type;
  // set the element size based on the type
  array->elementSize = getSize(type);
  // allocate space for the array
  array->array = (void*)malloc(array->elementSize * array->arraySize);
  return array;
}

int getSize(primitiveType type)
{
  switch(type)
  {
    case charType: return sizeof(char);
    case shortType: return sizeof(short);
    case intType: return sizeof(int);
  }
  // something went horribly, horribly wrong
  return -1;
}

void addElement(arrayList * arylstP, void * element)
{
  return;
}

void removeElement(arrayList * arylstP, int index)
{
  return;
}

void printArray(arrayList * arylstP)
{
  int i;
  printf("array size: %d, num elements: %d contents: ", arylstP->arraySize, arylstP->numElements);
  for (i = 0; i < arylstP->numElements; i++)
  {
    if (arylstP->type == charType)
      //fill in the missing code that gets the element and &s it with 0xff
      printf("%02x ", 0xff);
    else if (arylstP->type == shortType)
      //fill in the missing code that gets the element and &s it with 0xffff
      printf("%04x ", 0xffff);
    else if (arylstP->type == intType)
      //fill in the missing code that gets the element and &s it with 0xffffffff
      printf("%08x ", 0xffffffff);
  }
  printf("\n");
}

