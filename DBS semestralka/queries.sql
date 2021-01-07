--SELECT v SELECT
SELECT [name],[type],pieces,(SELECT AVG(pieces) FROM Stocks) AS 'average_stock' FROM Medicaments M LEFT JOIN Stocks S on M.id=S.id_medicament WHERE M.id IN (SELECT id_medicament FROM Stocks)

--SELECT ve FROM
SELECT S.sum_pieces FROM (SELECT SUM(pieces) AS 'sum_pieces' FROM Stocks GROUP BY Stocks.id_pharmacies) AS S WHERE sum_pieces>200

--SELECT ve WHERE
SELECT firstname, surname, phone FROM People P WHERE P.id IN (SELECT id FROM Doctors WHERE id NOT IN (SELECT id_Doctors FROM Doctors_People_tab))

--GROUP BY
SELECT firstname, surname, field,ISNULL(pacient_sum,0)FROM People P
LEFT JOIN Doctors D ON P.id=D.id_people 
LEFT JOIN Doctor_fields F on F.id=D.id 
LEFT JOIN (SELECT id_doctors, 
COUNT(id_People) AS 'pacient_sum' FROM Doctors_People_tab 
GROUP BY id_doctors) C ON D.id=C.id_doctors

-- LEFT JOIN What phramacies have in stock
SELECT [Pharmacies].[name], [Medicaments].[name], [Medicaments].[type], [Stocks].[pieces] FROM Pharmacies
    LEFT JOIN Stocks 
        ON Pharmacies.id = Stocks.id_pharmacies
    LEFT JOIN Medicaments 
        ON Medicaments.id = Stocks.id_medicaments

-- LEFT JOIN What phramacy n [2] have in stock
SELECT [Pharmacies].[name], [Medicaments].[name], [Medicaments].[type], [Stocks].[pieces] FROM Pharmacies
    LEFT JOIN Stocks 
        ON Pharmacies.id = Stocks.id_pharmacies
    LEFT JOIN Medicaments 
        ON Medicaments.id = Stocks.id_medicaments
WHERE Pharmacies.id = 2

-- How many doctors does hospital have and how many recipes on doctor have been created
 SELECT Hospitals.id ,Hospitals.name , ISNULL(doctor_count,0) AS 'doctor count', ISNULL(recipe_count,0) AS 'recipe count', ISNULL((recipe_count / doctor_count),0) AS 'Recipies on doctor' FROM Hospitals
 LEFT JOIN (SELECT id_hospital, sum(var_recipe_count) AS 'recipe_count' FROM Doctors JOIN 
		(SELECT id_doctor, count(id_doctor) AS 'var_recipe_count' FROM Recipes GROUP BY (id_doctor) ) AS R 
        ON R.id_doctor = Doctors.id GROUP BY id_hospital) AS T1	
    ON T1.id_hospital = Hospitals.id
 LEFT JOIN 
        (SELECT id_hospital, count(id_hospital) AS 'doctor_count' FROM Doctors GROUP BY id_hospital) AS T2
    ON T2.id_hospital = Hospitals.id 
 