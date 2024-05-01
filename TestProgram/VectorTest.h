#ifndef VECTORTEST_H_INCLUDED
#define VECTORTEST_H_INCLUDED

int TestVectorDefaultConstructor();
int TestVectorNonDefaultConstructor(int vecSize);
int TestVectorCopyConstructor(int vecSize);
int TestVectorAssignmentOperator(int vecSize);
int TestGetSize(int vecSize);
int TestDestructor(int vecSize);
int TestPushBack(int vecSize, int value);
int TestPopBack(int vecSize, int value);
int TestVectorArrayIndexOperator(int vecSize, int value, int loc);

#endif // VECTORTEST_H_INCLUDED
