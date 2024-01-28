# hex - 一个没有什么用的在windows中用命令查看文件16进制的C程序
## build
``` 
gcc hex.c mycon.c -o hex.exe -lwinmm
```
## run
```
hex -f [file name] (-c [column number])
```
 - `[file name]` 文件名
 - `[column number]` 输出的列数
