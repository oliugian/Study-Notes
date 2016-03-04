	main()
	{int a,b,c,m;
	scanf("%d,%d,%d",&a,&b,&c);
	m=max(a,b,c);
	printf("max=%d\n",m);
	}
	int max(x,y,z)
	int x,y,z;
	{int s;
	if (x>y) s=x;
	else s=y;
	if (s<z) s=z;
	return(s);
	}
