#include <iostream>
#include <thread>
#include <chrono>


void func_2 (int& ref_x) {

    while (true) {
	try {
	    std::cout << " func_2  ref_x=" << ref_x << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} catch (...) {
	    throw std::runtime_error ("Sum ding wong in func_2\n");
	}
    }
    return;
}
void func_1 () {

    int x = 5;
    std::thread thread_2 (func_2, std::ref(x));
    thread_2.detach ();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "func_1 thread has finished\n";

    return;
}

int main () {
    std::thread thread1(func_1);
    thread1.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::thread thread1a(func_1);
    thread1a.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    return (0);
}
