
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>


using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

class Account
{
public:
    Account();// default constructor
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

private:
    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}
// Task 1 (5 points)
// Implement Account constructor with arguments
Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt)
{
  this->id = id;
  this->name = name;
  this->validity_dt = validity_dt;
}

// Task 2 (10 points)
// Implement operator< overloading for Transaction
bool Transaction::operator<(const Transaction& other) const
{
  std::string type_1 = this->type;
  std::string type_2 = other.type;
  if (type_1 == "deposit") {
    return true;
  }
  else if (type_1 == "withdraw" && type_2 != "deposit") {
    return true;
  }
  else if (type_1 == "transfer" && type_2 != "transfer") {
    return false;
  }
  else {
    return true;
  }
  return this->date < other.date;
}
// Task 3 (10 points)
// Implement get balance to date method (default max value)
double Account::getBalance(UnixTS timestamp) const
{
  double balance = 0;
    for (auto& ele: this->transactions) {
      if (ele.date < timestamp) {
        if (ele.type == "withdraw") 
          balance -= ele.amount;
        else if (ele.type == "deposit")
          balance += ele.amount;
        else {
          if (ele.from == ele.to) {}
          else if (this->id == ele.from) {
            balance -= ele.amount;
          }
          else if (this->id == ele.to) {
            balance += ele.amount;
        }
      }
    }
  }
  return balance;
}

// Task 4 (15 points)
// Implement adding transaction to Account
void Account::addTransaction(const Transaction& transaction)
{
  this->transactions.insert(transaction);
}


// Task 5 (20 points)
// Implement transaction and account reading from csv and fill accounts by transactions
using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
      std::getline(fileStream, line);
      std::stringstream ss(line);
      Transaction transaction;

      std::string id, sdata, samount;
      UnixTS date;
      std::string type;
      std::string from;
      std::string to = "";
      double amount;

      ss >> id >> date >> type >> from;

      if (type == "transfer")
        ss >> to;
      
      ss >> amount;
      transaction = Transaction{id, date, type, from, to, amount};
      transactions.insert(transaction);
    }


    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
        std::stringstream ss(line);
        std::string field;
        Transaction transaction;
        for (unsigned short i = 0; i < TRANSACTION_COL_N; i++)
        {
          std::getline(fileStream, line);
          std::stringstream ss(line);
          Account account;

          std::string id, name;
          UnixTS validity;
          
          ss >> id >> name >> validity;
          account = Account(id, name, validity);
          accounts[id] = account;
        }
    }

    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
  for (auto it: transactions) {
    accounts[it.id].addTransaction(it);
  }
}
