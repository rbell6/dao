//
//  Timer.h
//  dao
//
//  Created by Richard Bell on 11/26/18.
//  Copyright © 2018 apocryphal. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#include <chrono>
using namespace std;

namespace dao {
	class Timer {
		chrono::high_resolution_clock::time_point mStart;
	public:
		Timer() {
			mStart = chrono::high_resolution_clock::now();
		}
		
		void reset() {
			mStart = chrono::high_resolution_clock::now();
		}
		
		chrono::milliseconds elapsed() {
			auto current = chrono::high_resolution_clock::now();
			auto diff = chrono::duration_cast<chrono::milliseconds>(current - mStart);
			return diff;
		}
	};

}

#endif /* Timer_h */
