-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2020-10-27 12:15:46.485

-- tables
-- Table: Logins
CREATE TABLE Logins (
    id_topic int  NOT NULL,
    id_user int  NOT NULL,
    last_login datetime  NOT NULL,
    CONSTRAINT PK_LOGINS PRIMARY KEY  (id_topic,id_user)
);

-- Table: Topics
CREATE TABLE Topics (
    id int  NOT NULL IDENTITY,
    name varchar(20)  NOT NULL,
    id_administrator int  NULL,
    CONSTRAINT PK_TOPIC PRIMARY KEY  (id)
);

-- Table: Users
CREATE TABLE Users (
    id int  NOT NULL,
    login varchar(20)  NOT NULL,
    password varchar(50)  NOT NULL,
    CONSTRAINT UQ_LOGIN UNIQUE (login),
    CONSTRAINT PK_USER PRIMARY KEY  (id)
);

-- foreign keys
-- Reference: FK_Manager (table: Topics)
ALTER TABLE Topics ADD CONSTRAINT FK_Manager
    FOREIGN KEY (id_administrator)
    REFERENCES Users (id)
    ON DELETE  SET NULL;

-- Reference: FK_Topic (table: Logins)
ALTER TABLE Logins ADD CONSTRAINT FK_Topic
    FOREIGN KEY (id_topic)
    REFERENCES Topics (id);

-- Reference: FK_User (table: Logins)
ALTER TABLE Logins ADD CONSTRAINT FK_User
    FOREIGN KEY (id_user)
    REFERENCES Users (id)
    ON DELETE  CASCADE;

-- End of file.

