
#include "ATM.h"

ATM::ATM() {
    int i=0;
    total_amount = 0;
    i=0;
    while(i<50) //Adds 5 bills of 5
    {
        col.add(5);
        total_amount+= 5;
        i++;
    }
    i=0;
    while(i<30) //Adds 30 bills of 10
    {
        col.add(10);
        total_amount+= 10;
        i++;
    }
    i=0;
    while(i<20) //Adds 20 bills of 50
    {
        col.add(50);
        total_amount+= 50;
        i++;
    }
    i = 0;
    while(i<10) //Adds 10 bills of 100
    {
        col.add(100);
        total_amount+= 100;
        i++;
    }
    i=0;
    while(i<10) //Adds 10 bills of 200
    {
        col.add(200);
        total_amount+= 200;
        i++;
    }
    i=0;
    while(i<5) //Adds 5 bills of 500
    {
        col.add(500);
        total_amount+= 500;
        i++;
    }


}

ATM::~ATM() {

}

void ATM::control_cash(int sum) {
    if(sum > total_amount)
        std::cout<<"NU exista destule bancnote in ATM pentru a elibera acea suma! \n";
    else{
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
    std::cout<<"\nAlege varianta de plata preferata:";
    std::cin>>opt;
    if(opt >= v.size())
        throw std::invalid_argument("Aceasta nu este o optiune valida!");
    v[opt].setSum(sum);
    v[opt].setId(storage.getStorage().size());
    storage.add(v[opt]);

    Iterator colection(col);
    while(colection.valid())
    {
        for(const auto& vectors:v)
        {
            std::vector<std::pair<int,int>> cash = vectors.getTypes();
            for(auto j:cash)
            {
                if(colection.current() == j.first)
                    colection.remove(colection.current(),j.second);
            }
        }
        colection.next();
    }
}
}

std::vector<Tranzactions> ATM::return_all() {
    return storage.getStorage();
}

