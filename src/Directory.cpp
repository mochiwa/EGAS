#include "Directory.h"

using namespace std;


Directory::Directory()
{
    init();
}

Directory::Directory(string const& name)
{
    init();
    setDirName(name);
}

Directory::~Directory()
{
    closedir(dir);
}
//*******************************************************
//*******************  PRIVATE  *************************
//*******************************************************

void Directory::init()
{

    dir=nullptr;
    fileRead=nullptr;
    setDirName("");
    countFile=0;
}

void Directory::open()
{
    if(isOpen())
        throw ERROR_DIR_ALREADY_OPEN;
   
    dir=opendir(name.c_str());
    if(!isOpen())
    {
        if(ENOENT==errno)
            throw ERROR_DIR_NOT_EXIST;
        else
            throw ERROR_DIR_UNKNOW;
    }
}

void Directory::close()
{
    if(isOpen())
    {
        closedir(dir);
        dir=nullptr;
    }
}

void Directory::listFiles()
{
    if(isOpen())
    {
        files.clear();
        while((fileRead=readdir(dir)) != NULL)
            if(strcmp(fileRead->d_name,".") && strcmp(fileRead->d_name,".."))
            {
                files.push_back(fileRead->d_name);
                countFile++;
            }
    }
}

void Directory::mkdir()
{
    string str;
    if(name.length()<1)
        throw ERROR_DIR_NAME_LENGTH;

    str="mkdir "+getDirName();
    system(str.c_str());
}

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

void Directory::read()
{
    countFile=0;
    try
    {
        open();
        listFiles();
        close();
    }catch(int error)
    {
        if(error==ERROR_DIR_NOT_EXIST)
            mkdir();
        /*else if(error==ERROR_DIR_NAME_LENGTH)
            setDirName(tmpnam(nullptr)); // A tester*/
        read();
    }
}

void Directory::erase(string const& filename)
{
    remove((name+"/"+filename).c_str());
}

void Directory::eraseContent()
{
    for(auto filename:files)
        erase(filename);
    read();
}

bool Directory::isFileExist(string const& filename) const
{
    for(auto file:files)
        if(file == filename)
            return true;
    return false;
}

string const Directory::getFilePath(string const& filename) const
{
    for(auto file:files)
        if(file == filename)
            return name+"/"+filename;
    return "";
}

string const Directory::getFilePath(unsigned int index) const
{
    if(index<countFile)
        return name+"/"+files[index];
    else
        throw BAD_INDEX;
}

void Directory::printFiles() const
{
    unsigned int i=1;
    for(auto filename:files)
        cout<<i++<<") "<<filename<<endl;
}

string Directory::toString() const
{
    string str="";

    for(auto filename:files)
        str+="File: "+filename+"\n";
    return str;
}

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

bool Directory::isOpen() const
{
    if(dir==nullptr)
        return false;
    return true;
}

bool Directory::isEmpty() const
{
    if(countFile>0)
        return false;
    return true;
}

unsigned int Directory::getCountFile() const
{
    return countFile;
}

string const& Directory::getDirName() const
{
    return this->name;
}

string const& Directory::getFile(unsigned int index) const
{
    if(index<countFile)
        return files[index];
    else
        throw BAD_INDEX;
}

vector<string> const& Directory::getFiles() const
{
    return files;
}


void Directory::setDirName(string const& name)
{
    this->name=name;
}


//------------  OPERATORS  -----------//

Directory&  Directory::operator=(Directory const& src)
{
    if(&src==this)
        return (*this);
    init();
    setDirName(src.name);
    this->countFile=src.countFile;
    this->files=src.files;
    return *this;
}