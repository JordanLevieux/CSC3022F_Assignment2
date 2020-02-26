#include "volimage.h"

class VolImage
{
private:

	int width, height;
	vector<char**> slices;
	
public:

	VolImage()
	{
		width = 0;
		height = 0;
		//slices = new vector<char**>;
	}
	~VolImage()
	{
	}
	
	
	bool readImages(string baseName)
	{
		int num_images = 0;
		string temp;
		ifstream mri_data("MRI.data");
		getline(mri_data, temp, ' ');
		istringstream(temp) >> width;
		getline(mri_data, temp, ' ');
		istringstream(temp) >> height;
		getline(mri_data, temp);
		istringstream(temp) >> num_images;
		mri_data.close();
		
		long pos;
		//popluate the vector
		ifstream mriscans;
		for (int i=0;i<num_images;i++)
		{
			mriscans.open(baseName+to_string(i)+".raw", ios::in | ios::binary);
			pos = 0; //store position of get pointer
			//slices.emplace(new char[height][width]);
			
			for (int j=0;j<height;j++)
			{
				mriscans.seekg(pos);
				mriscans.read(slices[i][j], width);
				pos += width;
			}
		}
		return true;
	}
	
	void diffmap(int sliceI, int sliceJ, string output_prifix){}
	
	void extract(int sliceId, string output_prefix){}
	
	int volImageSize(void){return 0;}
	
};
