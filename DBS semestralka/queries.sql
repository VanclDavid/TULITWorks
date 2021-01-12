 -- Select ve Where
SELECT firstname, surname, phone FROM People P WHERE P.id IN (SELECT id FROM Doctors WHERE id NOT IN (SELECT id_Doctors FROM Doctors_People_tab))

-- Select v Selectu
SELECT id_medicaments,(SELECT [name] FROM Medicaments WHERE id=s.id_medicaments) mname,AVG(pieces) FROM Stocks s GROUP BY id_medicaments

--Select ve from
SELECT Pharmacies.[name],S.sum_pieces AS 'Stock size' 
FROM (SELECT Stocks.id_pharmacies,SUM(pieces) AS 'sum_pieces' 
FROM Stocks 
GROUP BY Stocks.id_pharmacies) AS S 
LEFT JOIN Pharmacies ON S.id_pharmacies = Pharmacies.id WHERE sum_pieces>200

--Group by
SELECT firstname, surname, field,ISNULL(pacient_sum,0) pacient_sum
FROM People P 
JOIN Doctors D ON P.id=D.id_people 
JOIN Doctor_fields F on F.id=D.id 
left JOIN (SELECT id_doctors, COUNT(id_People) pacient_sum FROM Doctors_People_tab GROUP BY id_doctors) C ON D.id=C.id_doctors

-- EXCEPT množinová operace
SELECT firstname,surname,phone FROM People EXCEPT SELECT firstname,surname,phone FROM People JOIN Doctors ON Doctors.id_people = People.id

--LEFT JOIN
SELECT [Pharmacies].[name], [Medicaments].[name], [Medicaments].[type], [Stocks].[pieces] 
FROM Pharmacies 
LEFT JOIN Stocks ON Pharmacies.id = Stocks.id_pharmacies 
LEFT JOIN Medicaments ON Medicaments.id = Stocks.id_medicaments