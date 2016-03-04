#include <stdio.h>
#include <string.h>
union AUnion_Type {
      int Qtty;
      struct {
		char No[4];
		char Name[10];
		char Sex;
		int Age;
      }Student;
      long SeqNo;
};
int main(void)
{  union AUnion_Type AUnionRec;
   AUnionRec.Qtty=1000;
   AUnionRec.SeqNo=2000;
   strcpy(AUnionRec.Student.No,"0010");
   printf("Qtty=%d\n",AUnionRec.Qtty);
   printf("SeqNo=%ld\n",AUnionRec.SeqNo);
   printf("No=%s\n",AUnionRec.Student.No);
   return 0;
}
