#include "volimage.h"

class VolImage
{
private:

	int width, height;
	vector<unsigned char**> slices;
	
public:

	VolImage()
	{
		width = 0;
		height = 0;
		slices = new vector<usigned char**>;
	}
	~VolImage()
	{
		delete slices;
	}
	
	
	bool LVXJOR001::readImages(string baseName)
	{
		int numImages = 0;
		ifstream mri_data("MRI.data");
		getline(mri_data, width, ',');
		getline(mri_data, height, ',');
		getline(mri_data, numImages, ',');
		mri_data.close();
		
		for (int i=0,i<numImages,i++)
		{
			
		}
	}
	
	void LVXJOR001::diffmap(int sliceI, int sliceJ, string output_prifix){}
	
	void LVXJOR001::extract(intsliceId, string output_prefix){}
	
	int LVXJOR001::volImageSize(void){}
	
};
