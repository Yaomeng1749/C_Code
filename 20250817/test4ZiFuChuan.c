// 字符串，转义字符，注释

//<Plus0818>
//<Plus0821>
#include <stdio.h>
#include <string.h> //strlen所需库
int main()
{
    char ch = 'w';// 字符 单引号（空格也是字符，但是同位置多个空格也按1个空格算）
    char arr[10] = "abcdef";// 字符串无类型，只能字符数组表示，但字符串需要长度小于等于数组长度
    char arr1[] = "acdef";// 也可以这样，空赋,结果是01234排了字符，5排了\0
    char arr2[] = {'a', 'c', 'd', 'e', 'f'}; // 结果是只要01234排了字符没有5
    printf("arr1=%s\n", arr1);
    printf("arr1=%s\n", arr2);// 没遇到\0会瞎输出一段
    int len = strlen(arr1);// 求字符串长度
    printf("sz of arr1(strlen)=%zu\n", strlen(arr1)); // 5(strlen不会把'\0'计入长度)
    printf("sz of arr1(sizeof)=%zu\n", sizeof(arr1)); // 5+1(sizeof会把'\0'计入空间大小)<Plus0821>
    // 此处因为元素类型是字符，所以内存长度等于1字节，sizeof和strlen相近，但是无论如何sizeof都确实相较于strlen，会把'\0'考虑进来
    printf("sz of arr2(strlen)=%zu\n", strlen(arr2)); // 长度不一定，因为没遇到\0
    printf("sz of arr2(sizeof)=%zu\n", sizeof(arr2));

    // sizeof是一个操作符
    // 是用来计算变量(类型)所占内存空间的大小(字节)，不关注内存中存放的具体内容(会把'\0'考虑进来)

    // strlen是一个库函数，是专门求字符串长度的，且只能针对字符串
    // 从参数给定的地址向后一直接找\0，统计\0之前出现的字符的个数

    //数组长度会考虑进来'\0',而字符串长度strlen仅考虑字符个数

    // 转义字符（每个转义字符算一个字符位）
    //  \n换行符，\0终止符，\'单引号变字符转义符，\" \\ 同理
    //  \a蜂鸣声，\r回车，\t水平制表符（大空格）
    //  \ddd (每个d表示8进制数字) eg ‘\130' 1*64+3*8+0*0=88,根据ASCII码得到字符为X
    //  \xdd (每个d表示16进制数字) eg ‘\x30' 3*16+0*1=48 字符为0
    //  %d整型，%c字符型，%s字符串型，%f浮点型float，%lf浮点型double (以%c输出无单引号数字，会把数字视为ASCII码转化成字符)
    // 初始化=0.0时默认是double，要想时float，就需要写成0.0f
    int year = 0;
    int month = 0;
    int day = 0;
    scanf("%4d%2d%2d", &year, &month, &day);//%4d当前输入前四位录入
    printf("year%d,month%02d,day%02d", year, month, day); //%02d输出前两位不足则用(0）补齐
    //%2d 右对齐 0位用空格占位 %-2d 左对齐
    return 0;
}
// 注释
//  or /* 内容 */
