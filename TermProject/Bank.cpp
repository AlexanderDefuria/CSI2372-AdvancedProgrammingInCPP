// --------------------------------------------------------------------
// Alexander De Furia SN# 0300190815
// --------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

#include "Bank.h"

using namespace std;

double DepositAccount::rate = 6.50;
double totalAccounts = 0.0;

//******************************************************************
// Basic functions of the BankAccount class
//******************************************************************
inline BankAccount::BankAccount()
{
    accountId = type = updateDate = 0;
    clientName = new char[1];
    balance = 0.0;
}

inline BankAccount::BankAccount(long id, int newType,
                                    char * name, long newDate, double newBalance):
                                    accountId(id), type(newType),
                                    updateDate(newDate), balance(newBalance)
{
     clientName = new char[strlen(name) + 1];
     strcpy(clientName, name);
}

inline BankAccount::~BankAccount()
{
     if (clientName)
     {
          delete [] clientName;
     }
}

inline void BankAccount::setAccountId(long account)
{
     accountId = account;
}

inline void BankAccount::setType(int newType)
{
     type = newType;
}

inline void BankAccount::setClientName(char * name)
{
     if (clientName)
     {
          delete [] clientName;
     }
     clientName = new char[strlen(name) + 1];
     strcpy(clientName, name);
}

inline void BankAccount::setUpdateDate(long newDate)
{
     updateDate = newDate;
}

inline void BankAccount::setBalance(double newBalance)
{
     balance = newBalance;
}

void BankAccount::print() 
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << accountId << "\t\t\t" << type << "\t" << updateDate << "\t\t" << balance;
}

//******************************************************************
// Basic functions of the DepositAccount class
//******************************************************************
inline DepositAccount::DepositAccount(long id, int newType, char * name,
                                    long newDate, double balanceArg, int nbyear) :
                                    BankAccount(id, newType, name,
                                    newDate, balanceArg), nbyears(nbyear)
{}

inline void DepositAccount::setNbYears(int nbyear)
{
     nbyears = nbyear;
}

void DepositAccount::print() 
{
    Bonus();
    BankAccount::print();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\t" << nbyears << "\t\t" << rate << endl;
}

//******************************************************************
// Functions of the class DepositAccount. It allows to calculate
// the annual bonus on deposit accounts.
// Inputs: Nothing
// Outputs: Nothing
//******************************************************************
void DepositAccount::Bonus()
{
  setBalance(getBalance() + (getBalance()* getRate() * (getNbYears())/36000.00));
}



//******************************************************************
// Basic functions of the LoanAccount class
//******************************************************************
inline LoanAccount::LoanAccount(long id, int newType, char * name,
                                    long newDate, double newBalance, int nbyear,
                                    double newRate) : BankAccount(id, newType,
                                    name, newDate, newBalance), nbyears(nbyear), rate(newRate)
{ }

inline void LoanAccount::setNbYears(int nbyear)
{
     nbyears = nbyear;
}

inline void LoanAccount::setRate(double newRate)
{
     rate = newRate;
}

void LoanAccount::print() 
{
    BankAccount::print();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\t" << nbyears << "\t\t" << rate << endl;
}

//******************************************************************
// Basic functions of the Transaction class
//******************************************************************
inline Transaction::Transaction(long idTr, int typeTr, long dateTr,
                                    int codeTr = 01, double amountTr):
                                    accountId(idTr), type(typeTr),
                                    date(dateTr), code(codeTr),
                                    amount(amountTr)
{ }

inline void Transaction::setAccountId(long compteTr)
{
     accountId = compteTr;
}

inline void Transaction::setType(int typeTr)
{
     type = typeTr;
}

inline void Transaction::setDate(long dateTr)
{
     date = dateTr;
}

inline void Transaction::setCode(int codeTr)
{
     code = codeTr;
}

inline void Transaction::setAmount(double amountTr)
{
     amount = amountTr;
}



