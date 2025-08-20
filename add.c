
int add(int x,int y)
{
    return x+y;
}
//函数定义
//为演示静态库效果，一律注释化
//通过编译成静态库以做到闭源函数定义代码
//vscode需要手动同时编译 1.cd /Users/yaomeng/Documents/Cplusplus/20250819/ 2.gcc test15functionPlus.c add.c -o test15functionPlus 3../test15functionPlus
//问题已解决，目前修改task.json后，可通过1.选取对应文件，cmd+shift+B 构建集成任务(同文件夹)，2.cmd+shift+P run task -> run current folder执行 以触发同时编译同文件夹内所有文件
//Note:单纯使用code runnner的绿色三角仍会导致只运行单个文件

// 静态库生成教程(windows静态库格式是add.lib,mac中静态库格式是libadd.a)[导入前要把.c .h放在同一个文件夹里][1个静态库可放多个函数]
// # 进入 add 目录
// cd "/Users/yaomeng/Documents/Cplusplus/20250819/add"

// # 1) 把 add.c 编译成目标文件 .o （只编译，不链接）
// clang -I. -O2 -c add.c -o add.o

// # 2) 用 ar 打包成静态库 libadd.a
// ar rcs libadd.a add.o

// # （可选）查看库里是否有 add() 符号
// nm -gU libadd.a | grep " T _add"