#include <jni.h>
#include <stdio.h>
#include <iostream>
#include "MatrixUtil.h"
using namespace std;

 

/*
 * Class:     src_MatrixUtil
 * Method:    multiply
 * Signature: ([[I[[I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_MatrixUtil_multiply
  (JNIEnv * env, jobject jobj, jobjectArray jarr1, jobjectArray jarr2){
  
    int** a1;
    int** a2;
    
    //Get size of two Matrices
    int m = env->GetArrayLength(jarr1);
    int n = env->GetArrayLength(jarr2); 
    int k = env->GetArrayLength( (jintArray) env->GetObjectArrayElement(jarr2,0));
    
    a1 = new int*[m];
    a2 = new int*[n];
     
    //Copy jarr1 to a1 
    for(int i = 0; i <= m -1; i++)
    {
     a1[i] = new int[n];
     jintArray tmp = (jintArray) env->GetObjectArrayElement(jarr1,i);
     env->GetIntArrayRegion(tmp,0,n,a1[i]); 
    }
     
    //copy jarr2 to a2
    for(int i = 0; i <= n -1; i++)
    {
     a2[i] = new int[k];
     jintArray tmp = (jintArray) env->GetObjectArrayElement(jarr2,i);
     env->GetIntArrayRegion(tmp,0,k,a2[i]); 
    }
     
     //Mutilply two matrices
     int a3[m][k];
     for (int i = 0; i <= m -1; i++)
      for(int j = 0; j <= k -1; j++)
      { a3[i][j] = 0; 
        for(int h = 0 ; h <= n-1; h++)
          a3[i][j] += a1[i][h] * a2[h][j];
      }
          
     //Create jobjectArray named res to return
     jclass intarr = env->FindClass("[I");
     jobjectArray res = env->NewObjectArray(m,intarr,NULL);
     
     //Copy a3 to res
     for (int i = 0; i <= m-1; i++)
     {
      jintArray intArray  = env->NewIntArray(k);
      env->SetIntArrayRegion(intArray,0,k,a3[i]);
      env->SetObjectArrayElement(res,i,intArray);
     }
     
     return res;
     
  }

/*
 * Class:     src_MatrixUtil
 * Method:    output
 * Signature: ([[I)V
 */
 /*
JNIEXPORT void JNICALL Java_src_MatrixUtil_output
  (JNIEnv * env, jobject jobj, jobjectArray jarr){
    //Get size of matrix jarr
  	int m = env->GetArrayLength(jarr);
    int k = env->GetArrayLength((jarray)env->GetObjectArrayElement(jarr,0));
    int** arr = new int*[m];
    //copy matrix jarr to array "arr" and print it out
    for(int i = 0; i <= m -1; i++)
    {
     arr[i] = new int[k];
     
     jintArray tmp = (jintArray) env->GetObjectArrayElement(jarr,i);
     env->GetIntArrayRegion(tmp,0,k,arr[i]); 
     
     for (int j = 0; j <= k-1; j++)
     cout<<arr[i][j]<<" ";
     cout<<endl; 
     }
 
  }
  */
  
  
  /*
 * Class:     src_MatrixUtil
 * Method:    input
 * Signature: (II)[[I
 */
 /*
JNIEXPORT jobjectArray JNICALL Java_src_MatrixUtil_input
  (JNIEnv * env, jobject jobj, jint m, jint m){
    
  	jint a[m][n];
  	
    //Create jbjectAraay to return
    jclass intarr = env->FindClass("[I");
    jobjectArray res = env->NewObjectArray(i,intarr,NULL);
     
  	for (int i = 0; i <= m-1; i++)
    {
    
  	  for (int j =0; j <= n-1; j++) 
      {
  	 	  cin>>a[i][j];
  	  };
     
     
      jintArray intArray  = env->NewIntArray(j);
      env->SetIntArrayRegion(intArray,0,j,a[k]);
      env->SetObjectArrayElement(res,k,intArray);
    }
    return res;
  }
  
  */