//****************************************************************************
// Purpose: Sort a list of bank accounts in ascending order of ids and types.
//
// WARNING: This sort leaves the last account (of id 0) of the list which has 
// its position to assure the tests of end of list later !!!
//
// Inputs: listAccount(BankAccount *), a list of bank accounts.
// Outputs: listAccount(BankAccount *), sorted list of bank accounts.
//****************************************************************************
void sortAccounts(BankAccount ** list)
{

    struct sort {
        static void swap (BankAccount** a, BankAccount** b) {
            BankAccount *temp = *a;
            *a = *b;
            *b = temp;
        };

        static auto partition (BankAccount** lList, long low, long high) {
            long pivot = lList[high]->getAccountId();
            long i = (low - 1);

            for (long j = low; j <= high; j++)
                if (lList[j]->getAccountId() == pivot) {
                    pivot = lList[high]->getType();
                    if (lList[j]->getType() <  pivot) {
                        i++;
                        swap(&lList[i], &lList[j]);
                    }
                } else if (lList[j]->getAccountId() < pivot) {
                    i++;
                    swap(&lList[i], &lList[j]);
                }

            i++;
            swap(&lList[i], &lList[high]);
            return (i);
        };

        static void quicksort (BankAccount** lList, long low, long high) {
            if (low < high) {
                auto middle = partition(lList, low, high);
                quicksort(lList, low, middle - 1);
                quicksort(lList, middle + 1, high);
            }
        };
    };

    int size = 0;
    for(int k = 0; k < K_SizeMax; k++) {size += (list[k] ? 1 : 0);}

    sort::quicksort(list, 0, size-1);

}

//******************************************************************
// Purpose: This function reads the file 'clients.txt' and builds 
// an array containing the different bank accounts of customers.
//
// Inputs: Nothing
// Output: listAccount(type: BankAccount *), the list of bank 
//         accounts read from the file 'clients.txt'.
//******************************************************************
BankAccount ** readAccounts()
{
    ifstream inputFile("clients.txt");	// Opening the input file
    if (!inputFile)            		// If the file is not found...
    {
        cout << "File not found !!!" << endl;
        exit(0);
    }

    BankAccount ** listAccounts = new BankAccount*[K_SizeMax];
    if (!listAccounts) {
        cout << "Full memory. !!!" << endl;
        return listAccounts;
    }

    BankAccount ** pAccount = listAccounts;
	 
    long accountRead, dateRead;
    int TypeRead, nbyearRead, counter = 0;
    double balanceRead, RateRead;
    char nameRead[60];
	 
    inputFile >> accountRead >> TypeRead >> dateRead >> balanceRead >> nbyearRead >> RateRead;
    inputFile.getline(nameRead, 60);
	 
    while (inputFile && (counter < K_SizeMax - 1)){
        // YOU HAVE TO DO SOMETHING FROM HERE !!!
        if (nbyearRead > 0) {
            // Default Rate for Term Deposit is 6.50
            if (TypeRead == 3 && RateRead == 0)
                RateRead = 6.5;
            listAccounts[counter] = new LoanAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead, nbyearRead,
                                                    RateRead);
        }
        else
            listAccounts[counter] = new BankAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead);

        listAccounts[counter]->print();
        cout << endl;

	
	
	
	
	
	
	
	
	
	
	
	

        // UNTIL THIS POINT.
        int x = 1;
        inputFile >> accountRead >> TypeRead >> dateRead >> balanceRead >> nbyearRead >> RateRead;
        inputFile.getline(nameRead, 60);
        pAccount++;
        counter++;
    }
    *pAccount = new BankAccount();
    delete pAccount;
    return listAccounts;
}





//*****************************************************************************************
// Purpose: This function validates whether the transaction code 
//          corresponds to the correct account:
//              - 01 ==> account (01: Check, 02: Savings, 03: Deposit and 04: Loan)
//              - 02 ==> account (01: Check, 02: Savings)
//              - 03 ==> account (01: Check).
//
// Inputs: trans (Type: Transaction) an instance of the Transaction class.
// Outputs: true (Type bool) if the transaction matches one of the accounts listed above.
// false (Type bool) otherwise.
//*****************************************************************************************
Bool BankAccount::validateTransaction(const Transaction trans) const
{
    if ( ( (trans.getCode() == 02) && ( isDepositAccount() || isLoanAccount()) ) ||
         ( (trans.getCode() == 03) && ( isDepositAccount() || isLoanAccount() || isSavingsAccount() ) ) )
      {
       return FALSE;
      }
    else
      {
       return TRUE;
      }
        
}





//******************************************************************************
// Purpose: This function is used to execute the transaction already performed 
// (update the balance of an account).
//
// Inputs: trans (Transaction Type), instance of Transaction class
// Outputs: Nothing
//*******************************************************************************
void BankAccount::executeTransaction(const Transaction trans)
{
     if (validateTransaction(trans))
       {
         if (trans.getCode() == 01)    // Deposit
           {
             setBalance(getBalance() + trans.getAmount());
           }
         else 
           { if (trans.getCode() == 02)    // Withdrawal
                {
                  if (getBalance() >= trans.getAmount())
                     { setBalance(getBalance() - (trans.getAmount() + 0.50)); }
                  else {cout << " insufficient balance!! " << endl; }
                }
             else 			// Check
                {
                  if (getBalance() >= trans.getAmount())
                     { 
                       setBalance(getBalance() - trans.getAmount());
                     }
                  else {cout << " insufficient balance!! " << endl; }
                }
           }
                 
       }   
 
}

