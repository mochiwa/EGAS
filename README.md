# EGAS (ECI Generator Analyse for SGBD)
This application allows to generate random data for every type of DBMS where the file that used to create tables comes from JMerise.

## How to use:
When you run this application for the first time, three directories are created :
- input : where put files that comes from JMerise.
- tmp : here will be placed each table sliced (don't care about that).
- library: place here every file that EGAS will take to generate data as a list of names, a list of colors,etc.
- output: the directory where the SQL script done.

Your job is simple, just put your SQLFile generated by JMerise into the *Input* directory, fill the library with your data file and
run.

## Note About library file:
Two kinds of file can be here, The first is the *Type Table* and the second is *Common Table* . these files follow the same rules,
one data per line , but their behavior will change !

- Type Table:
If in your JMerise script you have a table looks like "one ID and one varchar" (just that) to describe a type, **name the library file
as your table name.** EGAS recognizes that and will generate a number of query equal to the number of lines to prevent to have two same types
with direfferent ID.

- Common Table:
For these , you have 2 choices :
  1. Name your files as your attributes and during the generation EGAS find the correct file for each attribute. 
      In the case where the file isn't found, then EGAS will ask you to select a file.
  2. Name your file how you want and EGAS will ask you what file do you want for each attribute. 
