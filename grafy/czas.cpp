#include "Czas.h"


using namespace std;
using namespace std::chrono;

void Czas::czasStart() {
	czasPoczatkowy = high_resolution_clock::now();
}

void Czas::czasStop() {
	czasKoncowy = high_resolution_clock::now();
}

long Czas::czasWykonania() {

	return long(duration_cast<std::chrono::microseconds>(Czas::czasKoncowy - Czas::czasPoczatkowy).count());

}