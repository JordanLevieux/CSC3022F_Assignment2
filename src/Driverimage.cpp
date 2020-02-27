#include "Driverimage.h"
#include "volimage.h"

int main()
{
	cout<<"hello"<<endl;
	VolImage v = *(new VolImage());
	v.readImages("MRI");
	return 0;
}
