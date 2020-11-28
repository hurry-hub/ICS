#include<stdio.h>

int checkendian(){
	typedef union {
	int a;
	char b;
	}my;
	my t;
	t.a = 1;
	return (t.b == 1);
}

int main(){
	printf("%d\n", checkendian());
	return 0;

}
