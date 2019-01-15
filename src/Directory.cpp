#include "Directory.h"

using namespace std;


Directory::Directory()
{
    init();
}

Directory::Directory(string const& name)
{
    init();
    setName(name);
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
    setName("");
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
        closedir(dir);
    dir=nullptr;
}

void Directory::listFiles()
{
    files.clear();
    while((fileRead=readdir(dir)) != NULL)
        if(strcmp(fileRead->d_name,".") && strcmp(fileRead->d_name,".."))
            files.push_back(fileRead->d_name);
}

void Directory::mkdir() const
{
    string str;
    if(name.length()<1)
        throw ERROR_DIR_NAME_LENGTH;

    str="mkdir "+getName();
    system(str.c_str());
}

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

void Directory::read()
{
    try
    {
        open();
        listFiles();
        close();
    }catch(int error)
    {
        if(error==ERROR_DIR_NOT_EXIST)
            mkdir();
        if(error==ERROR_DIR_ALREADY_OPEN)
            close();
        read();
    }
}

void Directory::erase(string const& filename) const
{
    remove((name+"/"+filename).c_str());
}

void Directory::eraseContent()
{
    for(string const& file:files)
        erase(file);
    read();
}

bool Directory::isFileExist(string const& filename) const
{
    for(string const& file:files)
        if(!file.compare(filename))
            return true;
    return false;
}

string const Directory::getFilePath(string const& filename) const
{
    for(string const& file:files)
        if(!file.compare(filename))
            return name+"/"+filename;
    return "";
}

string const Directory::getFilePath(unsigned int index) const
{
    return name+"/"+files.at(index);
}

void Directory::printFiles() const
{
    unsigned int i=1;
    for(string const& file:files)
        cout<<i++<<") "<<file<<endl;
}

string Directory::selectFile()
{
    unsigned int selected=-1;

    while(selected>=getCountFile())
    {
        CLEAR();
        cout<<"##############################"<<endl;
        cout<<"        "<<name<<endl;
        cout<<"##############################"<<endl;

        printFiles();
        if(isEmpty())
        {
            cout<<"Your input directory is empty, insert files into and press Return"<<endl;
            own::proceed();
            read();
        }
        else
            selected=own::readInteger("Select: ")-1;
    }
    return getFilePath(selected);
}

string Directory::toString() const
{
    string str="";
    str+="Directory: "+getName()+"\n";
    for(string const& file:files)
        str+="-File: "+file+"\n";
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
    if(getCountFile()>0)
        return false;
    return true;
}

unsigned int Directory::getCountFile() const
{
    return files.size();
}

string const& Directory::getName() const
{
    return this->name;
}

string const& Directory::getFile(unsigned int index) const
{
    return files.at(index);
}

vector<string> const& Directory::getFiles() const
{
    return files;
}

void Directory::setName(string const& name)
{
    this->name=name;
}


//------------  OPERATORS  -----------//

Directory&  Directory::operator=(Directory const& src)
{
    if(&src==this)
        return (*this);
    init();
    setName(src.name);
    this->files=src.files;
    return *this;
}