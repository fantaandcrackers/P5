#ifndef schedulerH
#define schedulerH
#include "ProjectRunner.h"

// Vertex:
// 	Pointer to job
// 	number of inDegrees
// We have an array of Vertexes, one Vertex for each Job.
// 
typedef struct
{
  //List <int> outEdges;
  Job *job;
  int inDegrees; 
} Vertex;

#include "VQueue.h"

class Scheduler
{
public:
  Scheduler(int numJobs, int numWorkers, Job *jobs, int numPeople);
  void run();
  int nJobs;
  Vertex *vertexes;

}; // class Scheduler


#endif
