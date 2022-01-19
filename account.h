#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//namespace account{
class account{
  protected:
  std::string account_code;
  std::string first_name;
  std::string last_name;
  double balance;
  std::string type;

  public:
  account(const std::string ac, const std::string& fn, const std::string& ln, double bal, std::string t):
  account_code(ac),
  first_name(fn),
  last_name(ln),
  balance(bal),
  type(t)
  {}

  account() = default;
  
  double get_balance(){
    return balance;
  }
  std::string get_account_code(){
    return account_code;
  }

  std::string get_name(){
    return first_name + " " + last_name;
  }

  void change_balance(double new_balance){
  balance = new_balance;
  }

void output(std::ostream& s)const{
    s <<  std::setfill(' ') << account_code << std::setw(15) << std::left << first_name << std::setw(25) << std::left << last_name;
    s << type;
    s <<  std::fixed <<std::setprecision(2) << std::setw(11) << std::right << std::setfill('0') << balance << "\n";
  }



  friend std::ostream& operator<<(std::ostream& s, const account& a) {
      a.output(s);
      return s;
  }

  void print_account(){
    std::cout << account_code << "," << first_name << "," << last_name << "," << balance << "\n";
  }



  virtual void monthly_update() = 0;
  virtual char type1() = 0;
  virtual std::string print_type()= 0;


};

class simple_account : public account{

  public:
  simple_account(const std::string ac, const std::string& fn, const std::string& ln, double bal, std::string t):
  account(ac, fn, ln, bal, t)
  {}
  
  void monthly_update(){
    double change = get_balance();
    change *= 1.05;
    change_balance(change);
  }

  char type1(){
    return 'A';
  }

  std::string print_type(){
    return "Simple";
  }

};

class bonus_account : public account{

  public:
  bonus_account(const std::string ac, const std::string& fn, const std::string& ln, double bal, std::string t):
  account(ac, fn, ln, bal, t)
  {}
  
  void monthly_update(){
    double change = get_balance();
    change = change * (change > 5000 ? 1.06 : 1.04);
    change_balance(change);
  }

  char type1(){
    return 'B';
  }

  std::string print_type(){
    return "Bonus";
  }

};

class service_account : public account{

  public:
  service_account(const std::string ac, const std::string& fn, const std::string& ln, double bal, std::string t):
  account(ac, fn, ln, bal, t)
  {}
  
  void monthly_update(){
    double change = get_balance();
    change  = (change - 5.0) * 1.04;
    change_balance(change);
  }

  char type1(){
    return 'C';
  }

  std::string print_type(){
    return "Service";
  }

};

class balanced_account : public account{

  public:
  balanced_account(const std::string ac, const std::string& fn, const std::string& ln, double bal, std::string t):
  account(ac, fn, ln, bal, t)
  {}
  
  void monthly_update(){
    double change = get_balance();
    change = change > 500.0 ? change * 1.05 : (change - 5.0) * 1.03;
    change_balance(change);
  }

  char type1(){
    return 'D';
  }

  std::string print_type(){
    return "Balanced";
  }

};