#include <iostream>
#include <string>
#include <unordered_map>
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace std;
using namespace ariel;
using ariel::Direction;


namespace ariel{
    Notebook::Notebook(){
        unordered_map<int, unordered_map<int, char[100]> > pages;
    }
    
    void Notebook::write(int page, int row, int col, ariel::Direction dir, string msg){
        if(page < 0 || row < 0 || col < 0 || col > 99 || (int)msg.length() > 100){
            throw invalid_argument("invalid input!");
        }
        if(dir == Direction::Horizontal){
            if((int)msg.length() > 100 - col){
                throw invalid_argument("invalid input!");
            }
        }
    }
    string Notebook::read(int page, int row, int col, ariel::Direction dir, int len){
        if(page < 0 || row < 0 || col < 0 || col > 99 || len < 0 || len > 100){
            throw invalid_argument("invalid input!");
        }
        string text = "";
        if(dir == Direction::Horizontal){
            if(len > 100 - col){
                throw invalid_argument("invalid input!");
            }
            for (int i = col; i < len; i++)
            {
                text += pages.at(page).at(row)[i];
            }
        }
        if(dir == Direction::Vertical){
            for (int j = 0; j < len; j++)
            {
                text += pages.at(page).at(row+j)[col];
            }
        }
        return text;
    }

    void Notebook::erase(int page, int row, int col, ariel::Direction dir, int len){
        if(page < 0 || row < 0 || col < 0 || col > 99 || len < 0 || len > 100){
            throw invalid_argument("invalid input!");
        }
        if(dir == Direction::Horizontal){
            if(len > 100 - col){
                throw invalid_argument("invalid input!");
             }
            for (int i = col; i < len; i++)
            {
                pages.at(page).at(row)[i] = '~';
            }    
        }
        if(dir == Direction::Vertical){
            for (int j = 0; j < len; j++)
            {
                pages.at(page).at(row+j)[col] = "~"
            }
        }
    }

    void Notebook::show(int page){

    }

}
