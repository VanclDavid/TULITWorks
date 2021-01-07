-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2021-01-07 18:04:52.777

-- tables
-- Table: Cities
CREATE TABLE Cities (
    id int  NOT NULL,
    name varchar(20)  NOT NULL,
    PSC int  NOT NULL,
    population int  NOT NULL,
    CONSTRAINT Cities_pk PRIMARY KEY  (id)
);

-- Table: Doctor_fields
CREATE TABLE Doctor_fields (
    id int  NOT NULL,
    field varchar(25)  NOT NULL,
    CONSTRAINT Doctor_fields_pk PRIMARY KEY  (id)
);

-- Table: Doctors
CREATE TABLE Doctors (
    id int  NOT NULL,
    id_hospital int  NULL,
    id_people int  NOT NULL,
    id_Doctor_fields int  NULL,
    CONSTRAINT Doctors_pk PRIMARY KEY  (id)
);

-- Table: Doctors_People_tab
CREATE TABLE Doctors_People_tab (
    id_Doctors int  NOT NULL,
    id_People int  NOT NULL,
    CONSTRAINT Doctors_People_tab_pk PRIMARY KEY  (id_Doctors,id_People)
);

-- Table: Hospitals
CREATE TABLE Hospitals (
    id int  NOT NULL,
    name varchar(50)  NOT NULL,
    owner varchar(20)  NOT NULL,
    id_city int  NOT NULL,
    CONSTRAINT Hospitals_pk PRIMARY KEY  (id)
);

-- Table: Medicaments
CREATE TABLE Medicaments (
    id int  NOT NULL,
    name varchar(50)  NOT NULL,
    type varchar(20)  NOT NULL,
    CONSTRAINT Medicaments_pk PRIMARY KEY  (id)
);

-- Table: People
CREATE TABLE People (
    id int  NOT NULL,
    firstname varchar(50)  NOT NULL,
    surname varchar(50)  NOT NULL,
    gender char(1)  NULL,
    birth date  NOT NULL,
    phone varchar(20)  NULL,
    CONSTRAINT People_pk PRIMARY KEY  (id)
);

-- Table: Pharmacies
CREATE TABLE Pharmacies (
    id int  NOT NULL,
    name varchar(50)  NOT NULL,
    id_city int  NOT NULL,
    gps varchar(20)  NOT NULL,
    CONSTRAINT GPS_UNIQUE UNIQUE (gps),
    CONSTRAINT Pharmacies_pk PRIMARY KEY  (id)
);

-- Table: Recipes
CREATE TABLE Recipes (
    id int  NOT NULL,
    code int  NOT NULL,
    id_user int  NOT NULL,
    id_doctor int  NOT NULL,
    id_medicament int  NOT NULL,
    id_pharmacy int  NULL,
    publication_date datetime  NOT NULL,
    pick_up_date datetime  NULL,
    description varchar(100)  NULL,
    CONSTRAINT Recipes_pk PRIMARY KEY  (id)
);

-- Table: Stocks
CREATE TABLE Stocks (
    id_pharmacies int  NOT NULL,
    id_medicaments int  NOT NULL,
    pieces int  NOT NULL,
    CONSTRAINT Stocks_pk PRIMARY KEY  (id_pharmacies,id_medicaments)
);

-- foreign keys
-- Reference: Doctors_Doctor_fields (table: Doctors)
ALTER TABLE Doctors ADD CONSTRAINT Doctors_Doctor_fields
    FOREIGN KEY (id_Doctor_fields)
    REFERENCES Doctor_fields (id)
    ON DELETE  SET NULL;

-- Reference: Doctors_Hospitals (table: Doctors)
ALTER TABLE Doctors ADD CONSTRAINT Doctors_Hospitals
    FOREIGN KEY (id_hospital)
    REFERENCES Hospitals (id)
    ON DELETE  SET NULL;

-- Reference: Doctors_People (table: Doctors)
ALTER TABLE Doctors ADD CONSTRAINT Doctors_People
    FOREIGN KEY (id_people)
    REFERENCES People (id);

-- Reference: Doctors_People_Doctors (table: Doctors_People_tab)
ALTER TABLE Doctors_People_tab ADD CONSTRAINT Doctors_People_Doctors
    FOREIGN KEY (id_Doctors)
    REFERENCES Doctors (id)
    ON DELETE  CASCADE;

-- Reference: Doctors_People_People (table: Doctors_People_tab)
ALTER TABLE Doctors_People_tab ADD CONSTRAINT Doctors_People_People
    FOREIGN KEY (id_People)
    REFERENCES People (id)
    ON DELETE  CASCADE;

-- Reference: Hospitals_Cities (table: Hospitals)
ALTER TABLE Hospitals ADD CONSTRAINT Hospitals_Cities
    FOREIGN KEY (id_city)
    REFERENCES Cities (id);

-- Reference: Pharmacy_Cities (table: Pharmacies)
ALTER TABLE Pharmacies ADD CONSTRAINT Pharmacy_Cities
    FOREIGN KEY (id_city)
    REFERENCES Cities (id);

-- Reference: Recipes_Doctors (table: Recipes)
ALTER TABLE Recipes ADD CONSTRAINT Recipes_Doctors
    FOREIGN KEY (id_doctor)
    REFERENCES Doctors (id);

-- Reference: Recipes_Medicaments (table: Recipes)
ALTER TABLE Recipes ADD CONSTRAINT Recipes_Medicaments
    FOREIGN KEY (id_medicament)
    REFERENCES Medicaments (id);

-- Reference: Recipes_People (table: Recipes)
ALTER TABLE Recipes ADD CONSTRAINT Recipes_People
    FOREIGN KEY (id_user)
    REFERENCES People (id);

-- Reference: Recipes_Pharmacy (table: Recipes)
ALTER TABLE Recipes ADD CONSTRAINT Recipes_Pharmacy
    FOREIGN KEY (id_pharmacy)
    REFERENCES Pharmacies (id)
    ON DELETE  SET NULL;

-- Reference: Stores_Medicaments (table: Stocks)
ALTER TABLE Stocks ADD CONSTRAINT Stores_Medicaments
    FOREIGN KEY (id_medicaments)
    REFERENCES Medicaments (id);

-- Reference: Stores_Pharmacies (table: Stocks)
ALTER TABLE Stocks ADD CONSTRAINT Stores_Pharmacies
    FOREIGN KEY (id_pharmacies)
    REFERENCES Pharmacies (id);

-- End of file.

