#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void addElement(arrayList * array, void * element)
{
  // get whether or not we need to resize the array
  if(array->numElements == array->arraySize)
  {
    // if so, make a new array that's double the size of the old one,
    // copy all of the elements over, and delete the old array
    int newSize = array->arraySize * 2;
    void* newArray = (void*)malloc(newSize * array->elementSize);
    // copy everything over
    memcpy(newArray, array->array, array->arraySize * array->elementSize);
    // free the new array
    free(array->array);
    // copy it over
    array->array = newArray;
    // set the new size
    array->arraySize = newSize;
    // voila
  }

  // insert the element at the last position
  switch(array->type)
  {
    case charType:
    {
      char* a = (char*)array->array;
      char* elementPtr = (char*)element;
      a[array->numElements] = *elementPtr;
      break;
    }
    case shortType:
    {
      short* a = (short*)array->array;
      short* elementPtr = (short*)element;
      a[array->numElements] = *elementPtr;
      break;
    }
    case intType:
    {
      int* a = (int*)array->array;
      int* elementPtr = (int*)element;
      a[array->numElements] = *elementPtr;
      break;
    }
  }
  // increment the number of elements
  array->numElements++;
}

void removeElement(arrayList * array, int index)
{
  // shift everything over towards index 0
  int i; // C99 you mysterious mistress
  for(i = index; i < array->numElements - 1; i++)
  {
    // Shift everything over one
    switch(array->type)
    {
      // brackets are necessary because C is great and has confusing scopes with switch-case
      case charType:
      {
        char* a = (char*)array->array;
        a[i] = a[i + 1];
        break;
      }
      case shortType:
      {
        short* a = (short*)array->array;
        a[i] = a[i + 1];
        break;
      }
      case intType:
      {
        int* a = (int*)array->array;
        a[i] = a[i + 1];
        break;
      }
    }
  }
  // decrement number of elements
  array->numElements--;
}

void printArray(arrayList * arylstP)
{
  int i;
  printf("array size: %d, num elements: %d contents: ", arylstP->arraySize, arylstP->numElements);
  for (i = 0; i < arylstP->numElements; i++)
  {
    if (arylstP->type == charType)
    {
      char* a = (char*)arylstP->array;
      printf("%02x ", a[i] & 0xff);
    }
    else if (arylstP->type == shortType)
    {
      short* a = (short*)arylstP->array;
      printf("%04x ", a[i] & 0xffff);
    }
    else if (arylstP->type == intType)
    {
      int* a = (int*)arylstP->array;
      printf("%08x ", a[i] & 0xffffffff);
    }
  }
  printf("\n");
}

