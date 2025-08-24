//结构体(自定义类型方法的一种)
//<Plus0823>

#include<stdio.h>
#include<string.h>//strcpy的库
//把一些单一类型组合在一起的方法
//学生
struct Stu
{
    //结构体的成员
   char name[20];
   int age;
   char sex[20];
   char tele[20];
}; //有分号

void print(struct Stu* ps)//也可以直接传s，但是指针的方法不用创建额外空间更便捷
{
    //printf("%s %d %s %s\n",(*ps).name,(*ps).age,(*ps).sex,(*ps).tele);结合指针但繁琐
    printf("%s %d %s %s\n",ps->name,ps->age,ps->sex,ps->tele);//指针优化，ps-> :指向对象的成员
    //结构体指针变量 -> 成员名
}

int main()
{
    struct Stu s={"zhangsan",20,"Male","13420304240"}; //拿起类型(Stu)创建一个变量or对象(s) [初始化]
    printf("%s %d %s %s\n",s.name,s.age,s.sex,s.tele);//类型一一对应
    strcpy(s.name,"Lihua");//后续改动字符串时采取复制粘贴，strcpy
    //结构体对象.成员名
    print(&s);
    return 0;
}
