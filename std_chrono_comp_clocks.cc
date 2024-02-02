#include <iostream>
#include <thread>
#include <chrono>

int main(int argc,char *argv[]){
  std::chrono::system_clock::time_point          system_clock_start = std::chrono::system_clock::now();
  std::chrono::steady_clock::time_point          steady_clock_start = std::chrono::steady_clock::now();
  std::chrono::high_resolution_clock::time_point h_reso_clock_start = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds system_clock_start_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (system_clock_start.time_since_epoch());
  std::chrono::nanoseconds steady_clock_start_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (steady_clock_start.time_since_epoch());
  std::chrono::nanoseconds h_reso_clock_start_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (h_reso_clock_start.time_since_epoch());

  for (int i = 0; i < 100; i++) {
    std::chrono::system_clock::time_point          system_clock_now = std::chrono::system_clock::now();
    std::chrono::steady_clock::time_point          steady_clock_now = std::chrono::steady_clock::now();
    std::chrono::high_resolution_clock::time_point h_reso_clock_now = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds system_clock_now_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (system_clock_now.time_since_epoch());
    std::chrono::nanoseconds steady_clock_now_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (steady_clock_now.time_since_epoch());
    std::chrono::nanoseconds h_reso_clock_now_epoch = std::chrono::duration_cast<std::chrono::nanoseconds> (h_reso_clock_now.time_since_epoch());
    std::chrono::nanoseconds system_clock_duration  = std::chrono::duration_cast<std::chrono::nanoseconds> (system_clock_now - system_clock_start);
    std::chrono::nanoseconds steady_clock_duration  = std::chrono::duration_cast<std::chrono::nanoseconds> (steady_clock_now - steady_clock_start);
    std::chrono::nanoseconds h_reso_clock_duration  = std::chrono::duration_cast<std::chrono::nanoseconds> (h_reso_clock_now - h_reso_clock_start);
    

    std::time_t now = std::chrono::system_clock::to_time_t(system_clock_now);
    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::cout << "system_clock_now: " << s << std::endl;
    std::cout << "system_clock_now_epoch.count(): " << system_clock_now_epoch.count() << std::endl;
    std::cout << "steady_clock_now_epoch.count(): " << steady_clock_now_epoch.count() << std::endl;
    std::cout << "h_reso_clock_now_epoch.count(): " << h_reso_clock_now_epoch.count() << std::endl;
    std::cout << "system_clock_duration.count(): "  << system_clock_duration.count() << std::endl;
    std::cout << "steady_clock_duration.count(): "  << steady_clock_duration.count() << std::endl;
    std::cout << "h_reso_clock_duration.count(): "  << h_reso_clock_duration.count() << std::endl;
    std::cout << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
