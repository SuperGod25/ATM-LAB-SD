#include "ATM.h"
#include "../repo/Iterator_Dinamic.h"
#include <fstream>

ATM::ATM() {
    int i;
    i=0;
    col = Collection_Dinamic<int>();
    this->add_money();
//    while(i<49)
//    {
//        col.add(5);
//        i++;
//    }
//    i=0;
//    while(i<30)
//    {
//        col.add(10);
//        i++;
//    }
//    i=0;
//    while(i<20)
//    {
//        col.add(50);
//        i++;
//    }
//    i = 0;
//    while(i<10)
//    {
//        col.add(100);
//        i++;
//    }

}

ATM::~ATM() {
//    this->put_money();
}

void ATM::control_cash(int sum) {
    std::vector<Tranzactions> v;
    v = aplly_back(sum,col);
    int i = 0;
    for(const auto& el:v)
    {
        std::vector<std::pair<int,int>> x1 = el.getTypes();
        std::cout<<i<<") ";
        i++;
        for(auto k:x1)
            std::cout<<k.first<<"*"<<k.second<<" ";
        std::cout<<std::endl;
    }

    int opt;
    std::cout<<"\nAlege varianta care o vrei:";
    std::cin>>opt;
    if(opt >= v.size())
        throw std::invalid_argument("Aceasta nu este o optiune valida!");
    v[opt].setSum(sum);
    v[opt].setId(storage.getStorage().size());
    storage.add(v[opt]);

//    Iterator_Dinamic colection(col);
//    while(colection.valid())
//    {
//        for(const auto& vectors:v)
//        {
//            std::vector<std::pair<int,int>> cash = vectors.getTypes();
//            for(auto j:cash)
//            {
//                if(colection.current() == j.first)
//                    colection.remove(colection.current(),j.second);
//            }
//        }
//        colection.next();
//    }
}

std::vector<Tranzactions> ATM::return_all() {
    return storage.getStorage();
}

void ATM::add_money() {
    ifstream fin("/Users/mpmp/Desktop/lab5/money.txt");
    int x;
    while(fin>>x)
    {
        this->col.add(x);
    }
    fin.close();
}

void ATM::put_money() {
    ofstream  fout("/Users/mpmp/Desktop/lab5/money.txt");
    int i =0;
    while(i<col.size())
    {
        int q = col.getAt(i);
        int q1 = col.nrocc_poz(i);

        while(q1>0)
        {
            fout<<q<<" ";
            q1--;
        }
        i++;
    }
}

void ATM::save_tr() {
    storage.save_tranzactions();
}

