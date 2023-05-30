#ifndef LAB_2_ATM_H
#define LAB_2_ATM_H


//#include "../repo/Multime.h"

#include "../repo/Collection.h"
#include "../repo/Repository.h"
#include "../util/backtraking.h"
#include "../repo/Collection_Dinamic.h"

class ATM {
public:
    ATM();

    std::vector<Tranzactions> return_all();

    virtual ~ATM();

    void control_cash(int sum);

    void add_money();
    void put_money();

    void save_tr();
private:
    Collection_Dinamic<int> col;
    Repository storage;
};


#endif //LAB_2_ATM_H
