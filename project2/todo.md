## Start with mapping create function

### CIFS_CONTEXT_TYPE
```
file system context

 holds the registry and an in-memory copy of the volume bitvector

 the registry is created when mounting the system (through traversal)
 the bitvector is copied from the volume when mounting

 all access to the files is through the registry (create, delete, get info, read, write)

 the in-memory bitvector must be used when the system is mounted, but updated on the disc
 on every successful creation, deletion, write, and read

 elements are added to the list of processes when they successfully open files; when a file is closed
 (by the same process), then the entry is removed
 ```