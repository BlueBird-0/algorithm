#include <Windows.h>
#include <iostream>
#include <thread>

using namespace std;
void threadFunction() {
	DWORD_PTR mask = 4;
	HANDLE thread = GetCurrentThread();
	SetThreadAffinityMask(thread, mask);

	while (true) {
		cout<<"hi"<<endl;
		//Sleep(1000);
	}
}

int main()
{
	thread t(threadFunction);
	t.join();
	return 0;
}