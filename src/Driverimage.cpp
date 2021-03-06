#include "Driverimage.h"
#include "volimage.h"

int main(int argc, char** argv)
{
	string base_name;
	string slice1;
	string slice2;
	if (argc<2){cout<<"Invalid input"<<endl;return 1;}
	
	VolImage v = *(new VolImage());
	base_name = string(argv[1]);
	v.readImages(base_name);
	if (argc==5)
	{
		if(string(argv[2])!="-x"){cout<<"Incorrect input"<<endl;
		return 1;}
		v.extract(atoi(argv[3]),argv[4]);
		cout<<"Slice "<<argv[3]<<" extracted to file "<<argv[4]<<".raw\n";
	}
	else if(argc==6)
	{
		if(string(argv[2])!="-d"){cout<<"Incorrect input"<<endl;
		return 1;}
		v.diffmap(atoi(argv[3]),atoi(argv[4]),argv[5]);
		cout<<"Diffmap of slices "<<argv[3]<<" and "<<argv[4]<<" sent to file "<<argv[5]<<".raw\n";
	}
	return 0;
}
