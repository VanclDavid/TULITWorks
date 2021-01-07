package com.dbs;

import java.sql.*;
import java.util.ArrayList;
import java.util.Scanner;

public class DBSConnector extends AccessPoint {
    private final Scanner scanner;

    public DBSConnector(Scanner scanner){
        super();
        this.scanner = scanner;
    }

    public void insertInto(String table) {
        try(Connection connection = this.dataSource.getConnection()) {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT COLUMN_NAME,DATA_TYPE FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '"+table+"'");
            ArrayList<String> fields = new ArrayList<>();
            ArrayList<String> fieldTypes = new ArrayList<>();
            StringBuilder sqlBuilder = new StringBuilder();
            sqlBuilder.append("INSERT INTO ").append(table).append(" (");
            while (resultSet.next()){
                fields.add(resultSet.getString("COLUMN_NAME"));
                sqlBuilder.append(resultSet.getString("COLUMN_NAME")).append(',');
                fieldTypes.add(resultSet.getString("DATA_TYPE"));
            }
            sqlBuilder.setLength(sqlBuilder.length() - 1);
            sqlBuilder.append(")").append(" VALUES (");
            for (int i = 0; i < fields.size();i++){
                System.out.println("Set '"+fields.get(i)+"':");
                if(fieldTypes.get(i).equals("varchar")){
                    sqlBuilder.append("'").append(scanner.next()).append("'").append(",");
                } else {
                    sqlBuilder.append(scanner.next()).append(",");
                }
            }
            sqlBuilder.setLength(sqlBuilder.length() - 1);
            sqlBuilder.append(")");
            statement.executeUpdate(sqlBuilder.toString());
            System.out.println("Successfully executed.");
        } catch (SQLException e){
            System.out.println("Something went wrong ... {"+e+"}");
        }
    }

    public void selectFrom(String table,ArrayList<Integer> ids,int limit){
        try(Connection connection = this.dataSource.getConnection()) {
            Statement statement = connection.createStatement();
            StringBuilder sqlCreator = new StringBuilder();
            sqlCreator.append("SELECT ");
            if(limit != 0){
                sqlCreator.append(" TOP(").append(limit).append(")");
            }
            sqlCreator.append(" * FROM ").append(table).append(" ");
            if(ids.size() > 0){
                sqlCreator.append(convertIDsToString(ids));
            }
            ResultSet resultSet = statement.executeQuery(sqlCreator.toString());
            while (resultSet.next()) {
                for (String field : parseColumnsName(resultSet)){
                    System.out.print(resultSet.getString(field) + " ");
                }
                System.out.println();
            }
            System.out.println("Successfully selected.");
        } catch (SQLException e){
            System.out.println("Something went wrong ... {"+e+"}");
        }
    }

    public void truncateTable(String table,ArrayList<Integer> ids){
        try(Connection connection = this.dataSource.getConnection()) {
            Statement statement = connection.createStatement();
            System.out.println("-------------------");
            selectFrom(table,ids,0);
            System.out.println("-------------------");
            StringBuilder sqlCreator = new StringBuilder();
            sqlCreator.append("DELETE FROM ").append(table);
            if(ids.size() > 0){
                sqlCreator.append(convertIDsToString(ids));
            }
            statement.executeUpdate(sqlCreator.toString());
            System.out.println("Successfully deleted.");
        } catch (SQLException e){
            System.out.println("Something went wrong ... {"+e+"}");
        }
    }

    public void editRow(String table,int id){
        try(Connection connection = this.dataSource.getConnection()) {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT * FROM " + table + " WHERE id="+id);
            ArrayList<String> columns = parseColumnsName(resultSet);
            String sql = null;
            while (resultSet.next()) {
                StringBuilder sqlCreator = new StringBuilder();
                sqlCreator.append("UPDATE ").append(table).append(" SET ");
                for (String field : columns){
                    if(!field.equals("id")){
                        System.out.println("Column '" + field + "': " + resultSet.getString(field));
                        System.out.println("Edit to (0 - no change): ");
                        String newRow = scanner.next();
                        if (!newRow.equals("0")) {
                            sqlCreator.append(field).append("='").append(newRow).append("',");
                        }
                    }
                }
                sqlCreator.setLength(sqlCreator.length() - 1);
                sqlCreator.append(" WHERE id=").append(id);
                sql = sqlCreator.toString();
            }
            statement.executeUpdate(sql);
            System.out.println("Successfully executed.");
        } catch (SQLException e){
            System.out.println("Something went wrong ... {"+e+"}");
        }
    }

    protected ArrayList<String> parseColumnsName(ResultSet resultSet){
        ArrayList<String> fields = new ArrayList<>();
        try{
            ResultSetMetaData metaData = resultSet.getMetaData();
            for (int i = 1; i <= metaData.getColumnCount(); i++) {
                fields.add(metaData.getColumnName(i));
            }
        } catch(SQLException e) {
            System.out.println("Wrong parsing ... {"+e+"}");
        }
        return fields;
    }

    private String convertIDsToString(ArrayList<Integer> ids){
        StringBuilder builder = new StringBuilder();
        builder.append("WHERE id IN (");
        for (int id: ids) {
            builder.append(id).append(",");
        }
        builder.setLength(builder.length() - 1);
        builder.append(")");
        return builder.toString();
    }
}