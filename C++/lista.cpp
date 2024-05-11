/*
 * Exercício para nota 04
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 04/05/2024
 */

#include <iostream>
#include <sstream>

using namespace std;

typedef struct Item {
    int categoria;
    int prioridade;
    string tarefa;
} TAREFA;

struct Node {
    TAREFA tarefa;
    Node *anterior;
    Node *proximo;
};

struct Lista {
    Node *inicio;
    Node *final;
    int tamanho;
};

void inicializar(Lista *);
void inserir_dados(Lista *);
void adicionar_tarefa(Lista *, TAREFA);
TAREFA retirar_tarefa_por_posicao(Lista *, int);
void mostrarLista(Lista *);
void mostrar_dados_tarefa(TAREFA);


void retirar_tarefa_por_posicao2(Lista *, int);
void buscar_tarefas_por_categoria(Lista *, int);
void buscar_tarefas_por_prioridades(Lista *, int);
void encerrar(Lista *);


int main() {
    Lista lista_tarefa; 
    TAREFA tarefa;

    inicializar(&lista_tarefa);
    mostrarLista(&lista_tarefa);
    retirar_tarefa_por_posicao(&lista_tarefa, 5);
    buscar_tarefas_por_categoria(&lista_tarefa, 2);
    buscar_tarefas_por_prioridades(&lista_tarefa, 2);
    inserir_dados(&lista_tarefa);

    mostrarLista(&lista_tarefa);

    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 5);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 1);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 8);
    mostrar_dados_tarefa(tarefa);
    tarefa = retirar_tarefa_por_posicao(&lista_tarefa, 8);
    mostrar_dados_tarefa(tarefa);

    mostrarLista(&lista_tarefa);

    retirar_tarefa_por_posicao2(&lista_tarefa, 2);
    mostrarLista(&lista_tarefa);
    buscar_tarefas_por_categoria(&lista_tarefa, 2);
    buscar_tarefas_por_prioridades(&lista_tarefa, 2);
    encerrar(&lista_tarefa);

    return 0;
}

void inicializar(Lista *lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->final = NULL;
}

void inserir_dados(Lista *lista) {
    TAREFA tarefa;
    for (int x = 0; x<10; x++) {
        tarefa.categoria = 1;
        tarefa.prioridade = 1;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }

    for (int x = 10; x<15; x++) {
        tarefa.categoria = 1;
        tarefa.prioridade = 2;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }

    for (int x = 15; x<25; x++) {
        tarefa.categoria = 2;
        tarefa.prioridade = 2;
        string str;
        stringstream stream;
        stream << x + 1;
        stream >> str;
        tarefa.tarefa = "Tarefa " + str;
        adicionar_tarefa(lista, tarefa);
    }
}

TAREFA retirar_tarefa_por_posicao(Lista *lista, int posicao) {
	TAREFA retorno;
//		cout << "Tamanho: " << lista->tamanho <<endl;
//  	cout << "Posi��o: " << posicao <<endl;
	if ( lista->tamanho < posicao){
	    cout << endl << "Tamanho da lista menor que a posição informada" << endl;
	}
	if(lista->tamanho != 0){
		Node* aux = lista->inicio;
		while (posicao >= 0) {
		    posicao--;
		    if (posicao == 0) {
		        aux->proximo->anterior = aux->anterior;
		        if(aux->anterior != NULL){
		            aux->anterior->proximo = aux->proximo;
		        }else{
		            lista->inicio = aux->proximo;
				}
		        aux->proximo = NULL;
		        aux->anterior = NULL;
		        retorno = aux->tarefa;
		        lista->tamanho = lista->tamanho - 1;
		        delete(aux);
		        return retorno;
		    }
		    aux = aux->proximo;
		}
	}
	return retorno;
}

