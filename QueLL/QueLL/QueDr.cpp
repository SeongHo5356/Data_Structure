// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int item;
  QueType<int> queue;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;


  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Enqueue")
      {
        inFile >> item; 
        queue.Enqueue(item);
        outFile << item << " is enqueued." << endl;
      }
      else if (command == "Dequeue")
      {
        queue.Dequeue(item); 
        outFile<< item  << " is dequeued. " << endl;
      } 
      else if (command == "IsEmpty") 
        if (queue.IsEmpty())
          outFile << "Queue is empty." << endl;
        else 
          outFile << "Queue is not empty." << endl;
             
      else if (command == "IsFull")
        if (queue.IsFull())
          outFile << "Queue is full." << endl;
        else outFile << "Queue is not full."  << endl;  
    }
    catch (FullQueue)
    {
      outFile << "FullQueue exception thrown." << endl;
    }
    
    catch (EmptyQueue)
    {
      outFile << "EmtpyQueue exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();

  // Set 'secondElement' to the second element in the Squeue, leaving the queue without its original two element

  QueType<int> Squeue;
  Squeue.Enqueue(1);
  Squeue.Enqueue(2);
  Squeue.Enqueue(3);
  Squeue.Enqueue(4);
  Squeue.Enqueue(5);

  int secondElement;
  Squeue.Dequeue(secondElement);
  Squeue.Dequeue(secondElement);

  cout << "secondElement : " << secondElement << endl;

  cout << "left elements in the Squeue" << endl;
  
  while(!Squeue.IsEmpty()) {
      Squeue.Dequeue(secondElement);

      cout << secondElement << '\t';
  }

  
  // set 'last' as equal to the rear element in the queue, leaving the queue empty
  
  QueType<int> Tqueue;
  
  for (int i = 1; i < 6; i++) {
      Tqueue.Enqueue(i);
  }

  int last;

  while (Tqueue.IsEmpty()) {
      Tqueue.Dequeue(last);
  }
  cout << "last item : " << last << endl;

  // set 'last2' equal to the rear element in the queue, leaving the queue unchanged

  QueType<int> Tqueue;
  QueType<int> temp_que;
  for (int i = 1; i < 6; i++) {
      Tqueue.Enqueue(i);
  }

  int last, temp_last;

  while (Tqueue.IsEmpty()) {
      Tqueue.Dequeue(last);
      temp_que.Enqueue(last);
  }
  cout << "last item : " << last << endl;
  while (temp_que.IsEmpty()) {
      temp_que.Dequeue(temp_last);
      Tqueue.Enqueue(temp_last);
  }

  // Make a copy of the queue, leaving the queue enchanged

  QueType<int> F_que;
  QueType<int> F_que_copy;
  QueType<int> copy;
  
  for (int i = 1; i < 6; i++) {
      F_que.Enqueue(i);
  }

  int copyItem;

  while (F_que.IsEmpty()) {
      F_que.Dequeue(copyItem);
      copy.Enqueue(copyItem);
  }
  while (copy.IsEmpty()) {
      copy.Dequeue(copyItem);
      F_que.Enqueue(copyItem);
      F_que_copy.Enqueue(copyItem);
  }



  return 0;
}


