#include <iostream>
#include <string>
#include <vector>
//#include "account.h"
#include "account_manager.h"


int main() {

  account_manager acc;

  acc.create_map("account2.dat");

  std::cout << "Before: \n\n";

  acc.print_map();

  acc.account_transactions("transact.dat", "account.log");

  std::cout << "\nAfter: \n\n";

  acc.print_map();

  std::cout << "\nAfter Monthly Update: \n\n";

  acc.monthly_update_map();

  acc.print_map();

  acc.output_map_to_file("update.dat");

  acc.output_report("report.txt");



  //account* a = new simple_account("1234567", "Joel", "Martin", 8000.00);

  //account_master acc("9587498357Bayern         Richard                  E00003457.12");
  //std::string b = ;
  //account* a;
  //a = create_account("9587498357Bayern         Richard                  A00003457.12");
  //if(a){
  //a->monthly_update();

  //std::cout << *a << "O\n";

  //a->print_account();
  //}
  //a.monthly_update();

  //char c = a.type();

  //std::cout << a;
}