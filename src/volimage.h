#ifndef VOLIMAGE_H
#define VOLIMAGE_H

//Include statements
#include <fstream>
#include <vector>
#include <string>

//Default namespace
using namespace std;

//method declarations
namespace LVXJOR001
{
	bool readImages(string baseName);	
	void diffmap(int sliceI, int sliceJ, string output_prifix);
	void extract(intsliceId, string output_prefix);
	int volImageSize(void);
}
#endif
