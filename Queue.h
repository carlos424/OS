//CS433 Assignment 1
//Carlos Ferrer, Brandon Herbert
//
//
//Purpose
//Create a priority queue

#ifndef Queue_H
#define Queue_H


#include <iostream>
#include <string>
#include "pcb.h"

using namespace std;

class Queue
{
	private:
		int numberOfProc;
		pcb* pcblist[20];
	
	public:
		int size();
		void insertProc(pcb* newProc);
		pcb* removeProc();
		void display();
		void heapify(int parent);
		void addHeapify(int parent,pcb* proc);
		
	
};

#endif