//
//  ImageUtils.h
//  dao
//
//  Created by Richard Bell on 11/29/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef ImageUtils_h
#define ImageUtils_h
#include <string>
//#include <FreeImage.h>
using namespace std;

namespace dao {
	class ImageUtils {
	public:
		static BYTE* loadImage(const char* filename, GLsizei& width, GLsizei& height) {
			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
			FIBITMAP *dib{nullptr};
			fif = FreeImage_GetFileType(filename, 0);
			if(fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename);
			if(fif == FIF_UNKNOWN)
				return nullptr;
			
			if(FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename);
			if(!dib)
				return nullptr;
			
			//retrieve the image data
			BYTE* data = FreeImage_GetBits(dib);
			width = FreeImage_GetWidth(dib);
			height = FreeImage_GetHeight(dib);
			return data;
		}
	};
}

#endif /* ImageUtils_h */
