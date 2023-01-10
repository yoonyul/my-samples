#include <emscripten.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EMSCRIPTEN_KEEPALIVE
double md5(int count){
    //int count = 10;
    clock_t start,end;
    start = clock();	
    for(int i=1; i<=count; i++){ //loop
    
    	EVP_MD_CTX* ctx;
    	ctx = EVP_MD_CTX_new();
    	EVP_MD_CTX_init(ctx);
 
    	unsigned int targetDataLength = 0;
    	unsigned char sourceData[1024] = "hello word";
    	unsigned char targetData[1024] = {0};
 
    	//设置摘要算法
    	EVP_DigestInit_ex(ctx, EVP_md5(), NULL);
 
    	//计算摘要
    	EVP_DigestUpdate(ctx, sourceData, strlen((char*)sourceData));
 
    	//输出摘要值
    	EVP_DigestFinal_ex(ctx, targetData, &targetDataLength);
 
    	//16进制打印
    	for(int i = 0; i < targetDataLength; i++)
    	{
        	printf("%.02x", targetData[i]);
  	}
    	printf("\n");
 	
   	EVP_MD_CTX_free(ctx);
    }
    end = clock();
    double time =((double)(end - start)); //用结束时间减去开始时间
    printf("Run %d times cost %f milliseconds\n",count, time);
    return time;
}


int main(int argc , const char *argv[]){
    int count = 0;
    //sscanf(argv[1], "%d", &count);
    //md5(count);
    return 0;
}

