#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "database.hpp"
using Blinding::Database;
using Blinding::Table;
ExecuteResult create_db(std::string &name,Database* &pointer){
    pointer=new Database;
    pointer->db_name=name;
    pointer->write();
    return EXECUTE_SUCCESS;
}
PrepareResult prepare(std::string &cmd,Database *in_use){
    std::stringstream ss(cmd);
    std::string str;
    ss>>str;
    if(str=="create"){
        ss>>str;
        if (str=="table"){
            if(in_use==nullptr)return PREPARE_UNRECOGNIZED_STATEMENT;

        } else if(str =="database"){
            ss>>str;
            Database *pointer;
            create_db(str,pointer);
            return PREPARE_SUCCESS;

        } else{
            return PREPARE_UNRECOGNIZED_STATEMENT;
        }

    } else if(str=="drop"){
        ss>>str;
        if(str=="database"){

        } else if(str=="table"){
            ss>>str;
            if(in_use== nullptr) {
                std::cout<<"Please select a database first!\n";
                return PREPARE_SYNTAX_ERROR;
            }
            auto tar_table=std::find_if(in_use->tables.begin(),in_use->tables.end(),[str](Table *a){return a->table_name==str;});
            if(tar_table==in_use->tables.end()) {
                std::cout << "There is no table named " << str << " !";
                return PREPARE_SYNTAX_ERROR;
            }else{
                delete *tar_table;
                in_use->tables.erase(tar_table);
                std::cout<<"Table "<<str<<" has been delete successfully.\n";
                return PREPARE_SUCCESS;
            }
        }

    }else if(str=="delete"){

    }else if(str=="use"){
        ss>>str;

    }else if(str=="info"){

    } else if(str=="insert"){

    } else if(str=="select"){

    }else
        return PREPARE_UNRECOGNIZED_STATEMENT;
}
ExecuteResult execute(StatementType type,std::string &cmd){

}


int main (){
    std::string cmd;
    Database *in_use= nullptr;
    while(true){
        std::cout<<"BLdb> ";
        getline(std::cin,cmd);
        if(cmd==".exit") {
            std::cout<<"Bye!";
            break;
        }


    }
    return 0;
}