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
  int jobID;
  int shortest;
  int longest;
  int slack;
  int behindID; // This holds the Job for the shortest path
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
