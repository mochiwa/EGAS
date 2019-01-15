#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

#include <iostream>
#include <cstring>
#include <vector>
#include <dirent.h>

#include "own_input.h"

#define ERROR_DIR_NOT_EXIST 1
#define ERROR_DIR_UNKNOW 2
#define ERROR_DIR_ALREADY_OPEN 3
#define ERROR_DIR_NAME_LENGTH 4
#define BAD_INDEX 5

#ifdef LINUX
    #define CLEAR() system("clear");
#else
    #define CLEAR() system("cls");
#endif

/**
 * @brief      Class for directory.
 *
 * @note       this class describe a directory with some files.
 *              it's important to rembember that directory need to be
 *              read() before all operation !
 *             the user doesn't allow to make , open , close directory,
 *             this append in private .
 * @author     mochiwa
 * @date       12-Dec-2018
 */
class Directory
{
private:
    DIR* dir; /**<  the directory*/
    struct dirent *fileRead; /**< element of a directory (element of a list)*/

    std::string name; /**< the name of the directory*/
    std::vector<std::string> files; /**< list of file in the directory*/

    /**
     * @brief      initialize variables of the Attribute
     *
     * @note       used by all constructor to initialize variables of the
     *             Attribute.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void init();
 
    /**
     * @brief      Try to open the directory
     *
     * @note       The function tries to open the directory
     * @throws     ERROR_DIR_NOT_EXIST  if the directory not exist (ENOENT==errno)
     * @throws     ERROR_DIR_UNKNOW     other errors possible
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void open();

    /**
     * @brief      close the directory
     *
     * @note       close the directory ?? all files too ??
     *
     * @author     mochiwa
     * @date       12-Dec-2018
     */
    void close();

    /**
     * @brief      list all files in the directory
     *
     * @note       list all files present in the directory
     *
     * @author     mochiwa
     * @date       12-Dec-2018
     */
    void listFiles();

    /**
     * @brief      make a directory
     *
     * @note       use attribute @p name to create a directory
     * @TODO        Append check is dire already exist
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void mkdir() const;

public:

    /**
     * @brief      Constructs the object.
     *
     * @see        open()
     * 
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    Directory();

    /**
     * @brief      Constructs the object with a directory name.
     *
     * @param      name  The name of the directory
     *
     * @note       Construct the object and try to open the directory
     * @see        open()
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    Directory(std::string const& name);

    /**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     * 
     * @todo:   Ajout fermeture de tout les fichiers
     */
    ~Directory();

    //*******************************************************
    //********************  PUBLIC  *************************
    //*******************************************************

    /**
     * @brief      list all files in the directory
     *
     * @note       Open the directory, read the content and close it
     * @see        listFiles()
     * @todo :      check problem windows/linux
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void read();

    /**
     * @brief      erase the file
     *
     * @param      filename  The filename
     *
     * @note       erase the file where the filename provided match
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void erase(std::string const& filename) const;

    /**
     * @brief      erase everythings in the directory
     * @see        erase()
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    void eraseContent();

    /**
     * @brief      Determines if file exist.
     *
     * @param      filename  The filename
     *
     * @return     True if file exist, False otherwise.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    bool isFileExist(std::string const& filename) const;

    /**
     * @brief      Gets the relative file path (dirname/filename).
     *
     * @param      filename  The filename
     *
     * @return     The file  relative path.
     *
     * @author     mochiwa
     * @date       12-Dec-2018
     */
    std::string const getFilePath(std::string const& filename) const;

    /**
     * @brief      Gets the relative file path (dirname/filename).
     *
     * @param[in]  index  The index
     *
     * @return     The file path.
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    std::string const getFilePath(unsigned int index) const;

    /**
     * @brief      elegant print of all file
     *
     * @note       print all files in dir as: 1) file
     *                                        2) file2
     *                                        3) ....
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    void printFiles() const;

    /**
     * @brief      return the file with the path of the file
     *
     * @author     mochiwa
     * @date       10-Jan-2019
     */
    std::string selectFile();    

    /**
     * @brief      Returns a string representation of the object.
     *
     * @return     String representation of the object.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    std::string toString() const;

    /**
     * @brief      affectation overload
     *
     * @param      src   The source
     *
     * @return     *this
     *
     * @note       doesn't make copy but make a new object with similar
     *             attribute cause pointer
     *
     * @author     mochiwa
     * @date       11-Dec-2018
     */
    Directory& operator=(Directory const& src);

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

    /**
     * @brief      Determines if the directory is open.
     *
     * @return     True if open, False otherwise.
     *
     * @author     mochiwa
     * @date       12-Dec-2018
     */
    bool isOpen() const;

    /**
     * @brief      Determines if empty.
     *
     * @return     True if empty, False otherwise.
     *
     * @author     mochiwa
     * @date       14-Dec-2018
     */
    bool isEmpty() const;

     /**
     * @brief      Gets count of file in directory .
     *
     * @return     The count of file.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    unsigned int getCountFile() const;

    /**
     * @brief      Gets the dir name.
     *
     * @return     The dir name.
     *
     * @author     mochiwa
     * @date       11-Dec-2018
     */
    std::string const& getName() const;

    /**
     * @brief      Gets the file.
     *
     * @param[in]  index  The index
     * @param[in]  position  The position
     *
     * @return     The file.
     * @throws     BAD_INDEX  if the index provided is bigger than countFile
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    std::string const& getFile(unsigned int index) const;

    /**
     * @brief      Gets the files.
     *
     * @return     The files.
     *
     * @author     mochiwa
     * @date       10-Dec-2018
     */
    std::vector<std::string> const& getFiles() const;

    /**
     * @brief      Sets the dir name.
     *
     * @param      filename  The filename
     *
     * @author     mochiwa
     * @date       11-Dec-2018
     */
    void setName(std::string const& filename);

};


#endif