	main()                  /*  主函数  */
	{int a,b,c;             /* 定义变量 */
	scanf("%d,%d",&a,&b);   /*输入变量a和b的值*/
	c=max(a,b);             /*调用max函数,将得到的值赋给c */
	printf("max=%d",c);     /*调出c的值*/
	}
	int max(x,y)            /*定义max函数,函数值为整型,x、y为形式参数*/
	int x,y;                /*对形参x、y作类型定义*/
	{int z;                 /*max函数中用到的变量z,也要加以定义*/
	if (x>y) z=x;
	else z=y;
	return(z);              /*将z的值返回,通过max带回调用处*/
	}
