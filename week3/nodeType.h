//*************************************************************
// Author: Quang Ly Ho
// 
//*************************************************************
#pragma once

#include <iostream>

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link;
};