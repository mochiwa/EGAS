#ifndef __SGBD_TYPE_H__
#define __SGBD_TYPE_H__

#include <iostream>

enum SGBDType {MYSQL,ORACLE,POSTGRES,LAST};


std::ostream& operator<<(std::ostream& stream,SGBDType const type);

#endif