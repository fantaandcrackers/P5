#ifndef _VQUEUE_H
#define _VQUEUE_H
#include "ProjectRunner.h"
#include "scheduler.h"

/*
  Queue for Vertexes Pointers
  Storage:
    -No actual Vertexes are stored in this queue
    -enqueue input: Pointers to Vertexes
    -GetFront output: Pointer to Vertex at front of queue
    -Dequeue Gets rid of front  
*/


class VQueue
{
  public:
  VQueue( int theSize ): maxSize(theSize), mySize( 0 ), front( 0 ), back(0)
    { VArray = new Vertex[theSize]; }
  Vertex *VArray;
  int maxSize;
  int mySize;
  int front;
  int back;

  int getSize()
  {
    return mySize;
  }

  void enqueue(Vertex a)
  {
    VArray[back] = a;
    back = inc(back);
    mySize++;
  }

  Vertex getFront()
  {
    return VArray[front];
  }

  void dequeue()
  {
    front = inc(front);
    mySize--;
  }
 
  int inc( int n )
  {
    if (n < maxSize-1)
    {
      return n+1;
    }
    else return 0;
  }

};
//#include "VQueue.cpp"
#endif
