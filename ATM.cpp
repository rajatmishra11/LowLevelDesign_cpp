#include <bits/stdc++.h>
using namespace std;

/// making different classes of differnt notes
class Hundrednotes
{
public:
    int countHundrednotes;
    Hundrednotes(int number)
    {
        countHundrednotes = number;
    }
};

class TwoHundrednotes
{
public:
    int countTwoHundrednotes;
    TwoHundrednotes(int number)
    {
        countTwoHundrednotes = number;
    }
};

class FiveHundrednotes
{
public:
    int countFiveHundrednotes;
    FiveHundrednotes(int number)
    {
        countFiveHundrednotes = number;
    }
};

class TwoThousandnotes
{
public:
    int countTwoThousandNotes;
    TwoThousandnotes(int number)
    {
        countTwoThousandNotes = number;
    }
};

class FiveThousandsnotes
{
public:
    int countFiveThousandNotes;
    FiveThousandsnotes(int number)
    {
        countFiveThousandNotes = number;
    }
};

// Denominations has all note related class
class Denominations
{
private:
    Hundrednotes hundrednotes;
    TwoHundrednotes twoHundrednotes;
    FiveHundrednotes fiveHundrednotes;
    TwoThousandnotes twoThousandnotes;
    FiveThousandsnotes fiveThousandsnotes;

public:
    Denominations(int hun, int twoHun, int fiveHun, int twoThou, int fiveThou)
        : hundrednotes(hun), twoHundrednotes(twoHun), fiveHundrednotes(fiveHun),
          twoThousandnotes(twoThou), fiveThousandsnotes(fiveThou) {}

    Hundrednotes &getHundrednotes()
    {
        return hundrednotes;
    }
    TwoHundrednotes &getTwoHundrednotes()
    {
        return twoHundrednotes;
    }
    FiveHundrednotes &getFiveHundredNotes()
    {
        return fiveHundrednotes;
    }
    TwoThousandnotes &getTwoThousandNotes()
    {
        return twoThousandnotes;
    }
    FiveThousandsnotes &getFiveThousandNotes()
    {
        return fiveThousandsnotes;
    }
};

class PMValidation
{
public:
    bool isValid(int denomination)
    {
        if (denomination == 5000)
            return false;
        else
            return true;
    }
};

class CashManagement
{
private:
    PMValidation pm;
    Denominations notes;

public:
    CashManagement(int hun, int twoHun, int fiveHun, int twoThou, int fiveThou)
        : pm(), notes(hun, twoHun, fiveHun, twoThou, fiveThou) {}

    string withDraw(int amount)
    {
        string withdrawalCurrency;
        int currentbalance = notes.getFiveHundredNotes().countFiveHundrednotes * 500 +
                             notes.getHundrednotes().countHundrednotes * 100 +
                             notes.getTwoHundrednotes().countTwoHundrednotes * 200;

        if (amount > currentbalance)
        {
            return "Insufficient balance";
        }
        else
        {
            int count5000 = 0;
            int count2000 = 0;
            int count500 = 0;
            int count200 = 0;
            int count100 = 0;

            while (amount > 0)
            {
                if (amount >= 5000 && pm.isValid(5000))
                {
                    amount -= 5000;
                    count5000++;
                }
                else if (amount >= 2000 && pm.isValid(2000))
                {
                    amount -= 2000;
                    count2000++;
                }
                else if (amount >= 500 && pm.isValid(500))
                {
                    amount -= 500;
                    count500++;
                }
                else if (amount >= 200 && pm.isValid(200))
                {
                    amount -= 200;
                    count200++;
                }
                else if (amount >= 100)
                {
                    amount -= 100;
                    count100++;
                }
            }

            withdrawalCurrency += "5000 Notes: " + to_string(count5000) + "\n";
            withdrawalCurrency += "2000 Notes: " + to_string(count2000) + "\n";
            withdrawalCurrency += "500 Notes: " + to_string(count500) + "\n";
            withdrawalCurrency += "200 Notes: " + to_string(count200) + "\n";
            withdrawalCurrency += "100 Notes: " + to_string(count100) + "\n";

            return withdrawalCurrency;
        }
    }
};

class ATM
{
private:
    CashManagement cashManagement;

public:
    ATM(int hun, int twoHun, int fiveHun, int twoThou, int fiveThou)
        : cashManagement(hun, twoHun, fiveHun, twoThou, fiveThou) {}

    CashManagement &getCashManagement()
    {
        return cashManagement;
    }
};

int main()
{
    ATM atm(10, 10, 10, 10, 10); // Initializing ATM with some initial notes
    cout << atm.getCashManagement().withDraw(8000);
    return 0;
}
