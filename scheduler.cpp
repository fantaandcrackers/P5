#include "scheduler.h"
#include <iostream>
using namespace std;
#include "VQueue.h"

Scheduler::Scheduler(int numJobs, int numWorkers, Job *jobs, int numPeople)
{
  cout << "Running Basic Test:" << endl;
  // Display the Jobs
  for (int i = 0; i<numJobs; i++)
  {
    cout << "Job " << i << " has " << jobs[i].numDependencies << " Dependencies: ";
    for (int j = 0; j<jobs[i].numDependencies; j++)
    {
      cout << jobs[i].dependencies[j] << ' ';
    }
    cout << endl;
  }
  cout << "End Basic Test" << endl << endl;


  // Initialize Vertexex for each job
  vertexes = new Vertex[numJobs];
  for (int i = 0; i<numJobs; i++)
  {
    vertexes[i].job = &jobs[i];
    vertexes[i].inDegrees = 0;
    vertexes[i].jobID = i;
  }

  // Set inDegrees for each Vertex
  for (int i = 0; i<numJobs; i++)
  {
    for (int j = 0; j<jobs[i].numDependencies; j++)
    {
      int dependNum = jobs[i].dependencies[j];
      vertexes[dependNum].inDegrees++;
    }
  }

  // Test to make sure vertexes are good
  cout << "Running Test 2:" << endl;
  for (int i=0; i<numJobs; i++)
  {
    cout << "Job " << i << " has " << vertexes[i].inDegrees << " inDegrees" << endl;
  }
  cout << "End Test 2" << endl << endl;

  nJobs = numJobs;
} // Scheduler()

<<<<<<< HEAD
void findCriticalPath(VQueue tpList)
{
  Job criticalPath[tpList.getSize()];
  Vertex V1;  
  int tracker; //keeping count of the finish time

  tracker = V1.job->startTime;
  tpList.dequeue();

  x = 0; // for counting critical path array

  for (int i=0; i < tpList.getSize(); i++)
  {
    if (!tpList.isEmpty())
    {
      V1 = tpList.getFront();

      if ((tracker - V1.job->length) == V1.job->startTime) { //no slack
        criticalPath[x] = V1.jobID;
        x++;
      }

      tpList.dequeue();
    }
  }
}

=======
>>>>>>> origin/master
void Scheduler::run()
{

  // Run Topological Sort
  //    First, Enqueue all Vertexes with inDegrees == 0
  //    Then for item in queue:
  //      For each Dependency
  //        Decriment inDegrees
  //        If dependency has inDegrees == 0
  //          enqueue dependency
  //      Dequeue item
  //      
  VQueue queue(nJobs);
  cout << "Running Topological Sort" << endl;

  for (int i = 0; i<nJobs; i++)
  {
    // Enqueue All Vertexes that have zero inDegrees
    if (vertexes[i].inDegrees == 0)
    { 
      queue.enqueue(vertexes[i]);
      cout << "Enqueued vertex " << i << endl;
    }
  }

  while ( !queue.isEmpty() )
  { 
    Vertex v = queue.getFront();
    Job *j = v.job;
    for (int i=0; i<j->numDependencies; i++)
    {
      int jNum = j->dependencies[i];
      vertexes[jNum].inDegrees--;
      if (vertexes[jNum].inDegrees == 0)
      {
        queue.enqueue(vertexes[jNum]);
	cout << "Enqueued vertex " << jNum << endl;
      }
    }
    queue.dequeue();
    
  }

  cout << endl << endl;
} // run()


