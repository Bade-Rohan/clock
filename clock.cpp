#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
using std::cout;
using std::endl;
class Clock{
	private:
		short seconds,minutes,hours;
	public:
		Clock(){
			seconds=0;
			minutes=0;
			hours=0;
		}
		Clock(short sec,short min,short hr){
			seconds=sec;
			minutes=min;
			hours=hr;
		}
		void display(){
				cout<<std::setw(2)<<hours<<std::setw(0)<<":";
				cout<<std::setw(2)<<minutes<<std::setw(0)<<":";
				cout<<std::setw(2)<<seconds<<std::setw(0)<<std::flush;
		}
		void display_time(){
			this->display();
			cout << "\x1B[2J\x1B[H";
			while(true){
				using namespace std::literals::chrono_literals;
				cout << "\x1B[2J\x1B[H";
				if(seconds<59){
					std::this_thread::sleep_for(1s);
					seconds++;
					this->display();
				}
				else{
					std::this_thread::sleep_for(1s);
					seconds=0;
					if(minutes<59){
						minutes++;
						this->display();
					}
					else{
						minutes=0;
						if(hours<23){
							hours++;
							this->display();
						}
						else{
							hours=0;
							this->display();
						}
					}


				}
				
					
			}	

		}
};
int main(){
	Clock a(50,59,23);
	a.display_time();
	return 0;
}
