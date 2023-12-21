
#include <stdio.h>
#include <mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    const char *host = "localhost";
    const char *user = "*****";
    const char *password = "******";
    const char *dbname = "******";

    if (mysql_real_connect(conn, host, user, password, NULL, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return 1;
    }

    // Create the database
    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS C_login")) {
        fprintf(stderr, "CREATE DATABASE failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Use the database
    if (mysql_query(conn, "USE C_login")) {
        fprintf(stderr, "USE database failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Create the table
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS user (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255),  username VARCHAR(255), password VARCHAR(255))")) {
        fprintf(stderr, "CREATE TABLE failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Database and table created successfully!\n");

    mysql_close(conn);

    return 0;
}
