--Clear
--DELETE FROM Logins;
--DELETE FROM Topics;
--DELETE FROM Users;

--DBCC CHECKIDENT ('Topics', RESEED, 0);

--Insert
IF NOT EXISTS (SELECT * FROM Users WHERE 
	login = 'Pavel' OR 
	login = 'Petr' OR 
	login = 'David' OR
	login = 'Honza' OR
	login = 'Lubor' OR
	login = 'Lukas')
BEGIN
    INSERT INTO Users (id,login,password) VALUES 
		(1,'Pavel', HASHBYTES('md5','Pavel')),
		(2,'Petr', HASHBYTES('md5','Petr')),
		(3,'David', HASHBYTES('md5','David')),
		(4,'Honza', HASHBYTES('md5','Honza')),
		(5,'Lubor', HASHBYTES('md5','Lubor')),
		(6,'Lukas', HASHBYTES('md5','Lukas'))
END

IF NOT EXISTS (SELECT * FROM Topics WHERE 
	name = 'Security' OR
	name = 'Languages' OR
	name = 'Objects' OR
	name = 'Levels')
BEGIN
    INSERT INTO Topics (name,id_administrator) VALUES 
	('Security', 4),
	('Languages', 5),
	('Objects', 6),
	('Levels', 1);
END

IF NOT EXISTS (SELECT * FROM Logins WHERE 
	id_topic = 1 AND id_user = 1 OR
	id_topic = 3 AND id_user = 2 OR
	id_topic = 1 AND id_user = 3 OR
	id_topic = 2 AND id_user = 4 OR
	id_topic = 2 AND id_user = 5 OR
	id_topic = 4 AND id_user = 6 )
BEGIN
    INSERT INTO Logins (id_topic,id_user,last_login) VALUES 
		(1,1,GETDATE()),
		(3,2,GETDATE()),
		(1,3,GETDATE()),
		(2,4,GETDATE()),
		(2,5,GETDATE()),
		(4,6,GETDATE())
END

--SELECT * FROM Users WHERE id = 4;
--DELETE FROM Users WHERE id = 4;


--DELETE FROM Topics WHERE id = 3;