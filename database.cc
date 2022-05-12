#include "database.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

#define re(a) reinterpret_cast<char*>(&(a)),
namespace Blinding {
    ReadTable Table::read() {
        std::string filename(this->table_name);
        filename.append("csv");
        std::fstream out_file(filename);
        if(!out_file.is_open()) return FAILED_TO_OPEN_FILE_TABLE;
        std::vector<std::string> array;
        std::string line;
        std::string str;


        getline(out_file,line);
        std::stringstream  ss(line);
        while(getline(ss,str,',')){
            if(this->col_num>=10) return COl_NOT_MATCH;
            this->header.push_back(str);
            this->col_num++;
        }



        getline(out_file,line);
        std::stringstream  sss(line);
        for(auto i=0;i<this->col_num;i++){
            getline(sss,str,',');
            this->col[this->header[i]]= stoi(str);
        }
        while (getline(out_file,line)){
            std::stringstream buffer(line);
            for(int i=0;i<col_num;i++){
                getline(buffer,str,',');
                if(this->col[this->header[i]]==_int32)
                    (this->int_var[this->header[i]])[this->records_num]= stoi(str);
                if(this->col[this->header[i]]==_float32)
                    (this->float_var[this->header[i]])[this->records_num]= stof(str);
                if(this->col[this->header[i]]==_string)
                    (this->string_var[this->header[i]])[this->records_num]= str;

            }
            this->records_num++;
        }

    }
    WriteTable Table::write() {
        std::string filename(this->table_name);
        filename.append("csv");
        std::fstream out_file(filename);
        out_file.flush();
        if(!out_file.is_open()) return FAILED_TO_OPEN_FILE_WRITE_TABLE;
        for(int i=0;i< this->col_num;i++)
            std::cout<< this->header[i]<<",";
        std::cout<<"\n";
        for(int i=0;i< this->col_num;i++)
            std::cout<< this->col[this->header[i]]<<",";
        std::cout<<"\n";
        for(int i=0;i<this->records_num;i++){
            for(int j=0;j< this->col_num;j++){
                if(this->col[this->header[j]]==int32)
                    std::cout<<(this->int_var[this->header[j]])[i]<<",";
                if(this->col[this->header[j]]==float32)
                    std::cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(3)<<(this->float_var[this->header[j]])[i]<<",";
                if(this->col[this->header[j]]==string)
                    std::cout<<(this->string_var[this->header[j]])[i]<<",";
            }
            std::cout<<"\n";
        }
        return WRITE_SUCCESS;
    }
    ReadDatabase Database::read() {
        std::string filename(this->db_name);
        filename.append(".db");
        std::fstream in_file(filename);
        std::string buffer;
        while(in_file>>buffer){
            this->tables[this->tables_nums]->table_name=buffer;
            this->tables_nums++;
        }
    }
    WriteDatabase Database::write() {
        std::string filename(this->db_name);
        filename.append(".db");
        std::fstream out_file(filename);
        if(!out_file.is_open())return FAILED_TO_OPEN_FILE_DB_OUT;
        out_file.flush();
        for(auto i=0;i<this->tables_nums;i++){
            out_file<< this->tables[i]->table_name<<"\n";
        }
        return WRITE_DATABASE_SUCCESS;
    }

}