//***********************************************************************
// Purpose: This function is used to execute a read transaction
// (updating the balance of the loan account).
//
// Inputs: trans (Transaction Type), instance of the Transaction class
// Outputs: Nothing
//***********************************************************************
void LoanAccount::executeTransaction(const Transaction trans)
{
     if (validateTransaction(trans))
     {
        if (trans.getCode() == 01)    // Deposit
        {
          setBalance(getBalance() - trans.getAmount());
         
        }
     }
}





//*************************************************************************
// Purpose: This function allows to read the file 'transact.txt' 
//          and to update the accounts concerned by the transactions read.
//
// Inputs: listAccount (type BankAccount *), the list of bank accounts.
// Output: Nothing.
//*************************************************************************
void updateAccounts(BankAccount ** listAccounts) {
    ifstream inputFile("transact.txt");	// Opening the input file
    if (!inputFile) {
        cout << "File not found !!!" <<endl;
        exit(0);
    }
    auto search = [] (BankAccount** list, int _size, int id) -> int {
        int left = 0, right = _size;
        while (left < right) {
            long mid = (left + (right)) / 2;
            long midID = list[mid]->getAccountId();

            if (midID == id) return mid;
            else if (midID < id) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    };



    int size = 0;
    for(int k = 0; k < K_SizeMax; k++)
        if (listAccounts[k]) {
            size += 1;
            // If it has an interest rate.
            if (listAccounts[k]->getType() >= 3) {

            }
        }
        else
            break;
    size;



    int id,type,date,code = 0;
    double amount = 0.0;

    inputFile >> id >> type >> date >> code >> amount ;

    // Return the index of the account for the transaction.
    while (inputFile) {
        Transaction *t = new Transaction(id, type, date, code, amount);
        int index = search(listAccounts, size, id);
        if (index != -1) {
            listAccounts[index]->executeTransaction(*t);
        }

        inputFile >> id >> type >> date >> code >> amount ;
    }


	 
	 
	 
	 
	 
	 
	 
	 
	 
}

//******************************************************************************
// Purpose: This function displays the list of bank accounts for all customers.
//
// Inputs: listAccount (type: BankAccount *), the list of bank accounts.
// Outputs: Nothing
//******************************************************************************
void displayAccounts(BankAccount ** listAccounts)
{
    cout << endl << endl << endl;

    cout << "        THE REPORT OF THE BANK ACCOUNTS OF CLIENTS" << endl;
    cout << "        ------------------------------------------" << endl;

    int i = 0;

    while (listAccounts[i]) {
        if (listAccounts[i]->getType()==0) { i++; continue; }
        char *x = listAccounts[i-1]->getClientName();
        char *y = listAccounts[i]->getClientName();
        if (strcmp(x, y) !=0) {
            cout << endl << "\tClient Name:" << listAccounts[i]->getClientName() << endl;

            cout << left << std::setw(18) << "Bank Account" << std::setw(6) << "Type"
                 << std::setw(14) << "Update Date" << std::setw(13) << "Balance" << std::setw(10) << "Nb.Years" <<
                 std::setw(10) << "Rate" << endl;

            cout << std::left << std::setw(18) << "------------" << std::setw(6) << "----"
                 << std::setw(14) << "-----------" << std::setw(13) << "------" << std::setw(10) << "--------" <<
                 std::setw(10) << "----" << endl;
        }

        if (listAccounts[i]->getType() >= 3) {
            LoanAccount *la = dynamic_cast<LoanAccount*>(listAccounts[i]);

        }

        cout << std::left << std::setw(18) << listAccounts[i]->getAccountId() << std::setw(6)
        << listAccounts[i]->getType()
        << std::setw(14) << listAccounts[i]->getUpdatedate() << std::setw(13)
        << listAccounts[i]->getBalance();
        if (listAccounts[i]->getType() >= 3) {
            LoanAccount *la = dynamic_cast<LoanAccount*>(listAccounts[i]);
            cout << setw(10) << la->getNbYears()
            << std::setw(10) << la->getRate() << endl;
            int x = 0;
        } else
            cout <<endl;

        i++;
    }

	
	
	
	
	
	
	
	
}




int main()
{
    BankAccount ** list = readAccounts();
    sortAccounts(list);
    displayAccounts(list);
    updateAccounts(list);
    cout << endl << endl;
    cout << "               ************************************************" << endl;
    cout << "               * RE-DISPLAY OF DATA AFTER THE UPDATE *" << endl;
    cout << "               ************************************************" << endl;
    displayAccounts(list);
    cout << endl;

	//system("PAUSE");
    delete[] list;
	return 0;
}
