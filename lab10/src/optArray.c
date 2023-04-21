/**
 * This implements the LRU page-replacement algorithm.
 */

#include "../inc/optArray.h"
#include <stdio.h>
#include <stdlib.h>

int *referenceString;
int refStringLength;

// the page frame list
int *pageTable;
int numOfFramesPerProcess = 0;

int victimIndex;
int hitPageNumber;

// statistics
int numOfFaults;

// this index is used to go through the sequence of pages references
int currentPgeReferenceIndex = 0;

int testOPT(int numOfFrames, int *refString, int refStrLen)
{
    numOfFramesPerProcess = numOfFrames;
    referenceString = refString;
    refStringLength = refStrLen;
    
    // setup page table

    pageTable = calloc(numOfFramesPerProcess, sizeof(int));
    for (int i = 0; i < numOfFramesPerProcess; i++)
        pageTable[i] = -1;
    
    for (int i = 0; i < refStrLen; i++) {
        hitPageNumber = -1;
        victimIndex = -1;
        currentPgeReferenceIndex = i;
        insertOPT(refString[i]);
        printf("%d -> ", refString[i]);
        displayOPT();
    }
    
    freePageTableOPT();
    return numOfFaults;
}

/*
 *	try to insert a page into the page table
 */
void insertOPT(int pageNumber)
{
    int searchVal = searchOPT(pageNumber);

    pageTable[searchVal] = pageNumber;
}

/*
 *  find either an empty slot, or the page, or a vitim to evict
 */
int searchOPT(int pageNumber)
{
    for (int i = 0; i < numOfFramesPerProcess; i++) {
        if(pageTable[i] == -1) {
            victimIndex = i;
            numOfFaults++;
            return i;
        } else if(pageTable[i] == pageNumber){
            hitPageNumber = i;
            return i;            
        }
    }

    return findVictimPageOPT();
}

int findVictimPageOPT()
{   
    numOfFaults++;
    int farthest = 0;
    int ret = 0;
    // loop through our page table
    for (int i = 0; i < numOfFramesPerProcess; i++) {
        // loop through our reference string
        for(int j = currentPgeReferenceIndex; j < refStringLength; j++) { 
            if(pageTable[i] == referenceString[j]) {
                if(j > farthest) {
                    farthest = j;
                    ret = i;
                }
                break;
            }
        if (j == refStringLength - 1) {
            victimIndex = i;
            return i;
        }
        }
    }
    victimIndex = ret;
    return ret;
}

void displayOPT()
{
    
    for (int i = 0; i < numOfFramesPerProcess; i++) {
        if(victimIndex != -1 && i == victimIndex) {
            printf("  %d*  ", pageTable[i]);
        } else if(hitPageNumber != -1 && i == hitPageNumber) {
            printf("  %d<  ", pageTable[i]);
        } else {
            printf("  %d  ", pageTable[i]);
        }
    }
        

    printf("\n");
}

void freePageTableOPT()
{
    free(pageTable);
}
