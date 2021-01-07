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