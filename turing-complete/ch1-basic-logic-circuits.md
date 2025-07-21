# 基础逻辑电路
## 前言
这个笔记记录了《Turing Complete》第一章中提到的概念

笔记将会以口语化的形式说明

## 正文
第一章有几个基础概念，分别是：与非门（NAND）、非门（NOT）、与门（AND）、或非门（NOR）、或门（OR）

接下来来逐一介绍：

### 与非门（NAND）
与非门的作用如下：

当且仅当两个输入均为True时，输出结果为False

除此之外，其他情况均输出为True

<table>
    <thead>
        <tr>
            <th>第一个输入</th>
            <th>第二个输入</th>
            <th>输出结果</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>False</td>
            <td>False</td>
            <td>True</td>
        </tr>
        <tr>
            <td>False</td>
            <td>True</td>
            <td>True</td>
        </tr>
        <tr>
            <td>True</td>
            <td>False</td>
            <td>True</td>
        </tr>
        <tr>
            <td>True</td>
            <td>True</td>
            <td>False</td>
        </tr>
    </tbody>
</table>

### 与门（AND）
与门的作用域与非门相反，也就是为什么叫NAND的原因（Not AND）
当且仅当两个输入均为True时，输出结果为True，其余结果均为False
<table>
    <thead>
        <tr>
            <th>第一个输入</th>
            <th>第二个输入</th>
            <th>输出结果</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>False</td>
            <td>False</td>
            <td>False</td>
        </tr>
        <tr>
            <td>False</td>
            <td>True</td>
            <td>False</td>
        </tr>
        <tr>
            <td>True</td>
            <td>False</td>
            <td>False</td>
        </tr>
        <tr>
            <td>True</td>
            <td>True</td>
            <td>True</td>
        </tr>
    </tbody>
</table>

### 或非门（NOR）
或非门也是一种常见的门，规则是当且仅当两个输入均为False输出为True，否则输出为False
<table>
    <thead>
        <tr>
            <th>第一个输入</th>
            <th>第二个输入</th>
            <th>输出结果</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>False</td>
            <td>False</td>
            <td>True</td>
        </tr>
        <tr>
            <td>False</td>
            <td>True</td>
            <td>False</td>
        </tr>
        <tr>
            <td>True</td>
            <td>False</td>
            <td>False</td>
        </tr>
        <tr>
            <td>True</td>
            <td>True</td>
            <td>False</td>
        </tr>
    </tbody>
</table>

有些人可能发现了，诶这个门怎么长得有点像与非门啊，让我们来对比一下区别
这里为了阅读方便，用1表示True，用0表示False
<table>
    <thead>
        <tr>
            <th>第一个输入</th>
            <th>第二个输入</th>
            <th>或非门</th>
            <th>与非门</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td>0</td>
            <td>1</td>
            <td>1</td>
        </tr>
        <tr>
            <td>0</td>
            <td>1</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td>1</td>
            <td>1</td>
            <td>0</td>
            <td>0</td>
        </tr>
    </tbody>
</table>

这里用Mermaid中的流程图简单演示一下
``` Mermaid
flowchart LR
    A([输入1]) --> C(非门)
    B([输入2]) --> D(非门)
    C --> E{与非门}
    D --> E{与非门}
    E --> F(非门) --> G([输出])
```
这里就是一个完整的或非门实现过程

### 或门（OR）
或门与或非门的关系与与门与与非门的关系是一致的\
也就是当且仅当两个输入为False时，输出为False，否则输出为True
<table>
    <thead>
        <tr>
            <th>第一个输入</th>
            <th>第二个输入</th>
            <th>输出结果</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>False</td>
            <td>False</td>
            <td>False</td>
        </tr>
        <tr>
            <td>False</td>
            <td>True</td>
            <td>True</td>
        </tr>
        <tr>
            <td>True</td>
            <td>False</td>
            <td>True</td>
        </tr>
        <tr>
            <td>True</td>
            <td>True</td>
            <td>True</td>
        </tr>
    </tbody>
</table>

### 非门
非门简单来理解就是翻转输入值，如下表显示
<table>
    <thead>
        <tr>
            <th>输入</th>
            <th>输出结果</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>True</td>
            <td>False</td>
        </tr>
        <tr>
            <td>False</td>
            <td>True</td>
        </tr>
    </tbody>
</table>

### 德·摩根定律
德摩根定律指出：与门，与非门，或门，或非门之间可以通过非门互相转换，关系如下表显示：
``` Mermaid
flowchart
    A[与门] <--对输出取反--> B[与非门]
    B <--对输入取反--> C[或门]
    C <--对输出取反--> D[或非门]
    D <--对输入取反--> A
```