
DELETE FROM [dbo].[Recipes];

DELETE FROM [dbo].[Stocks];

DELETE FROM [dbo].[Medicaments];

DELETE FROM Doctors_People_tab;

DELETE FROM Doctors;

DELETE FROM Doctor_fields;

DELETE FROM People;

DELETE FROM Pharmacies;

DELETE FROM Hospitals;

DELETE FROM Cities;

INSERT INTO Cities VALUES 
	(1,'Bechyně',39165,5016),
	(2,'Blovice',33601,4128),
	(3,'Čáslav',28601,10322),
	(4,'Chrastava',46331,6298),
	(5,'Jilemnice',51401,5401),
	(6,'Kosmonosy',29306,5233),
	(7,'Luhačovice',76326,5059),
	(8,'Třeboň',37901,8217),
	(9,'Železný Brod',46822,6051),
	(10,'Strážnice',69662,5537),
	(11,'Hořovice',26801,6901),
	(12,'Kamenice',25168,4664);

INSERT INTO Pharmacies VALUES 
	(1,'Lékárna Na Poliklinice',9,'50.6535, 15.2533'),
	(2,'Lékárna U Anděla',9,'50.6447 15.2574'),
	(3,'Lékárna Na Předměstí',8,'49.0540 14.7583'),
	(4,'Lékárna Palma',7,'49.1700 17.7527'),
	(5,'Lékárna U Zámku',6,'50.4583 14.9250'),
	(6,'Lékárna Montana',5,'50.6159 15.5049'),
	(7,'Lékárna Chrastava',4,'50.8287 14.9657'),
	(8,'Lékárna Pod Štítem',3,'49.9235 15.3959'),
	(9,'Lékárna Blovice',2,'49.5819 13.5391'),
	(10,'Lékárna Libušina',1,'49.2975 14.4698'),
	(11,'Lékárna U Růže',8,'49.0660 14.7583'),
	(12,'Lékárna Panacea',5,'50.6163 15.5008'),
	(13,'Lékárna Alba',12,'49.9394, 14.5761');

INSERT INTO Hospitals VALUES
	(1,'NH Hospital, a.s.','MND a.s.',9),
	(2,'Masarykův onkologický ústav','AGROFERT, a.s.',5),
	(3,'DELTA, spol. s r.o.','ČEPRO, a.s.',11),
	(4,'Fakultní nemocnice u sv. Anny','GECO CZ',1),
	(5,'Nemocnice Čáslav','OTE, a.s.',3),
	(6,'NEMOS PLUS, s.r.o.','Kooperativa ',7),
	(7,'Nemocnice Třeboň','Ezpada s.r.o.',8),
	(8,'Fakultní nemocnice Jilemnice','Insurance Group',5),
	(9,'Oblastní nemocnice Strážnice','O2',10),
	(10,'Nemocnice Blovice','GECO CZ',2);


INSERT INTO People (id,firstname, surname,gender, birth, phone) VALUES
	(1,'Karel','Jurek','M','1987-01-14','+420784957641'),
	(2,'Radovan','Toth','M','1999-05-27',NULL),
	(3,'Oleg','Šimeèek','M','1993-04-10','+420457964321'),
	(4,'Ivana','Coufalová','Ž','1991-02-15','+420789456154'),
	(5,'Jarmil','Diviš','M','1981-04-19','+420963254781'),
    (6,'Dominik','Hrubeš','M','1985-05-28','+420789654321'),
	(7,'Roman','Tlustý','M','1975-02-14',NULL),
	(8,'Jarmila','Chmelová','Ž','1996-04-18','+420852147963'),
	(9,'Emil','Hlava','M','1995-07-21','+420963254781'),
	(10,'Erik','Klièka','M','1999-07-18','+420757842963'),
	(11,'Roman','Urbánek','M','1979-07-18','+420785459126'),
	(12,'Radoslav','Tyl','M','1981-01-20','+420985756365'),
	(13,'Cyril','Hajda','M','1991-02-01','+420123456789'),
	(14,'Ivan','Bouška','M','1997-10-10','+420857963212'),
	(15,'Jáchym','Koláø','M','1997-10-10','+4208745638592'),
	(16,'Oskar','Zamazal','M','1989-10-10',NULL),
	(17,'Lubomír','Vybíral','M','1993-04-10','+420956745182'),
	(18,'Ludìk','Zdráhal','M','1987-11-11','+420365253142'),
	(19,'Erika','Kobrová','Ž','1999-01-01','+420999745621'),
	(20,'Dalibor','Jiøík','M','1989-11-05','+420456789456');

