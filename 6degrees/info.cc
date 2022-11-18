#include "info.h"
#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>


ActorInfo::ActorInfo(char* fileName){
    int fd = open(fileName, O_RDONLY);

    struct stat fileStats;
    fstat(fd, &fileStats);

    std::cout<<fileStats.st_size<<std::endl;

    void* startOfMemory = mmap(0, fileStats.st_size, PROT_READ, MAP_SHARED, fd, 0); // gets the starting pointer of the allcoated memory map for the file
}

int ActorInfo::getNumEntries() const{
    return numEntries;
}