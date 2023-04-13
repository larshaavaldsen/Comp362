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

FRAME *pageTableTop = NULL;
FRAME *leastRecentlyUsed;
int pageTableSize = 0;

int numberOfFramesPerProcess = 0;

// statistics
int nummberOfFaults = 0;

int hitPageNumber = 0;

/*
Function to update least used frame
*/
void updateLeast(void) {
    FRAME *next = pageTableTop;
    while(next->down != NULL) {
        next = next->down;
    leastRecentlyUsed = next;
}
}
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
                updateLeast();
            } else {
                pageTableTop->up = newFrame;
                newFrame->down = pageTableTop;
                newFrame->up = NULL;
                pageTableTop = newFrame;
                pageTableSize++;
                updateLeast();
            } 
        } else {
            leastRecentlyUsed->up->down = NULL;
            free(leastRecentlyUsed);
            newFrame->down = pageTableTop;
            newFrame->up = NULL;
            pageTableTop->up = newFrame;
            pageTableTop = newFrame;
            updateLeast();
    } 
} else { // we got a hit
    // fix this this is where its broken
    // 3 cases top, bottom change where bottom is pointing to
    // anywhere else
    hitPageNumber = search->pageNumber;
    if (search->pageNumber == pageTableTop->pageNumber) {
        return;
    } else if (search->pageNumber == leastRecentlyUsed->pageNumber) {
        search->up->down = NULL;
        search->up = NULL;
        pageTableTop->up = search;
        search->down = pageTableTop;
        pageTableTop = search;
        updateLeast();
    } else {
        search->up->down = search->down;
        search->down->up = search->up;

        search->up = NULL;
        pageTableTop->up = search;
        search->down = pageTableTop;
        pageTableTop = search;
        updateLeast();
    }
}
}


/**
 * Searches for page pageNumber in the page frame list
 * returns NULL if a frame with pageNumber was not found
 * otherwise, returns a reference to the frame with pageNumber
 */
FRAME *searchLRU(int pageNumber)
{
    FRAME *ret = NULL;
    if (pageTableTop != NULL) {
        for (FRAME *curr = pageTableTop; curr->down != NULL; curr = curr->down) {
            if (curr->pageNumber == pageNumber) {
                ret = curr;
            }
        }
    }
    return  ret;
}

void displayLRU(void)
{
    for (FRAME *curr = pageTableTop; curr != NULL; curr = curr->down) {
        if(hitPageNumber == curr->pageNumber) {
            printf(" %d> ", curr->pageNumber);
        } else if (curr->pageNumber == leastRecentlyUsed->pageNumber) {
            printf(" %d* ", curr->pageNumber);
        } else {
            printf(" %d ", curr->pageNumber);
        }
    }
    printf("\n");
}

void freePageTableLRU(void)
{
    // TODO: implement
}

