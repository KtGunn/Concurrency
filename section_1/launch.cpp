

#include <iostream>
#include <thread>


void foo() {
    std::cout << "Hello from foo\n";
}

class CCallable {
 public:
    void operator ()() {
	std::cout << "Hello from class CCallable \n";
    }
};

void run () {

    std::thread thread1(foo);
    CCallable callie;
    
    std::thread thread2(callie);
    
    std::thread thread3([] {
	    std::cout << "Hello from Lambda id=" << std::this_thread::get_id() << std::endl;
	    
	});
    
    thread1.join();
    thread2.join();
    thread3.join();

    return;
}



int main () {
    run ();
    return 1;
}