INSERT INTO Doctor_fields (id,field) VALUES
    (1,'praktický lékaø'),
	(2,'stomatolog'),
	(3,'kardiolog'),
	(4,'gynekolog'),
	(5,'dìtský lékaø'),
	(6,'pediatr'),
	(7,'psychiatr'),
	(8,'urolog'),
	(9,'chirurg'),
	(10,'oèní lékaø');

INSERT INTO Doctors (id,id_hospital,id_people,id_Doctor_fields) VALUES
        (1,1,1,1),
	(2,2,4,1),
	(3,3,18,2),
	(4,4,11,3),
	(5,5,20,4),
	(6,6,3,5),
	(7,7,6,5),
	(8,8,16,6),
	(9,9,13,7),
	(10,9,13,10);

INSERT INTO Doctors_People_tab (id_Doctors,id_People) VALUES
	(1,2),
	(1,5),
	(2,8),
	(3,9),
	(4,12),
	(5,15),
	(6,7),
	(6,19),
	(9,10),
	(9,7);

INSERT INTO [dbo].[Medicaments] ([id], [name], [type]) VALUES 
	(101, 'RECOXA 15 30X15MG', 'tablety'),
	(102, 'RECOXA 15 60X15MG', 'tablety'),
	(103, 'RECOXA 15 100X15MG', 'tablety'),
	
	(111, 'IBALGIN 80MG TBL FLM 12', 'tablety'),
	(112, 'IBALGIN 200MG TBL FLM 12', 'tablety'),
	(113, 'IBALGIN 400MG TBL FLM 12', 'tablety'),
	
	(121, 'SEVREDOL 30X10MG', 'potahové tablety'),
	(122, 'SEVREDOL 60X10MG', 'potahové tablety'),
	
	(201, 'BOIRON CH 15 4g', 'granule'),
	(202, 'BOIRON CH 30 4g', 'granule'),
	(203, 'BOIRON CH 9 4g', 'granule'),
	
	(301, 'JODISOL 38,5MG/G 3,6G', 'roztok'),
	(302, 'JODISOL 38,5MG/ 80G', 'roztok'),
	(303, 'JODISOL 38,5MG/ 760G', 'roztok'),
	
	(311, 'HEPARIN LÉÈIVA 1X10ML/50KU', 'injekční roztok'),
	(321, 'KANAVIT 1X5ML/100MG', 'kapky'),
	
	(601, 'MATRIFEN 10X1 18MG', 'náplast'),
	(602, 'MATRIFEN 10X1 38MG', 'náplast'),
	(603, 'MATRIFEN 10X1 76MG', 'náplast');

INSERT INTO [dbo].[Stocks] ([id_pharmacies], [id_medicaments], [pieces]) VALUES 
	(1, 203, 122),(1, 103, 115),(1, 202, 191),
	(2, 201, 126),(2, 103, 155),(2, 102, 12),
	(3, 601, 146),(3, 201, 106),(3, 301, 35),
	(4, 302, 3),(4, 203, 67),(4, 301, 196),
	(5, 102, 14),(5, 303, 34),(5, 302, 85),
	(6, 203, 23),(6, 202, 55),(6, 111, 149),
	(7, 203, 16),(7, 201, 189),(7, 302, 166),
	(8, 301, 58),(8, 122, 171),(8, 303, 194),
	(9, 311, 0),(9, 202, 36),(9, 201, 78),
	(10, 203, 172),(10, 202, 42),(10, 603, 121),
	(11, 122, 21),(11, 121, 114),(11, 102, 108),
	(12, 603, 40),(12, 203, 134),(12, 112, 64);

