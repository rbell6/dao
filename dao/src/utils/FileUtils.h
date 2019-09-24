//
//  fileutils.h
//  dao
//
//  Created by Richard Bell on 11/24/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef fileutils_h
#define fileutils_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace dao {
	class FileUtils {
	public:
		static string read(string filename) {
            cout << "filename: " << filename << endl;
			FILE* file = fopen(filename.c_str(), "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);
			string result(data);
			delete [] data;
			return result;
		}
		
		static string readSlow(string filename) {
			ifstream file(filename.c_str());
			string s((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			return s;
		}
	};
}

#endif /* fileutils_h */
