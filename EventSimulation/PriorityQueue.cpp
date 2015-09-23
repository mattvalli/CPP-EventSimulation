//
//  PriorityQueue.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//
#include <vector>
#include "Comparable.h"

using namespace std;



// METHOD SIGNATURES
void insert(Comparable&);
long size();


class PriorityQueue {
private:
    // DEBUGGING
    const bool DEBUG_REMOVE = false;
    const bool DEBUG_COMPARE = false;
    // CONSTANTS
    const int INITIAL_SIZE = 0;
    const int TOP = 1;
    // MEMBERS
    int mSize;
    vector<Comparable*> *mElements;
    
    // CONVENIENCE METHODS
    bool compare(int x, int y) {
        Comparable *c = mElements->at(x);
        Comparable *p = mElements->at(y);
        
        bool result = false;
        // Determine whether to exchange of not
        switch (c->compareTo(*p)) {
            case Comparable::LESS_THAN:
                result = true;
                break;
            case Comparable::EQUAL:
            case Comparable::GREATER_THAN:
                result = false;
                break;
        }
        return result;
    }
    void exch(int i, int j) {
        Comparable *swap = mElements->at(i);
        mElements->at(i) = mElements->at(j);
        mElements->at(j) = swap;
    }
    
    void swim(int k) {
        // Move object at K up until Parent of K is larger
        while (k > 1 && compare(k, k/2)) {
            // Swap parent and child
            exch(k, k/2);
            k = k/2;
        }
    }
    
    void sink(int parent) {
        int vSize = (int) size();
        // Double k (next level down) and check to see if it is within range
        while((parent * 2) < vSize) {
            // The LEFT CHILD
            int child = parent * 2;
            // If the leftChild is within range, compare it with the RIGHT CHILD, if true, use RIGHT CHILD
            if (child < vSize && !compare(child, child+1)) {
                child++;
                if (DEBUG_COMPARE) cout << "Potential Swap - RIGHT CHILD: " << mElements->at(child)->toString() << endl;
            } else {
                if (DEBUG_COMPARE) cout << "Potential Swap - LEFT CHILD" << endl;
            }
            if (compare(parent, child)) break;
            
            exch(parent, child);
            parent = child;
        }
    }
    
    
public:
    // CONSTRUCTORS
    PriorityQueue() {
        // Initialize the size of the PQ to 0
        mSize = INITIAL_SIZE;
        
        // Initialize a vector of type T
        mElements = new vector<Comparable*>();
        
        // Add ONE Comparable Element to shift Queue by 1
        mElements->push_back(nullptr);
    }
    // DESTRUCTORS
    ~PriorityQueue();
    
    // QUEUE INTERFACE IMPLEMENTATION
    bool empty() {
        if (mElements->size() > 1) return false;
        else return true;
    }
    long size() {
        return mSize;
    }
    
    // Adds an item to the queue
    void insert(Comparable& item) {
        // Add the item to the vector of items
        mElements->push_back(&item);
        swim((int) size());
        mSize++;
    }
    
    // Returns/Removes the current item with the highest priority from the queue
    Comparable* remove() {
        int pqSize = (int) size();
        if (DEBUG_REMOVE) {
            cout << "START - REMOVE LOG" << endl;
            cout << "BEFORE EXCHANGE" << "\n";
            cout << "Top: " << mElements->at(TOP)->toString() << endl;
            cout << "Back: " << mElements->at(pqSize)->toString() << endl << endl;
        }
        // Exchange TOP element with BACK element and Sink NEW TOP
        exch(TOP, pqSize);
        if (DEBUG_REMOVE) {
            cout << "AFTER EXCHANGE/BEFORE SINK" << "\n";
            cout << "Top: " << mElements->at(TOP)->toString() << endl;
            cout << "Back: " << mElements->at(pqSize)->toString() << endl << endl;
        }
        sink(TOP);
        if (DEBUG_REMOVE) {
            cout << "AFTER SINK" << "\n";
            cout << "Top: " << mElements->at(TOP)->toString() << endl;
            cout << "Back: " << mElements->at(pqSize)->toString() << endl << endl;
            cout << "END - REMOVE LOG" << endl;
        }
        
        // Get the BACK element (FORMER TOP)
        Comparable *priorityElement = mElements->back();
        // Remove the BACK element
        mElements->pop_back();
        mSize--;
        
        return priorityElement;
    }
    
    Comparable peek();           // Preview the next item without removal
    void clear();       // Removes all items from the queue
    
    
    string toString() {
            string s = "PRIORITY QUEUE - Vector Order - Size: " +to_string(size()) + "\n";
            for (int i = 1; i < mElements->size(); i++) {
                s += "mElements[" + to_string(i) + "]: " + mElements->at(i)->toString() + "\n";
            }
        s += "END PRIORITY QUEUE\n";
        return s;
    }
    
};