INSERT INTO [dbo].[Recipes] ([id],[code],[id_user],[id_doctor],[id_medicament],[id_pharmacy],[publication_date],[pick_up_date]) VALUES 
(1, 163786, 12, 5, 103, 4, DATEADD(day, -318,GETDATE()), DATEADD(day, -301,GETDATE())),
(2, 420153, 18, 4, 101, 11, DATEADD(day, -437,GETDATE()), NULL),
(3, 650630, 6, 8, 303, 6, DATEADD(day, -104,GETDATE()), NULL),
(4, 860813, 14, 10, 321, 5, DATEADD(day, -538,GETDATE()), DATEADD(day, -526,GETDATE())),
(5, 98023, 13, 4, 121, 7, DATEADD(day, -411,GETDATE()), NULL),
(6, 664335, 17, 8, 302, 8, DATEADD(day, -11,GETDATE()), NULL),
(7, 27243, 1, 10, 103, 5, DATEADD(day, -556,GETDATE()), NULL),
(8, 713638, 7, 9, 102, 8, DATEADD(day, -197,GETDATE()), NULL),
(9, 502479, 18, 6, 203, 7, DATEADD(day, -77,GETDATE()), NULL),
(10, 464750, 18, 3, 303, 8, DATEADD(day, -282,GETDATE()), NULL),
(11, 819751, 20, 9, 201, 7, DATEADD(day, -594,GETDATE()), NULL),
(12, 19131, 13, 5, 603, 4, DATEADD(day, -332,GETDATE()), DATEADD(day, -326,GETDATE())),
(13, 161120, 14, 4, 203, 4, DATEADD(day, -64,GETDATE()), NULL),
(14, 68401, 9, 7, 101, 1, DATEADD(day, -131,GETDATE()), NULL),
(15, 202206, 10, 4, 303, 4, DATEADD(day, -420,GETDATE()), DATEADD(day, -420,GETDATE())),
(16, 216901, 5, 3, 301, 8, DATEADD(day, -436,GETDATE()), NULL),
(17, 190841, 20, 4, 201, 10, DATEADD(day, -15,GETDATE()), DATEADD(day, 2,GETDATE())),
(18, 404779, 9, 6, 603, 12, DATEADD(day, -296,GETDATE()), DATEADD(day, -277,GETDATE())),
(19, 971187, 15, 9, 121, 12, DATEADD(day, -369,GETDATE()), NULL),
(20, 615639, 3, 8, 111, 3, DATEADD(day, -561,GETDATE()), NULL),
(21, 675490, 9, 4, 302, 6, DATEADD(day, -90,GETDATE()), NULL),
(22, 793929, 18, 4, 603, 12, DATEADD(day, -36,GETDATE()), DATEADD(day, -23,GETDATE())),
(23, 575261, 1, 6, 303, 10, DATEADD(day, -562,GETDATE()), NULL),
(24, 550848, 6, 8, 122, 1, DATEADD(day, -574,GETDATE()), NULL),
(25, 635400, 19, 10, 603, 6, DATEADD(day, -573,GETDATE()), NULL),
(26, 701242, 12, 1, 321, 3, DATEADD(day, -480,GETDATE()), DATEADD(day, -478,GETDATE())),
(27, 754039, 15, 5, 122, 6, DATEADD(day, -102,GETDATE()), NULL),
(28, 39240, 17, 7, 112, 8, DATEADD(day, -281,GETDATE()), NULL),
(29, 964499, 13, 10, 101, 11, DATEADD(day, -90,GETDATE()), NULL),
(30, 563054, 3, 7, 122, 6, DATEADD(day, -517,GETDATE()), NULL),
(31, 499932, 18, 1, 122, 8, DATEADD(day, -73,GETDATE()), NULL),
(32, 816268, 1, 9, 113, 10, DATEADD(day, -287,GETDATE()), NULL),
(33, 130139, 8, 1, 102, 8, DATEADD(day, -469,GETDATE()), DATEADD(day, -462,GETDATE())),
(34, 434623, 2, 4, 103, 12, DATEADD(day, -427,GETDATE()), NULL),
(35, 777803, 1, 1, 601, 2, DATEADD(day, -318,GETDATE()), NULL),
(36, 680463, 10, 6, 102, 8, DATEADD(day, -163,GETDATE()), NULL),
(37, 789484, 16, 8, 102, 11, DATEADD(day, -316,GETDATE()), NULL),
(38, 711309, 9, 10, 102, 4, DATEADD(day, -150,GETDATE()), DATEADD(day, -135,GETDATE())),
(39, 667877, 10, 10, 111, 12, DATEADD(day, -349,GETDATE()), DATEADD(day, -343,GETDATE())),
(40, 429318, 7, 7, 311, 11, DATEADD(day, -202,GETDATE()), NULL);