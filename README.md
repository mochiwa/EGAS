# EGAS (ECI Generator Analyse for SGBD)
This application allows to generate random data for every type of DBMS where the file that used to create tables comes from JMerise application.
From this :
```
CREATE TABLE public.cities(
	city_id     SERIAL NOT NULL ,
	city_name   VARCHAR (50) NOT NULL ,
	city_zip    VARCHAR (50) NOT NULL  ,
	CONSTRAINT cities_PK PRIMARY KEY (city_id)
)WITHOUT OIDS;
```
Generate something like this :
```
INSERT INTO cities(city_name,city_zip) VALUES ('bierge','1330');
INSERT INTO cities(city_name,city_zip) VALUES ('liege','1300');
INSERT INTO cities(city_name,city_zip) VALUES ('sering','4500');
INSERT INTO cities(city_name,city_zip) VALUES ('paris','2015');
INSERT INTO cities(city_name,city_zip) VALUES ('bruge','8888');
INSERT INTO cities(city_name,city_zip) VALUES ('cointe','2015');
```

## How to use:
When you run this application for the first time, three directories are created :
- input : where put files that comes from JMerise.
- tmp : here will be placed each table sliced (don't care about that).
- library: place here every file that EGAS will take to generate data as a list of names, a list of colors,etc.
- output: the directory where the SQL script done.

Your job is simple, just put your SQLFile generated by JMerise into the *Input* directory, fill the library with your data file and
run.
<br/>
![egas](https://user-images.githubusercontent.com/42714500/104151331-0a436980-53dd-11eb-976d-bb6630cdbb73.png)
<br/>
![Screenshot from 2021-01-11 07-16-12](https://user-images.githubusercontent.com/42714500/104151337-10d1e100-53dd-11eb-9455-6d1643e3ce6c.png)
<br/>
![Screenshot from 2021-01-11 07-16-53](https://user-images.githubusercontent.com/42714500/104151339-13343b00-53dd-11eb-89b8-e44ee9153492.png)
