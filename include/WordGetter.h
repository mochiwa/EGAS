#ifndef __WORD_GETTER_H__
#define __WORD_GETTER_H__

#include <iostream>
#include <fstream>
#include <cstring>

#include "own_random.h"

class WordGetter
{
private:
    unsigned int count;
    std::fstream file;

public:

    /**
     * @brief      Constructs the object.
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    WordGetter();
    /**
     * @brief      Destroys the object.
     *
     * @note       free the file
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    ~WordGetter();

    /**
     * @brief      Opens a file.
     *
     * @param      filename  The filename
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    void openFile(std::string const& filename );

    /**
     * @brief      Counts the number of line.
     *
     * @note       counts the number of line in the file
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    void countLine();

    /**
     * @brief      get a word randomly selected in the file
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    std::string selectWord();

    /**
     * @brief      Sets the count line.
     *
     * @param[in]  count  The count
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    void setCountLine(unsigned int count);

    /**
     * @brief      Gets the count line.
     *
     * @return     The count line.
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    unsigned int getCountLine();

    /**
     * @brief      Gets a word.
     *
     * @return     The word.
     *
     * @note       { paragraph }
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    static std::string getWord(std::string const& filename);
    
    /**
     * @brief      Gets the maximum word in a file.
     *
     * @param      filename  The filename
     *
     * @return     The maximum word.
     *
     * @author     mochiwa
     * @date       11-Jan-2019
     */
    static int getMaxWord(std::string const& filename);
};

#endif