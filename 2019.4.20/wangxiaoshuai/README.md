# 2019.4.20
## Hdu_1325
### &emsp;简单并查集，注意:
### &emsp;1.只能有一棵树
### &emsp;2.因为是个有向图所以点的入度只能为1
### &emsp;3.只有两个点都小于0的时候才能结束，而不是==-1
## Hdu_1074
### &emsp;此题是个状压dp.注意题目给的就是按字典序排的。
### &emsp;我们很容易能想到定义状态dp[state],state二进制的第i位
### &emsp;表示的是第i个作业的写与不写。当然最后所有作业都是要写的。
### &emsp;但是最后的状态从之前的那个状态转移过来决定了选作业的顺序。
### &emsp;比如111就可以从011,101,100转移过来。
