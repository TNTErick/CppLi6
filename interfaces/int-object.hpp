#pragma once
#ifndef __INTERFACE_OBJECT_
#define __INTERFACE_OBJECT_

namespace XyQZ {
namespace objectify {
struct intStruct {
public:
	int self;
	intStruct(int i) : self(i){
	}
	operator int(){
		return self;
	}
};


}
}

#endif//__INTERFACE_OBJECT_