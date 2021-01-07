package com.dbs;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class CustomConnector extends DBSConnector {

    public CustomConnector(Scanner scanner) {
        super(scanner);
    }

    public void getUselessDoctors() {
        executeAndPrint("SELECT firstname, surname, phone FROM People P WHERE P.id IN (SELECT id FROM Doctors WHERE id NOT IN (SELECT id_Doctors FROM Doctors_People_tab))");
    }

    public void getMedicamentAVGStock(){
        executeAndPrint("SELECT id_medicaments,(SELECT [name] FROM Medicaments WHERE id=s.id_medicaments) mname,AVG(pieces) FROM Stocks s GROUP BY id_medicaments");
    }

    public void getPharmaciesStockMoreThan200(){
        executeAndPrint("SELECT Pharmacies.[name],S.sum_pieces AS 'Stock size' FROM (SELECT Stocks.id_pharmacies,SUM(pieces) AS 'sum_pieces' FROM Stocks GROUP BY Stocks.id_pharmacies) AS S LEFT JOIN Pharmacies ON S.id_pharmacies = Pharmacies.id WHERE sum_pieces>200");
    }

    public void getDoctorsPeopleCount(){
        executeAndPrint("SELECT firstname, surname, field,ISNULL(pacient_sum,0) pacient_sum FROM People P JOIN Doctors D ON P.id=D.id_people JOIN Doctor_fields F on F.id=D.id RIGHT JOIN (SELECT id_doctors, COUNT(id_People) pacient_sum FROM Doctors_People_tab GROUP BY id_doctors) C ON D.id=C.id_doctors");
    }

    public void getStockPharmacy(){
        executeAndPrint("SELECT [Pharmacies].[name], [Medicaments].[name], [Medicaments].[type], [Stocks].[pieces] FROM Pharmacies LEFT JOIN Stocks ON Pharmacies.id = Stocks.id_pharmacies LEFT JOIN Medicaments ON Medicaments.id = Stocks.id_medicaments      ");
    }

    private void executeAndPrint(String SQL){
        try(Connection connection = this.dataSource.getConnection()) {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            while (resultSet.next()){
                for(String column: parseColumnsName(resultSet)){
                    System.out.print(resultSet.getString(column) + " ");
                }
                System.out.println();
            }
        } catch (SQLException e){
            System.out.println("Something went wrong ... {"+e+"}");
        }
    }
}
