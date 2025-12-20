# JDBC

## Class.forName()
Class.forName()是一个用于动态加载数据库的方法，基本用法是在圆括号加上指定的类

例如：`Class.forName("com.mysql.cj.jdbc.Driver");`

指的是MySQL的JDBC驱动类

这个方法在JDBC4.0后便不怎么常用，因为在这个版本后便引入了`SPI`机制

也就是说启动的时候会自动加载这个驱动类

所以现在不再需要显式调用`Class.forName()`

## getConnection
DriverManager.getConnection()是获取数据库连接的核心方法

这个方法签名如下：
``` Java
public static Connection getConnection(String url, String user, String password) throws SQLException
```

其中第一个参数代表数据库的地址，而第二个参数代表账户名称，第三个参数代表密码

由于该方法可能抛出`SQLException`，所以必须处理

为了确保及时关闭连接，所以要使用`try-with-resources`来自动关闭资源

## createStatement
这个方法的作用是创建一个`Statement`对象，这个对象的作用是向数据库发送SQL语句

通过Statement，可以执行一些静态的SQL语句

``` Java
Statement stmt = conn.createStatement();
ResultSet rs = stmt.executeQuery("SELECT id, name FROM users")
```

## executeQuery
executeQuery()的作用为执行查询语句，并返回其结果集

如果用于执行不为查询操作的操作，那么会抛出`SQLException`

需要注意的一点是，每次查询后都要执行一次`next()`来确保游标移动

## next

## close

### isClose()

## Properties

## setProperty

## executeUpdate

## execute

## prepareStatement

## setString

## addBatch

## executeBatch

## first & last

## wasNull

## SetAutoCommit

## commit

## rollback

## setSavepoint

## releaseSavepoint

## getTransactionIsolation