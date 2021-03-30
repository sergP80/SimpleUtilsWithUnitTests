#include "bitops.h"

bool f1();
bool f2();

int main()
{
	//int a = 11;
	//int b = 57;

	//int &ra = a;
	//int &rb = b;

	//cout << dec << a << endl;
	//cout << hex << a << endl;

	//cout << dec << b << endl;
	//cout << hex << b << endl;

	//cout << bitset<8>(a) << endl;
	//cout << bitset<8>(b) << endl;

	//cout << "===== & ======" << endl;
	//cout << dec << (a & b) << endl;
	//cout << bitset<8>(a & b) << endl;

	//cout << "==== | ======" << endl;
	//cout << (a | b) << endl;
	//cout << bitset<8>(a | b) << endl;

	//cout << "===== ^ ======" << endl;
	//cout << (a ^ b) << endl;
	//cout << bitset<8>(a ^ b) << endl;

	//cout << "===== ~a ======" << endl;
	//cout << (~a) << endl;
	//cout << bitset<8>(~a) << endl;

	//cout << "===== ~b ======" << endl;
	//cout << (~b) << endl;
	//cout << bitset<8>(~b) << endl;

	//cout << (a & b | ~b) << endl;
	//cout << bitset<8>(a & b | ~b) << endl;

	//cout << "===== << ======" << endl;

	//
	//cout << bitset<16>(a) << endl;
	//cout << (a << 3) << endl;//a << n = a * 2^n
	//cout << bitset<16>((a << 3)) << endl;

	//cout << "===== >> ======" << endl;
	//cout << bitset<16>(b) << endl;
	//cout << (b >> 1) << endl;
	//cout << bitset<16>((b >> 1)) << endl;

	//cout << "===== ~ >> ======" << endl;
	//cout << dec << (~b) << endl;
	//cout << bitset<16>(~b) << endl;
	//cout << (~b >> 1) << endl;
	//cout << bitset<16>((~b >> 1)) << endl;

	//cout << "+++++" << endl;

	//unsigned int c = ~b;

	//cout << dec << c << endl;
	//cout << bitset<16>(c) << endl;
	//cout << dec << (c >> 1) << endl;
	//cout << bitset<16>(c >> 1) << endl;


	//cout << boolalpha <<  (bool)(f1() & f2()) << endl;
	cout << boolalpha << (bool)(f1() | f2()) << endl;
	
	//cout << boolalpha << (f1() && f2()) << endl;
	cout << boolalpha << (f1() || f2()) << endl;

	return 0;
}


bool f1() {
	cout << "f1" << endl;
	return true;
}

bool f2() {
	cout << "f2" << endl;
	return false;
}