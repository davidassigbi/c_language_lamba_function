#include <stdio.h>
#include <stdlib.h>
#define staticArray(size,type,varName) type varName[size]
#define dynArrayOf(size,type) (type*)(malloc(sizeof(type)*(size)))
#define pointerTo(type) dynArrayOf(1,type)
#define invisible(sth)
#define lambda(returnType, arguments, lambdaBody) ({               \
            returnType lambdaFunction arguments                    \
                lambdaBody                                         \
            &lambdaFunction; })

int main() {
    invisible(staticArray(20,int,intVar));
    lambda(void, (), {
        printf("Hello world from first lambda!");
    })();
    lambda(void, (), {
        printf("Hello world from second lambda!");
    })();
    char* stringVar = dynArrayOf(101,char);
    printf("Hello world! Please enter something for me : ");
    scanf("%s", stringVar);
    printf("stringVar = %s", stringVar);
    return 0;
}
