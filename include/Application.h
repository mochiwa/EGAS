#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>

#include "own_input.h"

#include "Directory.h"
#include "WordGetter.h"


#include "ReaderFactory.h"
#include "WriterFactory.h"
#include "TypeDetectorFactory.h"

#include "SGBDType.h"
#include "TypeDetector.h"

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
typedef std::pair<Attribute const*,std::string> att_file;
typedef std::pair<int,int> uniqueRelation;

class Application
{
private:
    Directory inputdir; /** < Describe the directory where put the main SQLFile to read */
    Directory tmpdir; /** < Describe the directory where the application put the temp file */
    Directory outputdir; /** < Describe the directory where the application put the file */
    Directory library; /** < Describe the directory where the application take data to... */

    SGBDType sgbd; /** < the type of SGBD used */
    TableReader *reader; /** < The reader that read a SQLFile (Abstract)*/
    SQLWriter *writer; /** < The writer that write SQLFile*/
    TypeDetector * typeDetector; /** < The detector that detecte which type of attribute */
    CleverGenerator clever; /** < Object respive to detect what kind of data generate*/


    std::vector<Table> tables; /** < List of tables in the worked file */
    std::map<std::string,int> tableReferences; /** < a map of table name and count line */
    std::map<Attribute const*,std::string> attributeFiles; /** a map where varchar attribute use file */
    std::vector<uniqueRelation> uniqueRelations; /** */
    

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
     * @brief      show a menu to select a file in the input directory
     *
     * @return     the relative path with name of the file selected
     *
     * @author     mochiwa
     * @date       09-Jan-2019
     */
    std::string selectLibraryFile();

    /**
     * @brief     show a menu to select the type of SQL
     *
     * @return    the type
     *
     * @author     mochiwa
     * @date       17-Dec-2018
     */
    SGBDType selectSQLType() const;

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


    /**
     * @brief      Write a data according by type
     *
     * @param      att   The att
     *
     * @note       ask to TypeDector the type and ask the CleverGenerator to generate according its
     *
     * @author     mochiwa
     * @date       05-Jan-2019
     */
    void cleverGeneration(Attribute const& att);

    /**
     * @brief      Generate data from existing file
     *
     * @param      att   The att
     *
     * @author     mochiwa
     * @date       23-Jan-2019
     */
    void existingGeneration(Attribute const& att);


    /**
     * @brief      detecte what will be generated
     *
     * @param      table  The table
     * @param[in]  id      the id
     *
     * @note       detecte if the attribute is primary,foreign , both or other
     *              and set the best way to generate data
     *
     * @author     mochiwa
     * @date       05-Jan-2019
     */
    void automaticGeneration(Table const& table,int id);

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

    /**
     * @brief      Appends an <attribute, file>. into the map
     *
     * @param      att   The att
     * @param      file  The file
     * @param      att   The att
     *
     * @author     mochiwa
     * @date       09-Jan-2019
     */
    void appendAttributeFile(Attribute const& att,std::string const& file);

    /**
     * @brief      Shows the attribute files.
     *
     * @param      table  The table
     *
     * @author     mochiwa
     * @date       09-Jan-2019
     */
    void showAttributeFiles(Table const& table);

    /**
     * @brief      fill the list of files for attribute
     *
     * @param      table  The table
     *
     * @note       run through the table to find varchar attribute
     *              ans ask to the user which file link to the attribute
     *
     * @author     mochiwa
     * @date       09-Jan-2019
     */
    void fillAttributeFiles(Table const& table);

    /**
     * @brief      reduce the count of line for relation table
     *
     * @param[in]  countLines  The count lines
     * @param[in]  max         The maximum
     *
     * @return     a number less than 3 * max
     *
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    unsigned int reduceRelationCount(unsigned int countLines,int max);

    /**
     * @brief      initialize the parameters of table that type is Type
     *
     * @note       auto define the max line will generated and the file where take word
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    void initTypeTable(Table const& table);

    /**
     * @brief      initialize the parameters of table that type is Relation
     *
     * @param      table     The table
     * @param[in]  maxLines  The maximum lines
     *
     * @note       auto define the max line will be generated ;
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    void initRelationTable(Table const& table,unsigned int maxLines);

    /**
     * @brief      initialize the parameters of table that type is Normal
     *
     * @param      table  The table
     * @param[in]  lines  The lines
     *
     * @note       auto define the max line will be generated and ask user the
     *             file
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    void initTable(Table const& table,unsigned int lines);

    /**
     * @brief      Gets a unique relation.
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    uniqueRelation getUniqueRelation(Table const& table);

    /**
     * @brief      {check if unique relation already exist
     *
     * @param[in]  r   the relation
     *
     * @author     mochiwa
     * @date       23-Jan-2019
     */
    bool alreadyCreate(uniqueRelation r);

    /**
     * @brief      Determines if it has attribute.
     *
     * @param      att   The att
     *
     * @return     True if AttributeFile has, False otherwise.
     *
     * @author     mochiwa
     * @date       23-Jan-2019
     */
    bool hasAttribute(Attribute const* att);
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

bool operator==(uniqueRelation a,uniqueRelation b);

#endif