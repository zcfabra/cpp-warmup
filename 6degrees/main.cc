// 6 degrees of Kevin Bacon from CS110 @ Stanford https://web.stanford.edu/class/cs110/
// Completely from scratch (i.e. no starter code from the assignment)

#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
int main(){

    int fd = open("./data/actordata", O_RDONLY);

    struct stat stats;

    fstat(fd, &stats);


    std::cout<<stats.st_size<<std::endl;


    void* start_of_data =   mmap(0, stats.st_size, PROT_READ, MAP_SHARED, fd, 0);

    int first_name_offset = *((int* ) start_of_data + 1);
    std::cout<<first_name_offset<<std::endl;

    char* first_char_ptr = ((char * ) start_of_data + first_name_offset);
    char first_char = *first_char_ptr;
    // std::cout<<first_char<<std::endl;
    char current_char = first_char;
    char* current_char_ptr = first_char_ptr;
    while (current_char != '\0'){
        std::cout<<current_char;
        current_char_ptr++;
        current_char = *current_char_ptr;
    };
    std::cout<<""<<std::endl;
};


