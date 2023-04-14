# Project 1 notes

### cylinder, sector, track/head - physical repersentation - 
- store as a 3d array

### block -
- when you r/w on a disk, a block is how much you r/w, size of a block
- unit of sectors that we read/write 

*we are starting counting at 0*
```
cyl = 3, head = 3, sect = 3
max logical block address = cyl * head * sect, in this case 0-26
3 matricies for each cyl
3 x 3 matrix = cyl
rows of matrix = heads
each cell is a sector

logical block address/lba = 11, what us cyl, head, and sector chs = (1, 0, 2) 
how can we go from 11 to (1, 0, 2) and vice verse?

chs to lba - 

if c = 1, h = 0, s = 2
lba = ?

formula = c * (head * sect) + h * sect + s
i.e. 1 * (3 * 3) + 0 * 3 + 2 = 11

lba to chs -
c = lba/(head * sect)
h = (lba/sect) % head
s = lba % sect

```
## Task 1 -

``` 
chs2lba() and lba2chs() // same as formulas from above

// lba = lba, 
// # disk reads = size/SECT_SIZE
readDisk(lba_t lba, unsigned int size, char **buffer) {

}
```