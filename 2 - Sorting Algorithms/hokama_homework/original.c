#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct champion{
    char* name;
    int tier;
}champion;




int particionaTier(champion *V, int inicio, int final, int subvet){
    int esq, dir;
    
    int controle = (final - inicio) + 1; //controle do tamanho do vetor
    int posi;
    srand(time(NULL)); // Para valores aleatórios não se repetirem

    champion pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    
    //caso seja um subvetor
    if(subvet){
        //posição aleatoria
        if(controle <=5)
            posi = inicio + (rand()%(controle)); 
        //mediana de 3 posições aleatórias    
        else
            posi = ( (inicio + (rand()%(controle))) + (inicio + (rand()%(controle))) + (inicio + (rand()%(controle))) )/3;
        
        //posicionar a posição aleatória escolhida, na posição de pivo
        aux = V[inicio];
        V[inicio] = V[posi];
        V[posi] = aux;
        pivo = V[inicio];
    }
    
    while (esq < dir){  
        // Avança posição da esquerda até encontrar numero maior que o pivo
        while (V[esq].tier <= pivo.tier)
            esq++;
        
        // Recua a posição da direita até encontrar numero menor que o pivo
        while (V[dir].tier > pivo.tier)
            dir--;
        
        // Trocar esq e dir
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    //retorna a posição do pivo
    return dir;
}

int particionaCamp(champion *V, int inicio, int final){
    int esq, dir, posi;
    //Encontrar tamanho do vetor
    int controle = (final - inicio) + 1;
    champion pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    //Já estou considerando a ordenação por campeão, sendo subvetores
    
    //posição aleatoria
    if(controle <=5)
        posi = inicio + (rand()%(controle)); 
    //mediana de 3 posições aleatórias    
    else
        posi = ( (inicio + (rand()%(controle))) + (inicio + (rand()%(controle))) + (inicio + (rand()%(controle))) )/3;

    //posicionar a posição aleatória escolhida, na posição de pivo
    aux = V[inicio];
    V[inicio] = V[posi];
    V[posi] = aux;
    pivo = V[inicio];pivo = V[inicio];

    while (esq < dir){
        // Avança posição da esquerda até encontrar numero maior que o pivo
        while(strcmp(V[esq].name, pivo.name) <= 0){
            esq++;
            if(esq == final)
                break;
        }
        // Recua a posição da direita até encontrar numero menor que o pivo
        while(strcmp(V[dir].name, pivo.name) > 0){
            dir--;
            if(dir == inicio)
                break;
        }
        // Trocar esq e dir
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    
    V[inicio] = V[dir];
    V[dir] = pivo;
    //retorna a posição do pivo
    return dir;
}

void quickSortTier(champion *V, int inicio, int fim,int subve){
    int pivo, subvet = subve;
    //a variaveis subvet é para o controle de subvetores
    //ordenar por tier
    if(fim > inicio){
        //separa os dados em 2 partições
        pivo = particionaTier(V, inicio, fim, subvet);
        subvet=1;
        //Função para a primeira metade
        quickSortTier(V, inicio, pivo-1, subvet);
        //Função para a segunda metade
        quickSortTier(V, pivo+1, fim, subvet);
    }
    
}

void quickSortCamp(champion *V, int inicio, int fim){
    int pivo;
    //ordenar por camp
    if(fim > inicio){
        //separa os dados em 2 partições
        pivo = particionaCamp(V, inicio, fim);
        //Função para a primeira metade
        quickSortCamp(V, inicio, pivo-1);
        //Função para a segunda metade
        quickSortCamp(V, pivo+1, fim);
    }
}

void ordernar(champion *V, int inicio, int fim){
    
    //ordenar por tier
    quickSortTier(V, inicio, fim, 0);
    
    //ordenar por campeao
    int origem = 0, cont_tier = V[0].tier;
    //percorrendo a lista
    for(int i=0; i<=fim; i++){
        //procurando a posição em que se altera o tier
        if(V[i].tier != cont_tier){
            //com a mudança de tier, encontramos a posição final do tier atribuido ao cont_tier
            //possui aqui então o inicio e fim do tier na lista
            //é passado como parametro "i-1" e "origem", que representam respectivamente a posição final e inicial do tier 
            quickSortCamp(V, origem, i-1);
            //"inicio" recebe a posição inicial do novo tier
            origem = i;
            //"cont_tier" recebe o novo tier
            cont_tier = V[i].tier;
        }

    }
    //ordernar ultimo tier que a função não encontra
    quickSortCamp(V, origem, fim);
}


int main(){
    int n;
    scanf("%d", &n);

    champion *champ;
    //alocação dinâmica de espaço para a lista de campeões
    champ = malloc(n*sizeof(champion));
    for (int i = 0; i < n; i++)
        champ[i].name = malloc(sizeof(char));
    
    //Recebendo os valors
    for (int i = 0; i < n; i++){
        scanf("%s", champ[i].name);
        scanf("%d", &champ[i].tier);
    }
    //ordenadar a estrutura
    ordernar(champ, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%s", champ[i].name);
        printf(" %d", champ[i].tier);
        printf("\n");
    }
    free(champ);

    return 0;
}