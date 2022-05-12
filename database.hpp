#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "statement.hpp"
#include <array>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#define  _int32 0
#define  _float32 1
#define  _string 2
namespace Blinding {
    enum VarType{
        int32,
        float32,
        string
    };//变量类型的枚举
    struct Table{
        std::string table_name;                                        //表名
        std::vector<std::string> header;
        std::map<std::string,uint32_t> col;                        //表头
        std::map<std::string,std::vector<int32_t>> int_var;         //int类型数据
        std::map<std::string,std::vector<float>> float_var;         //float类型数据
        std::map<std::string,std::vector<std::string>> string_var;  //字符串类型
        uint32_t records_num=0;
        uint32_t col_num=0;
        Table()=default;

        explicit Table(std::string &name):table_name(name){ header[0]="Order";};
        Table(std::string &name,bool flag):table_name(name){ read();header[0]="Order";}
                                                                    //构造函数，根据table名读取数据
        ~Table()= default;;
        ReadTable read();                                           //读取文件中的数据
        //ReadTable read(std::string &name);
        WriteTable write();                                         //储存数据到磁盘

    };

    class Database{
    public:
        std::string db_name;                                           //数据库名
        std::vector<Table*> tables;                               //表
        uint16_t tables_nums=0;                                       //表数

        Database()=default;
        explicit Database(std::string &name):db_name(name){}
        Database(std::string &name,bool flag):db_name(name){ this->read();};
        ~Database()= default;;

        ReadDatabase read();
        //ReadDatabase read(std:: string &name);                      //读取数据
        WriteDatabase write();                                      //储存数据到磁盘
    private:
        //const char header[2]="DB" ;
        const char separator='#';
    };

    
}



#endif