# Week 7 📝
Working with Data

## Flat-file database
- text files, csv
- dictreader allows using keys instead of frekin numbers
- key   |   value

## Relational Database
- SQL: Database Specific Language, is kinda Descriptive Language, it queries databases
- Follows CRUD -
    - Crete Data
    - Read Data
    - Update Data
    - Delete Data
- Keywords: CREATE, INSERT, SELECT, UPDATE, DELETE, etc.
- Some Other SQL: MySQL, phpMyadmin (GUI)
- Create DB -> Create Tables -> Add Data (Rows & Column) -> Create Relationships
- Each SQL table is capable of holding of purticular data type.
- NULL, INTEGER, REAL (decimal, float), TEXT (char, varchar), BLOB
- Primary Key - One Column that has all unique data

## sqlite3 and SQL
- A implemetaion of SQL with core functions
- Popular in Smartphones, Games, Apps etc.

- Loading CSV into sqlite:
    ```sqlite3
        .mode csv
        .import data.csv data_table_name
        .quit
    ```
- SELECT, INSERT, DELETE, UPDATE

## Database Designing
- Entity Relationship Diagram
- one-to-one relationship

- data types:
    - BLOB : Binary Large Object
    - INTEGER
    - NUMERIC - kinda date
    - REAL - decimal points things
    - TEXT
- NOT NULL - column cannot be null
- UNIQUE - no  duplicates
- PRIMARY KEY: is uniique to that table and the data
- FOREIGN KEY: presense of primary key present in the other table
- JOIN ON

- select * from shows join ratings on shows.id = ratings.show_id

## Relationship
- One-to-One
- One-to-many
- Many-to-many

    ```
    qlite> select * from genres limit 10;
    +---------+-----------+
    | show_id |   genre   |
    +---------+-----------+
    | 62614   | Comedy    |
    | 63881   | Adventure |
    | 63881   | Comedy    |
    | 63881   | Family    |
    | 63962   | Action    |
    | 63962   | Sci-Fi    |
    | 65269   | Family    |
    | 65269   | Fantasy   |
    | 65270   | Comedy    |
    | 65270   | Sci-Fi    |
    +---------+-----------+
    sqlite> select * from shows where id = 63881
    ...> ;
    +-------+-----------+------+----------+
    |  id   |   title   | year | episodes |
    +-------+-----------+------+----------+
    | 63881 | Catweazle | 1970 | 26       |
    +-------+-----------+------+----------+
    sqlite>

    ```
- Basically its like this SELECT * FROM shows JOIN genres shows.id = genres.show_id;
- Here we are selecting all stuff from Joint table of 'shows' & 'genres'.
- Matching it with ON the column shows.id = genres.show_id

## Indexes
- CREATE INDEX
- Makes querying faster.

## Race Condition
- so many things at one time.
- to prevent this we use Transactions

    ```SQL
        BEGIN TRANSACTION
        COMMIT
        ROLLBACK
    ```
## SQL Injection Attacks (new version: Prompt Injection)
- always validate user's input first to avoid SQL injections

----
# Shorts

- INSERT
    ```SQL
    INSERT INTO
    <table>
    (<columns>)
    VALUES
    (<values1>, <values2>)
    ```
    - Primary Key is mostly interger, and it is alaways a good practice to autoincrement it.

- SELECT
    - Extract data from table

        ```SQL
        SELECT
        <columns>
        FROM
        <aable>
        WHERE
        <predicate>
        ORDER BY
        <column>
        ```
- SELECT (JOIN)
    - Extract info from multiple tables
        ```SQL
        SELECT
            <columns>
        FROM
            <table1> JOIN <table2>
        ON
            <predicate>

        -- Example:
        SELECT
            users.fullname, moms.mother
        FROM
            users JOIN moms
        ON
            users.username = moms.username

        ```
- UPDATE
    - Modify info in table
        ```SQL
        UPDATE
            <table>
        SET
            <column> = <value>
        WHERE
            <predicate>

        -- Example:
        UPDATE
            users
        SET
            password = 'yaayay'
        WHERE
            id = 10
        ```
- DELETE
```SQL
DELETE FROM
    <table>
WHERE
    <predicate>
```
