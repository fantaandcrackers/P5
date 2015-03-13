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

void findCriticalPath(VQueue tpList)
{
  Jobs criticalPath[100000];
  Vertex V1, V2;  
  for (int i=0; i < tpList.length; i++)
  {
    V1 = tpList.getFront();
    tpList.dequeue();
    V2 = 
  }
}

void Scheduler::run()
{
  VQueue queue(nJobs);
  queue.enqueue(vertexes[1]);
  Vertex v = queue.getFront();
  cout << "Vertex: " << v.inDegrees << endl;


  cout << endl << endl;
} // run()


