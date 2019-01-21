#ifndef __TYPE_DETECTOR_FACTORY_H__
#define __TYPE_DETECTOR_FACTORY_H__

#include <iostream>

#include "SGBDType.h"
#include "TypeDetector.h"
#include "MYSQLTypeDetector.h"
#include "OracleTypeDetector.h"
#include "PostgresTypeDetector.h"

class TypeDetectorFactory
{
public:

    /**
     * @brief      Gets the type detector.
     *
     * @param[in]  type  The type
     *
     * @return     The type detector.
     *
     * @author     mochiwa
     * @date       05-Jan-2019
     */
    static TypeDetector * getDetector(SGBDType const type);
    
};

#endif