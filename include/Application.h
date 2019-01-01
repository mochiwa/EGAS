#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "Directory.h"
#include "own/own_input.h"
#include "ReaderFactory.h"
#include "MYSQLTableReader.h"
#include "SQLWriter.h"
#include "Table.h"
#include "TableMaker.h"
#include "CleverGenerator.h"


#ifdef LINUX
    #define CLEAR() system("clear");
#else
    #define CLEAR() system("cls");
#endif

typedef std::pair<std::string,int> reference;


class Application
{
private:
    Directory inputdir; /** < Describe the directory where put the main SQLFile to read */
    Directory tmpdir; /** < Describe the directory where the application put the temp file */
    Directory outputdir; /** < Describe the directory where the application put the file */
    Directory library; /** < Describe the directory where the application take data to... */

    ReaderType readerType; /** < the type of SGBD used */
    TableReader *reader; /** < The reader that read a SQLFile (Abstract)*/
    SQLWriter writer; /** < The writer that write SQLFile*/

    std::vector<Table> tables; /** < List of tables in the worked file */
    std::map<std::string,int> tablereferences; /** < a map of table name and count line */

    CleverGenerator clever; /** < Object respive to detect what kind of data generate*/
    

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
    void showTitle(std::string const& str) const;

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
     * @brief      Arrange tables that have foreign key
     *
     * @param[in]  current      The current
     * @param[in]  foreignKeys  The foreign keys
     *
     * @return     0 if current table is moved , the current pos else
     *
     * @note       if the current table moves then all vector have to check .
     *
     * @author     mochiwa
     * @date       01-Jan-2019
     */
    int ArrangeForeignTable(int current,std::map<std::string,std::string> const& foreignKeys );

    /**
     * @brief      swap table at posA to posB
     *
     * @param[in]  posA  The position a
     * @param[in]  posB  The position b
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    void swapTable(int posA,int posB); 

    /**
     * @brief      sort tables
     *
     * @note       this function sort the tables with
     *              the foreign relations, tables without foreign
     *              are at first.
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    void sortTable();

    /**
     * @brief      Loads tables.
     *
     * @param      reader  The Table reader
     *
     * @note       Run through files into the tmpdir and load all tables into the Tables vector
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void loadTables();

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
     * @brief     show a menu to select the type of SQL
     *
     * @return    the type
     *
     * @author     mochiwa
     * @date       17-Dec-2018
     */
    ReaderType selectSQLType() const;

    /**
     * @brief      show a menu to select the table 
     *
     * @return     the table to work
     *
     * @note       show all table name and ask to select one
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    Table const& selectTable() const;

    /**
     * @brief      generate all Lines to write
     *
     * @note       Run through every table to generate line
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void generateLines();

    void cleverGeneration(Attribute const& att);

    void automaticGeneration(Table const& table,int i);

    /**
     * @brief      Appends a table reference.
     *
     * @param      table  The table
     * @param[in]  count  The count
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void appendTableReference(std::string const& table,int count);



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