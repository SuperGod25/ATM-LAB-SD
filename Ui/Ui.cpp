
#include "Ui.h"

using namespace std;

Ui::Ui() {}

void Ui::menu() {
    cout<<"===================== MENU =====================\n";
    cout<<"|\t1. Platirea unei sume\n|\t2. Afisarea tuturor tranzactilor\n|\t0. Exit\n";
    cout<<"================================================\n\n";
    bool ok = true;
    while(ok)
    {
        int opt;
        cout<<"Optiune:";
        cin>>opt;
        switch (opt) {
            case 1:
            {
                int sum;
                cout<<"Suma=";
                cin>>sum;
                if(sum == 0 or sum % 5 != 0)
                    cout<<"ATM-ul nu poate elibera aceasta suma de bani! \n";
                else
                atm.control_cash(sum);
                break;
            }
            case 2:
            {
                std::vector<Tranzactions> transanctions = atm.return_all();
                for(const auto& trans:transanctions)
                {
                    cout<<trans<<endl;
                }
                break;
            }
            default:
                ok = false;
        }
    }
}
