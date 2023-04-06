# Lab 10
- LRU - least recently used, has not been used recently. Lets remove and replace the one that was used last
- OPT - optimal Does whatever that one does
Want to reduce page faults

## replace.c -
main() simulates page repl.
with lru/opt
Frames - number of pages we can hold
Reference string - string of page requests
upper Page Bound - highest page #

Basically when our table fills up, we need to replace the page based on either LRU or OPT algorithm 

hit - page is in the table

Ref string = 6106 - 6 was put in the table first, so it will have a hit the second time

## LRU - lruList.c lruList.h
Double linked list 

When we hit, move to top of the linked list, when we miss kick the bottom of the linked list off

Make sure to keep track of bottom of list

### lruList.h - 
```
frame {
    int page
    *up // (next)
    *down // (prev)
} // the reason its up down is thats how we draw memory
```

### lruList.c
```
testLRU() {
    for everything in our reference string
        insertLRU()
        searchLRU() // start with search
        displayLRU()
}

void insertLRU(int pageNumber) {
    if searchLRU() is null {
        if pageTableSize < numberOfFramesPerProcess
            if top == NULL
                then just make our new thing top
                pageTableSize++
            else {
                go to top
                up on currentTop = newTop
                down on newTop = currentTop
                top = newTop
                pageTableSize++
            }
        else { // our linked list is full
            go to bottom node and get rid of that shit
            go to one above set down to null
            free()

            go to top
            up on currentTop = newTop
            down on newTop = currentTop
            top = newTop
            // dont need to adjust the size cuz we got rid of one and added another
        }
    } else { // we got a hit
        take our hit, connect up and down
        put our hit on the top and adjust next and down accordingly 
    }
}

// my notes, not Scrivnor's
searchLRU(pagenumber) {
    next = top
    while next is not null
        if pagenumber = next.pagenumber
            return next
        next = next.down

    return NULL
}
```