#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void childFunction(int id) {
    cout << "Child: " << id << " ID: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

int main() {
    vector<thread> threads;

    for(int i = 1; i <5; i++) {
        threads.push_back(thread(childFunction, i));
    }
    
    for(auto& j : threads) {
        j.join();
    }
    

    return 0;
}