void adicionar_tarefa(Lista *lista, TAREFA tarefa){
    Node *new_node = new Node;
    if (new_node == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }
    new_node->tarefa = tarefa;
    new_node->proximo = NULL;
    new_node->anterior = NULL;

   if (lista->inicio == NULL) {
        lista->inicio = new_node;
        lista->final = new_node;
        lista->tamanho = lista->tamanho + 1;
        return;
    } 
    if (lista->tamanho == 1) {
        Node* aux = lista->final;
        lista->final->proximo = new_node;
        new_node->anterior = lista->final;
        lista->final = new_node; 
        lista->tamanho = lista->tamanho + 1;
        return;
    } else {
        Node* aux = lista->final;
        aux->proximo = new_node;
        new_node->anterior = aux;
        lista->final = new_node; 
        lista->tamanho = lista->tamanho + 1;
        return;
    }
}

void mostrarLista(Lista *lista){
    if (lista->inicio != NULL) {
        cout << endl << "Tamanho da lista: " << lista->tamanho << endl;
        Node* cliente_local = lista->inicio;
        while(cliente_local != NULL){
            cout <<"[" << cliente_local->tarefa.tarefa << "]";
            cliente_local = cliente_local->proximo;
        }
        cout << endl << endl;
    } else {
        cout << "Tamanho da lista: " << lista->tamanho << endl;
        cout << "[]" << endl;
    }
}

void mostrar_dados_tarefa(TAREFA tarefa){
    cout << endl;
    cout << "************************************" << endl;
    cout << "Tarefa:\t" << tarefa.tarefa << endl;
    cout << "Categoria:\t" << tarefa.categoria << endl;
    cout << "Prioridade:\t" << tarefa.prioridade << endl;
    cout << endl;
    
}

/* Funções devem ser desenvolvidas a partir daqui */

void retirar_tarefa_por_posicao2(Lista *lista, int posicao)
{
    if(posicao > lista->tamanho){
		cerr << "Tamanho da lista menor que a posição informada"<<endl;
		return;
	}
	if(lista->tamanho != 0){
		Node *aux = lista->inicio;
		for(int x = 0; x < posicao - 1; x++){
			aux = aux->proximo;
		}
		if(aux->anterior != NULL){
			aux->anterior->proximo = aux->proximo;
		}else{
			lista->inicio = aux->proximo;
		}
		aux->proximo->anterior = aux->anterior;
		aux->proximo = NULL;
		aux->anterior = NULL;
		cout << "Removido:    "<<aux->tarefa.tarefa;
        cout << endl;
		delete aux;
	}
}

void buscar_tarefas_por_categoria(Lista *lista, int categoria)
{
    if(lista->tamanho!=0)
    {
		Node *aux = lista->inicio;
		if(categoria == 1) {
			cout << "TAREFAS NA CATEGORIA 1" << endl;
			while(aux != NULL){
				if(aux->tarefa.categoria == 1){
					cout << "[" << aux->tarefa.tarefa << "]";
				}
				aux = aux->proximo;
			}

		} else {
			cout << "TAREFAS NA CATEGORIA 2" << endl;
			while(aux != NULL){
				if(aux->tarefa.categoria == 2){
					cout << "[" <<aux->tarefa.tarefa << "]";
				}
				aux = aux->proximo;
			}

			cout << endl;
		}
	}
    
}


void buscar_tarefas_por_prioridades(Lista *lista, int prioridade)
{
    if(lista->tamanho != 0) 
    {
		Node *aux = lista->inicio;
		if(prioridade == 1){
			cout << "TAREFAS COM PRIORIDADE 1" << endl;
			while(aux != NULL){
				if(aux->tarefa.prioridade == 1){
					cout << "[" << aux->tarefa.tarefa << "]";
				}
				aux = aux->proximo;
			}
			cout << endl;
		}else{
            cout << endl;
			cout << "TAREFAS COM PRIORIDADE 2" << endl;
			while(aux != NULL){
				if(aux->tarefa.prioridade == 2){
					cout << "["<<aux->tarefa.tarefa << "]";
				}
				aux = aux->proximo;
			}
			cout << endl;
		}
	}
}

void encerrar(Lista *lista) 
{   
   Node *aux = lista->inicio;
	while(lista->tamanho != 0){
		Node *deleteAux = aux;
		aux = aux->proximo;
		delete deleteAux;
		lista->tamanho--;
	}
}