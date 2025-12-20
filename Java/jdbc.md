# JDBC

## Class.forName()
Class.forName()是一个用于动态加载数据库的方法，基本用法是在圆括号加上指定的类

例如：`Class.forName("com.mysql.cj.jdbc.Driver");`

指的是MySQL的JDBC驱动类

这个方法在JDBC4.0后便不怎么常用，因为在这个版本后便引入了`SPI`机制

也就是说启动的时候会自动加载这个驱动类

所以现在不再需要显式调用`Class.forName()`

## getConnection

## createStatement

## executeQuery

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