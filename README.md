# Infra_SW_tutoria_mutex
Treinamento com threads e mutex da cadeira de Infraestrutura de Software. 

## Threads com mutex 
O programa recebe o input de uma matriz e retorna o somatório com as threads responsáveis. 
Cada thread se refere à soma dos numeros da linha respectiva da matriz, e assim, cada uma 
soma seus valores na variável global. Esta, é incremntada a cada vez que uma thread entra no 
loop e os lockers impedem outra thread de acessar a mesma região durante o tempo de execução.
