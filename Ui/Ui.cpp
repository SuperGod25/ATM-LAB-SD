#include "Ui.h"

using namespace std;

Ui::Ui() {}

void Ui::menu() {
    cout<<"1.Platirea unei sume\n2.Afisarea tuturor tranzactilor\n";
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
            default: {
                this->atm.put_money();
                this->atm.save_tr();
                ok = false;
            }
        }
    }
}
