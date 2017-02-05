//CS433 Assignment 1
//Carlos Ferrer, Brandon Herbert
//
//
//Purpose
//Create a priority queue

#ifndef Queue_CPP
#define Queue_CPP


#include "Queue.h"


int numberOfProc = 0;

int Queue::size()
{
	return numberOfProc;
}

void Queue::insertProc(pcb* newProc)
{
	if(numberOfProc == 20)
	{
		cout << "Queue Full!" << endl;
	}
	
	else
	{
		//insert it into our data structure
		pcblist[numberOfProc] = newProc;
		pcblist -> state = "ready";
		numberofProc++;
		
		heapify(0);
		
		
	}
	
	return;
	
}

pcb* Queue::removeProc()
{
	if (numberOfProc == 0)
	{
		cout << "Queue Empty!" << endl;
	}
	
	else
	{
		pcb* highest = pcblist[0];

		pcblist[0] = numberOfProc-1;
		
		heapify(0);
		
		numberOfProc--;
		return highest;
	}
	

}

void Queue::display()
{
	
}


void Queue::heapify(int parent)
{
	int left = (2 * parent) + 1;
	int right = (2 * parent) + 2;
	

	//test left side
	if(pcblist[left]->priority > pcblist[parent]->priority) 
	{
		pcb* swap = pcblist[parent];
		pcblist[parent] = pcblist[left];
		pcblist[left] = swap;

	}

	heapify(left);

	//test right side
	
	if( pcblist[right]->priority > pcblist[parent]->priority)
	{
		pcb* swap = pcblist[parent];
		pcblist[parent] = pcblist[right];
		pcblist[right] = swap;

	}
	
	heapify(right);
	
	return;
	
	
}

void Queue::addHeapify(int parent,pcb* proc)
{
	pcb* temp = proc;
	int left = (2 * parent) + 1;
	int right = (2 * parent) + 2;
	
	if(temp->priority > pcblist[parent])
	{
		pcb* swap = pcblist[parent];
		pcblist[parent]=temp;
		temp=swap;
	}
	
		
	if(temp->priority > pcblist[left])
	{
		pcb* swap = pcblist[left];
		pcblist[left]=temp;
		temp=swap;
	}
	
		
	if(temp->priority > pcblist[right])
	{
		pcb* swap = pcblist[right];
		pcblist[right]=temp;
		temp=swap;
	}
	
	addHeapify(left,pcb* temp);
	addHeapify(right,pcb* temp);
}


