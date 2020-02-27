#ifndef VOLIMAGE_H
#define VOLIMAGE_H

//Include statements
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

//Default namespace
using namespace std;
class VolImage
{
	private:
	
	int width, height;
	int num_images;
	
	std::vector<char**>slices;
	
	public:
	
	VolImage();
	~VolImage();
	bool readImages(std::string baseName);
	void diffmap(int sliceI,int sliceJ,std::string output_prefix);
	void extract(int sliceId, std::string output_prefix);
	int volImageSize(void);
};
class VolImage;

//method declarations
namespace LVXJOR001
{
	bool readImages(string baseName);	
	void diffmap(int sliceI, int sliceJ, string output_prifix);
	void extract(int sliceId, string output_prefix);
	int volImageSize();
}
#endif
