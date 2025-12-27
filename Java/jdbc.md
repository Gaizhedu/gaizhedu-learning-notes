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
next()的作用是将游标下移一行，如果有有效行，则返回`true`，否则返回false

一般来讲，在执行完.executeQuery后，会得到一个ResultSet对象，通过循环调用next()便可以读取数据

需要注意的一点是，在读取第一行数据的时候必须要先使用一次next()才能读取

## close
`close()`方法用于释放数据库连接及相关资源，`Connection`，`Statement`，`ResultSet`需要使用调用`close()`

为什么需要使用close呢？一个比较大的原因是防止资源泄漏和避免连接耗尽

### isClosed()
这个方法的作用是判断该对象是否关闭。如果为true则为关闭，否则为打开状态

## Properties
Properties是一个常见的类，主要的作用是处理键值对形式的配置信息

所有的键和值都是字符串类型，并且线程安全，可以使用`setProperty`方法来设置键值对，用`getProperty`来获取指定键的值

## executeUpdate
executeUpdate用于执行不返回结果集的 SQL 语句，例如`INSERT`、`UPDATE`、`DELETE`，不能用于查询！

## execute
execute是一个通用的执行语句，用于执行所有类型的SQL语句

使用起来更复杂，通常只在SQL 语句类型未知或需要处理多结果集/混合结果时才使用

## prepareStatement
这个方法的作用是执行SQL语句，一般推荐使用这个方法来执行SQL语句，可以防止SQL注入，并且类型安全

## setString
这个方法的作用是设置参数占位符为字符串类型的值。

签名如下
``` Java
void setString(int parameterIndex, String x) throws SQLException;
```

需要注意的一点是，第一个参数从1开始，第二个参数代表设置的字符为

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