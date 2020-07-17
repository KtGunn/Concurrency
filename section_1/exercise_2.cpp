
#include "thread_guard.h"
#include <iostream>
#include <chrono>

void Clean () {
    std::cout << "Aye, aye, Sir. We're cleaning good\n";
    std::this_thread::sleep_for (std::chrono::milliseconds(5000));
    std::cout << "...Done cleaning\n";
    
}
void FullAhead () {
    std::cout << "Aye, aye, Sir. Full ahed it is\n";
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
    std::cout << "...Full ahead now\n";
}
void StopEngines () {
    std::cout << "Aye, aye, Sir. Stopping engines now is\n";
    std::this_thread::sleep_for (std::chrono::milliseconds(3000));
    std::cout << "...Engines full stop now \n";
}

int main () {

    std::thread clean_thread;
    std::thread fullahead_thread;
    std::thread stopengine_thread;

    while (true) {

	int code;
	std::cin >> code;

	if (code == 1) {
	    ////////////////////////////////////////////
	    /// 'cleaning'
	    //
	    clean_thread = std::thread (Clean);
	    clean_thread.detach();
	} else if (code == 2) {
	    ////////////////////////////////////////////
	    /// 'full ahead'
	    //
	    fullahead_thread = std::thread (FullAhead);
		
	} else if (code == 3) {
	    ////////////////////////////////////////////
	    /// 'stop engines'
	    //
	    stopengine_thread = std::thread (StopEngines);
	} else if (code == 100) {
	    break;
	} else {
	    std::cout << " Bad input, try again\n";
	}
	
	if ( fullahead_thread.joinable()) {
	    std::cout << " FullAhead : waiting for full ahead to finish\n";
	    fullahead_thread.join();
	}
	if ( stopengine_thread.joinable()) {
	    std::cout << " StopEngine : waiting for engines stop to finish\n";
	    stopengine_thread.join();
	}
    }

    std::cout << " Ship back in port \n";
    return (0);
}
