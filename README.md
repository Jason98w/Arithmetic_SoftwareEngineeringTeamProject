# Arithmetic_SoftwareEngineeringTeamProject
软件工程结对项目——四则运算

组员：谢蜜雪、杨冰琪

问题描述：

1.一次生成一千个小学四则运算题目到一个文件里，保证合法、不重复。
注意：
a.运算符至多10个，其中括号数不在此限制内。
b.可以进行真分数运算。
c.可以设置对乘方的符号选择（ ** 或 ^ ）。
d.合法的注意事项：没有除0的操作、括号匹配、真分数运算可能会出现假分数结果，此时将结果表示为 整数+真分数。

2.一个图形界面，用户可以输入答案，系统判断对错，并设立一个20秒的倒计时。

控制台程序使用说明：
生成四则运算题目的命令行格式为：Arithmetic.exe -p N type
                                其中N为生成的题目个数（1<= N <=1000)；
                                type为题目的类型：A为普通四则运算，B为加入乘方 ^ 的四则运算 , C为加入乘方 ** 的四则运算
求解题目的命令行格式为：Arithmetic.exe -a

