#include <iostream>
#include <cmath>
#include <chrono>
#include <typeinfo>

int main(int argc,char *argv[]){


  std::chrono::system_clock::time_point  p_time_point;
  std::chrono::system_clock::duration    p_duration;
  std::chrono::system_clock::period      p_period;

  std::cout << "### Parameter definitions ###" << std::endl;
  std::cout << "std::chrono::system_clock::time_point  p_time_point;" << std::endl;
  std::cout << "std::chrono::system_clock::duration    p_duration;"   << std::endl;
  std::cout << "std::chrono::system_clock::period      p_period;"     << std::endl;
  std::cout << std::endl;
  std::cout << "### typeid().name() results ###" << std::endl;
  std::cout << "typeid(p_time_point).name(): " << typeid(p_time_point).name() << std::endl;
  std::cout << "typeid(p_duration  ).name(): " << typeid(p_duration  ).name() << std::endl;
  std::cout << "typeid(p_period    ).name(): " << typeid(p_period    ).name() << std::endl;
  
  std::cout << std::endl;
  std::cout << "### c++filt -t results ###" << std::endl;
  std::string cmd1 = std::string("c++filt -t ") + typeid(p_time_point).name();
  std::string cmd2 = std::string("c++filt -t ") + typeid(p_duration  ).name();
  std::string cmd3 = std::string("c++filt -t ") + typeid(p_period    ).name();
  std::cout << "c++filt -t typeid(p_time_point).name(): " << std::endl;
  system(cmd1.c_str());
  std::cout << "c++filt -t typeid(p_duration).name(): " << std::endl;
  system(cmd2.c_str());
  std::cout << "c++filt -t typeid(p_period).name(): " << std::endl;
  system(cmd3.c_str());

  std::cout << std::endl;
  std::cout << "### system_clock::period::num and den check ###" << std::endl;
  std::cout << "typeid(std::chrono::system_clock::period::num).name(): " << typeid(std::chrono::system_clock::period::num).name() << std::endl;
  std::cout << "typeid(std::chrono::system_clock::period::den).name(): " << typeid(std::chrono::system_clock::period::den).name() << std::endl;
  std::cout << "std::chrono::system_clock::period::num: " << std::chrono::system_clock::period::num << std::endl;
  std::cout << "std::chrono::system_clock::period::den: " << std::chrono::system_clock::period::den << std::endl;

  return 0;
}
