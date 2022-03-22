#include <iostream>
#include "Notebook.hpp"
using namespace std;
using namespace ariel;


namespace ariel{
    Notebook::Notebook(){
        
    }
    
    void Notebook::write(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, string msg){

    }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len){
        return " ";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len){

    }
    void Notebook::show(unsigned int page){

    }

}

