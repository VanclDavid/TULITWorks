package com.dbs;
import com.microsoft.sqlserver.jdbc.SQLServerDataSource;

class ConfigData {
    protected final String serverName = "147.230.21.34";
    protected final String databaseName = "DBS2020_DavidVancl";
    protected final int port = 1433;
    protected final String username = "student";
    protected final String password = "student";
}

public class AccessPoint extends ConfigData {
    protected SQLServerDataSource dataSource;

    public AccessPoint() {
        dataSource = new SQLServerDataSource();
        dataSource.setServerName(this.serverName);
        dataSource.setPortNumber(this.port);
        dataSource.setDatabaseName(this.databaseName);
        dataSource.setUser(this.username);
        dataSource.setPassword(this.password);
    }
}