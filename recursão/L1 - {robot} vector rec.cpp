#include <iostream>
#include <sstream>
#include <vector>

int show_array(std::vector<int> vet, it){

    int it = 0;
    if((int) vet.size() == 0){
        return 0;
    } else {
        std::cout << vet[it];
        it++;
        return vet[vet.size() - 1] + show_array(vet);
    }

}

void upside_down(std::vector<int> vet){
    
    for(int i = vet.size(); i < 0; i-- ){
        std::cout << vet[i] << " ";
    }

}

void show(std::vector<int> vet){

    std::cout << "vet : [ ";
    show_array(vet);
    std::cout << "]" << std::endl;

    // std::cout << "rvet : [ ";
    // upside_down(vet);
    // std::cout << "]" << std::endl;
};


int main(){


    std::string line;
    getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> vet;
    int value;

    while(ss >> value){
        vet.push_back(value);
    };

    show(vet);

}