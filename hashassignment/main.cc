#include <iostream>
#include <optional>

class HT{
    int length;
    char* elements;

    public:
        HT(){
            this->length = 0;
            this->elements = (char *) malloc(11*26*sizeof(char));


        };
        bool insert(std::string key){
            if (key.length() > 10){
                return false;
            }
            char last = key[key.length() - 1];
            int offset = last - 'a';
            std::cout<<offset<<std::endl;

            for (int i = 0; i < key.length(); i++){
               this->elements[offset * 11 + i] = key[i]; 
            }
            this->elements[offset*11 + key.length()] = '\0';

            return true;
        }
        std::string get(char key){
            int offset = key - 'a';
            std::string out = "";
            int idx = 0;
            while (this->elements[offset * 11 + idx] != '\0'){
                out += this->elements[offset*11+idx];
                idx++;
            }

            return out;
        }
};


int main(){


    HT hi = HT();
    hi.insert("apple");
    std::cout<<hi.get('e')<<std::endl;


}