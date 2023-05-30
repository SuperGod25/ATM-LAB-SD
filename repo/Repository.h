#ifndef LAB_2_REPOSITORY_H
#define LAB_2_REPOSITORY_H
#include "vector"
#include "../domain/Tranzactions.h"
#include "Double_List.h"

class Repository {
public:
    Repository();

    std::vector<Tranzactions> &getStorage();

    std::vector<std::pair<int,int> > return_all();

    void setStorage(const std::vector<Tranzactions> &storage);

    void save_tranzactions();
    void read_tranzaction();
    void add(Tranzactions transaction);

private:
    std::vector<Tranzactions> local;
    List<std::pair<Tranzactions,int>> storage;
};


#endif //LAB_2_REPOSITORY_H
