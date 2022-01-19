#include <iostream>
#include "account_factory.h"
#include <map>
#include <iomanip>


class account_manager{
  private:
  static const int size = 1;
  std::map<std::string, account*> account_map;

  public:
  account_manager() = default;

   void create_map(const std::string& file){
     try{
     int i = 0;
     std::ofstream log("account.log");
     if(!log)throw "error log file";
     std::ifstream input(file);
     log << "Error opening input file for function 'create map'";
     if(!input){
       log << "Error opening input file for function 'create map'";
       throw file;}
    //std::map<std::string, account*> account_map;
    do{
      i++;
      std::string line;
      std::getline(input,line);
      account* a;
      a = create_account(line);
    if(a){
      account_map.insert( std::make_pair(a->get_account_code(),a) );
    }
    }while(!input.eof());
    input.close();
     }catch(std::string& s){
       std::cerr << "Error opening file: " << s;
     }catch(int i){
       std::cerr << "Error creating account profile from entry number :" << i;
     }

    
    }

    void print_map(){
      
      for (std::map<std::string, account*>::iterator it=account_map.begin(); it!=account_map.end(); ++it)
    std::cout << it->first << " => " << *it->second << '\n';
    }

    void account_transactions(const std::string& file1, const std::string& file2){
        int i = 0;
        std::ifstream input(file1);
        if(!input){
          std::cout << "failed to open input file";
          return;
        }
        std::ofstream output(file2);
        if(!output){
          std::cout << "failed to open output file";
          return;
        }
        do{
          std::string line;
          std::string acc;
          double transaction;
          double old_balance;
          double new_balance;
          std::map<std::string, account*>::iterator it;
          std::getline(input,line);
          //std::cout << line;

          acc = line.substr(0,10);
          transaction = std::stod(line.substr(10,11));

          //std::cout << acc << "=>" << transaction << "\n";
          
          it = account_map.find(acc);
          if(it == account_map.end()){
            output << "Couldn't find account number " << acc << " for transaction\n";
            continue;
          }
          old_balance = it->second->get_balance();
          new_balance = old_balance + transaction;
          it->second->change_balance(new_balance);
          
        }while(!input.eof());
      input.close();
      output.close();
    }

    void monthly_update_map(){
      for (std::map<std::string, account*>::iterator it=account_map.begin(); it!=account_map.end(); ++it)
    it->second->monthly_update();
    }

    void output_map_to_file(const std::string& file){
      std::ofstream output(file);
        if(!output){
          std::cout << "failed to open output file";
          return;
        }
        for (std::map<std::string, account*>::iterator it=account_map.begin(); it!=account_map.end(); ++it){
        output << *it->second;
        }
        output.close();
    }

    void output_report(const std::string& file){
      std::ofstream output(file);
        if(!output){
          std::cout << "failed to open output file";
          return;
        }
      for (std::map<std::string, account*>::iterator it=account_map.begin(); it!=account_map.end(); ++it){
        output << "Account Number: " << it->second->get_account_code() << " ";
        output << "Owner: " << std::setw(21) << std::left << it->second->get_name() << " ";
        output << "Type:" << std::setw(10) << std::left << it->second->print_type() << " ";
        output << "Balance: $" <<  std::fixed <<std::setprecision(2) << it->second->get_balance() << "\n";
        }
        output.close();

    }


    
   };
