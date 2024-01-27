#include <iostream>
using namespace std;


class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();


int main()
{
    
    /*cout << "hh" << endl;
    cout << "hh" << flush;
    cout << "hh" << ends;*/

}