#include <iostream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
int main() {
	int at = 1;
	int choice = 1;
	while(at==1){
		if (choice == 1) PlaySound(TEXT("C:\\Users\\ADMIN\\Downloads\\01.-Main-Menu"), NULL, SND_LOOP | SND_ASYNC); else PlaySound(NULL, NULL, SND_ASYNC);
		if (choice == 1) { cout << "nhac dang bat, nhap 0 de tat nhac";cin >> choice; }
		else { cout << "Nhac dang tat, nhap 1 de bat nhac";cin >> choice; }
		
	}return 0;
}