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
		cout<<"Number of images: "<<num_images<<"\nNumber of bytes required: "<<(num_images*height*width)<<endl;
		
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
				//cout<<pos<<",";
			}
			mriscans.close();
		}
		return true;
	}
	
	//Write slice to output.raw
	void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix)
	{
		ofstream outFile(output_prefix+".raw");
		for (int i=0; i<height; i++)
		{
			for (int j=0; j<width; j++)
			{
				outFile<<(unsigned char)(abs((float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j])/2);
			}
		}
		outFile.close();
	}
	
	void VolImage::extract(int sliceId, string output_prefix)
	{
		ofstream outFile(output_prefix+".raw");
		for (int i=0; i<height; i++)
		{
			for (int j=0; j<width; j++)
			{
				outFile<<slices[sliceId][i][j];
			}
		}
		outFile.close();
	}
	
	int VolImage::volImageSize(void){return 0;}
	

