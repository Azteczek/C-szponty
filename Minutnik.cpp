#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


int main() {
    int time;
    cout << "Na ile sekund chcesz ustawić minutnik?: ";
    cin >> time;
    while (time > 0) {
        cout << "Poztostało: " << time << "s" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        time--;
 
    }
    cout << "Czas minął! \a" << endl;
    
    return 0;
}
