-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2021-01-07 18:04:52.777

-- foreign keys
ALTER TABLE Doctors DROP CONSTRAINT Doctors_Doctor_fields;

ALTER TABLE Doctors DROP CONSTRAINT Doctors_Hospitals;

ALTER TABLE Doctors DROP CONSTRAINT Doctors_People;

ALTER TABLE Doctors_People_tab DROP CONSTRAINT Doctors_People_Doctors;

ALTER TABLE Doctors_People_tab DROP CONSTRAINT Doctors_People_People;

ALTER TABLE Hospitals DROP CONSTRAINT Hospitals_Cities;

ALTER TABLE Pharmacies DROP CONSTRAINT Pharmacy_Cities;

ALTER TABLE Recipes DROP CONSTRAINT Recipes_Doctors;

ALTER TABLE Recipes DROP CONSTRAINT Recipes_Medicaments;

ALTER TABLE Recipes DROP CONSTRAINT Recipes_People;

ALTER TABLE Recipes DROP CONSTRAINT Recipes_Pharmacy;

ALTER TABLE Stocks DROP CONSTRAINT Stores_Medicaments;

ALTER TABLE Stocks DROP CONSTRAINT Stores_Pharmacies;

-- tables
DROP TABLE Cities;

DROP TABLE Doctor_fields;

DROP TABLE Doctors;

DROP TABLE Doctors_People_tab;

DROP TABLE Hospitals;

DROP TABLE Medicaments;

DROP TABLE People;

DROP TABLE Pharmacies;

DROP TABLE Recipes;

DROP TABLE Stocks;

-- End of file.

