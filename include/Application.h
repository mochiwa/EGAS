#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "Directory.h"
#include "own/own_input.h"
#include "SQLParser/ReaderFactory.h"
#include "SQLParser/MYSQLTableReader.h"
#include "SQLParser/Table.h"
#include "SQLParser/TableMaker.h"


#ifdef LINUX
    #define CLEAR() system("clear");
#else
    #define CLEAR() system("cls");
#endif


class Application
{
private:
    Directory inputdir; /** < Describe the directory where put the main SQLFile to read */
    Directory tmpdir; /** < Describe the directory where the application put the temp file */
    Directory outputdir; /** < Describe the directory where the application put the file */
    Directory library; /** < Describe the directory where the application take data to... */

    ReaderType readerType; /** < the type of SGBD used */ 

    

    /**
     * @brief      initialize variables of the Attribute
     *
     * @note       used by all constructor to initialize variables of the
     *             Attribute.
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void init();

    /**
     * @brief      Shows an elegant  title.
     *
     * @param      str   The string
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void showTitle(std::string const& str);

    /**
     * @brief      provides a menu to manage the tmpdir if is not empty
     *
     * @note       if the tmpdir , asks to the user what to do with the file
     *             into the dir (delete or compress ?)
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void tmpdirManagement();

    /**
     * @brief      slice a SQLFile into multiple table file
     *
     * @param      filepath  The filepath
     *
     * @note       open the file , recognize table and slice the file into mutli
     *             table
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void sliceSQLFile(std::string const& filepath);

    /**
     * @brief      show a menu to select a file in the input directory
     *
     * @return     the relative path with name of the file selected
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    std::string selectInputFile();

    /**
     * @brief     show a menu to select the tyep of SQL
     *
     * @return    the type
     *
     * @author     mochiwa
     * @date       17-Dec-2018
     */
    ReaderType selectSQLType();


public:

    /**
     * @brief      Constructs the object.
     *
     * @note       { paragraph }
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    Application();

    /**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    ~Application();
    

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************
    /**
     * @brief      Launch the EGAS
     *
     * @note       the main function of the application , must be called in the
     *             main
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void run();


    


    
//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************
};

#endif