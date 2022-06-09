#include <unistd.h>

int main(){
	write(1, "Seeping Now\n", 12);
	sleep(0.01);
	write(1, "Done\n", 12);
	return 0;
}