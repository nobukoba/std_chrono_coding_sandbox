#include <iostream>
#include <cmath>
#include <chrono>
#include <typeinfo>

int main(int argc,char *argv[]){
  std::cout << "here" << std::endl;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    for ( long i = 0; i < 100000000; ++i ) {
      sqrt( 123.456L );
    }

    std::cout << "typeid(start).name(): " << typeid(start).name() << std::endl;
    std::string cmd = std::string("c++filt -t ") + typeid(start).name();
    system(cmd.c_str());
    
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << "took " << sec.count() << " seconds\n";

    auto start2 = std::chrono::high_resolution_clock::now();

    for ( long i = 0; i < 100000000; ++i ) {
      sqrt( 123.456L );
    }

    auto  end2 = std::chrono::high_resolution_clock::now();
    std::cout << "typeid(start2).name(): " << typeid(start2).name() << std::endl;

    typedef std::chrono::nanoseconds ns;
    ns d = std::chrono::duration_cast<ns>(end2 - start2);

    // d now holds the number of milliseconds from start to end.

    std::cout << d.count() << "ns\n";
 
    return 0;
}
