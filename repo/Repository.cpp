#include <fstream>
#include <sstream>
#include <cstring>
#include "Repository.h"

Repository::Repository() {
    read_tranzaction();
}

std::vector<Tranzactions> &Repository::getStorage(){
    int i =0;
    while(i<storage.size())
    {
        std::pair<Tranzactions,int> q = storage.get_at(i);
        local.push_back(q.first);
        i++;
    }
    return local;
}

void Repository::add(Tranzactions transaction) {
    this->storage.push_back(std::make_pair(transaction,0));
}

void Repository::save_tranzactions() {
    ofstream fout("/Users/mpmp/Desktop/lab5/transaction.txt");
    int i =0;
    while(i<storage.size())
    {
        std::pair<Tranzactions,int> q = storage.get_at(i);
        std::vector<std::pair<int,int>> c= q.first.getTypes();
        for(auto i:c)
        {
            fout<<i.first<<" "<< i.second<<"/";
        }
        fout<<endl;
        i++;
    }
}

void Repository::read_tranzaction() {
    std::ifstream file;
    file.open ("/Users/mpmp/Desktop/lab5/transaction.txt");
    for( std::string line; getline( file, line ); )
    {
        Tranzactions c;
        std::vector<pair<int,int>> q;
        std::stringstream ss(line);
        std::string s;
        getline(ss,s,'/');
        while(ss)
        {
            std::stringstream ss1(s);
            std::string s1;
            getline(ss1,s1,' ');
            int x = atoi(s1.c_str());
            getline(ss1,s1,' ');
            q.push_back(make_pair(x, atoi(s1.c_str())));
            getline(ss,s,'/');
        }
        c.setTypes(q);
        c.setId(1);
        storage.push_back(make_pair(c,0));
    }
    file.close();
}

