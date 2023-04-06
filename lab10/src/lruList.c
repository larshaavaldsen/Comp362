/**
 * This implements the LRU page-replacement algorithm.
 */
/*

TAKE CARE OF THE BOTTOM

*/
#include "../inc/lruList.h"
#include <stdio.h>
#include <stdlib.h>

int *referenceString;
int refStringLength;

FRAME *pageTableTop;
FRAME *leastRecentlyUsed;
int pageTableSize = 0;

int numberOfFramesPerProcess = 0;

// statistics
int nummberOfFaults = 0;

int hitPageNumber;

/*
 * insert pages from a reference string into a page table and measure
 * the page fault rate
 */
int testLRU(int numOfFrames, int *refString, int refStrLen)
{
    numberOfFramesPerProcess = numOfFrames;
    
    for (int i = 0; i < refStrLen; i++) {
        insertLRU(refString[i]);
        displayLRU();
    }
    return 0;
}

/*
 *	try to insert a page into the page table
 */
void insertLRU(int pageNumber)
{
    FRAME *search = searchLRU(pageNumber);

    if (search == NULL) {
        FRAME *newFrame = malloc(sizeof(FRAME));
        newFrame->pageNumber = pageNumber;
        if (pageTableSize < numberOfFramesPerProcess) {
            if (pageTableTop == NULL) {
                newFrame->down = NULL;
                newFrame->up = NULL;
                pageTableTop = newFrame;
                pageTableSize++;
            } else {
                pageTableTop->up = newFrame;
                newFrame->down = pageTableTop;
                newFrame->up = NULL;
                pageTableTop = newFrame;
                pageTableSize++;
            } 
        } else {
            FRAME *last = pageTableTop;
            while(last->down != NULL) {
                last = last->down;
            }
            last->up->down = NULL;
            free(last);

            newFrame->down = NULL;
            newFrame->up = NULL;
            pageTableTop = newFrame;
    } 
} else { // we got a hit
    search->up->down = search->down;
    search->down->up = search->up;

    search->up = NULL;
    pageTableTop->up = search;
    search->down = pageTableTop;
}
}

/**
 * Searches for page pageNumber in the page frame list
 * returns NULL if a frame with pageNumber was not found
 * otherwise, returns a reference to the frame with pageNumber
 */
FRAME *searchLRU(int pageNumber)
{
    FRAME *next = pageTableTop;
    while(next->down != NULL) {
        if(pageNumber == next->pageNumber)
            return next;
        next = next->down;
    }
    return NULL;
}

void displayLRU()
{
    for (FRAME *curr = pageTableTop; curr != NULL; curr = curr->down) {
        printf("\t%d\t", curr->pageNumber);
    }
    printf("\n");
}

void freePageTableLRU()
{
    // TODO: implement
}

