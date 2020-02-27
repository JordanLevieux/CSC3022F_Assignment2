#include "volimage.h"
VolImage::VolImage()
	{
		width = 0;
		height = 0;
		num_images = 0;
	}
	VolImage::~VolImage()
	{
		for (int i=0;i<num_images;i++)
		{
			for (int j=0;j<height;j++)
			{
				delete[] slices[i][j];
			}
			delete[] slices[i];
		}
	}
	
	
	bool VolImage::readImages(string baseName)
	{
		//Get the dimensions and number of files to create 3D image
		string temp;
		ifstream mri_data("raws/"+baseName+".data");
		if (!mri_data) {cerr<<"Could not open data file"<<endl;return false;}
		getline(mri_data, temp, ' ');
		istringstream(temp) >> width;
		getline(mri_data, temp, ' ');
		istringstream(temp) >> height;
		getline(mri_data, temp);
		istringstream(temp) >> num_images;
		mri_data.close();
		cout<<"width: "<<width<<"\nheight: "<<height<<"\nnum images: "<<num_images<<endl;
		
		//Populate the vector with raw data from scans
		ifstream mriscans;
		long pos;
		for (int i=0;i<num_images;i++)
		{
			//Open raw files
			mriscans.open("raws/"+baseName+to_string(i)+".raw", ios::in | ios::binary);
			if (!mriscans) {cerr<<"Could not open file "<<baseName<<to_string(i)<<".raw"<<endl;return false;}
			
			pos = 0; //store position of get pointer
			slices.emplace_back(new char*[height]);
			
			//Create arrays to hold data and add it to the vector
			for (int j=0;j<height;j++)
			{
				slices[i][j] = new char[width];
				mriscans.seekg(pos);
				mriscans.read(slices[i][j], width);
				pos += width;
			}
			mriscans.close();
		}
		return true;
	}
	
	void VolImage::diffmap(int sliceI, int sliceJ, string output_prifix){}
	
	void VolImage::extract(int sliceId, string output_prefix){}
	
	int VolImage::volImageSize(void){return 0;}
	

