#include "account.h"
#include <fstream>
#include "trim.h"

 account* create_account(std::string new_account){
   //try{
    std::string account_code1 = new_account.substr (0,10);
    std::string first_name1 = new_account.substr (10,15);
    std::string last_name1 = new_account.substr (25,25);
    std::string type = new_account.substr (50,1);
    double balance1 = std::stod(new_account.substr (51,11));

    generic::trim(first_name1);
    generic::trim(last_name1);
    account* a;
    if(type == "A"){
      a = new simple_account{account_code1, first_name1, last_name1, balance1, type};
    }else if(type == "B"){
      a = new bonus_account{account_code1, first_name1, last_name1, balance1, type};
    }else if(type == "C"){
      a = new service_account{account_code1, first_name1, last_name1, balance1, type};
    }else if(type == "D"){
      a = new balanced_account{account_code1, first_name1, last_name1, balance1, type};
    }else if(type == "X"){
      a = NULL;
    }else{
      a = NULL;
      std::ofstream o_stream{"account.log"};
      o_stream << "Couldn't open account number: "<< account_code1 << "\n";
      o_stream.close();
      }
      return a;
   //}catch(char const* s){
  //std::cerr << s << std::endl;
  //}
}
