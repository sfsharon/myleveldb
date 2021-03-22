#include <cassert>
#include <stdio.h>
#include <iostream>
#include "leveldb/db.h"

int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    std::string value = "mumu";
    std::string key1 = "sharon";
    std::string key2 = "here";

    leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (!s.ok()) 
    { 
        std::cerr << "Line "<< __LINE__ << " : levelDB error : " << s.ToString() << std::endl;  

            s = db->Put(leveldb::WriteOptions(), key1, value);
            if (!s.ok()) 
            { 
                std::cerr << "Line "<< __LINE__ << " : levelDB error : " << s.ToString() << std::endl;        
            }    
                delete db;
                return 0;
    } 
    else {
        std::cout <<"Line " << __LINE__ << " Key : " << key1 << ", Val : " << value << std::endl;

        s = db->Delete(leveldb::WriteOptions(), key1);
        if (!s.ok())  {
            std::cerr << "Line "<< __LINE__ << " : levelDB error : " << s.ToString() << std::endl;        
        }

        delete db;
        return 0;
    }
    
    s = db->Put(leveldb::WriteOptions(), key2, value);
    if (!s.ok()) 
    { 
        std::cerr << "Line "<< __LINE__ << " : levelDB error : " << s.ToString() << std::endl;        
    } 

    s = db->Delete(leveldb::WriteOptions(), key1);
    if (!s.ok())  {
        std::cerr << "Line "<< __LINE__ << " : levelDB error : " << s.ToString() << std::endl;        
    }

    return 0;    
}

