#include <string>

class ActorInfo{
    void* startOfMemoryPtr;
    int numEntries;


   public:
    ActorInfo(char* fileName);

    int getNumEntries() const;

    std::string getOffset(int offset){
        
    }

};