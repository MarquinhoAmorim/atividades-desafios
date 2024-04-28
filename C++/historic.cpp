/*
 * Segunda lista
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 13/04/2023
 */

#include <iostream>
#include <ctime>

using namespace std;

struct URL {
    string url;
    int dia;
    int mes;
    int ano;
};

struct Node {
    URL url;
    Node *next;
};

struct Pilha {
    Node *topo;
    int tamanho;
};

void inicializar(Pilha *);
void navegar(Pilha *, string);
void navegar(Pilha *historico, string, int, int, int);
URL voltar(Pilha *);
void imprime_historico(Pilha *);
void imprime_url(URL);
void destruir_historico(Pilha *);


int main() {
    int valor;
    URL site;
    Pilha historico_navegacao; 
    inicializar(&historico_navegacao);
    navegar(&historico_navegacao, "http://www.google.com");

    navegar(&historico_navegacao, "http://www.facebook.com");
    navegar(&historico_navegacao, "http://www.globo.com", 15, 1, 2023);
    navegar(&historico_navegacao, "http://www.fatecararas.sp.gov.br");
    navegar(&historico_navegacao, "http://www.google.com");
    navegar(&historico_navegacao, "http://www.facebook.com");
    navegar(&historico_navegacao, "http://www.fatecararas.sp.gov.br");
    navegar(&historico_navegacao, "http://www.gmail.com");

    imprime_historico(&historico_navegacao);
    
    site = voltar(&historico_navegacao);
    imprime_url(site);
    site = voltar(&historico_navegacao);
    imprime_url(site);
    imprime_url(voltar(&historico_navegacao));
    
    imprime_historico(&historico_navegacao);
    destruir_historico(&historico_navegacao);

    return 0;
}

void inicializar(Pilha *historico) {
    historico->tamanho = 0;
    historico->topo = NULL;
}

void navegar(Pilha *historico, string url_acessada) {
    Node *np = new Node;
    if (np == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }
    /*
    Com as bibliotecas chrono e ctime 
    seria mais fácil, mas como ambas são para 
    C++ 11, adotei a struct std::time_t.
    */ 
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1 ;
    int ano= now->tm_year + 1900;

    np->url.url = url_acessada;
    np->url.dia = dia;
    np->url.mes = mes;
    np->url.ano = ano;
    np->next = historico->topo;
    historico->topo = np;
    historico->tamanho++; 
}

void navegar(Pilha *historico, string url, int dia, int mes, int ano){
    
    Node *np = new Node;
    if (np == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }

    np->url.url = url;
    np->url.dia = dia;
    np->url.mes = mes;
    np->url.ano = ano;

    np->next = historico->topo;
    historico->topo = np;
    historico->tamanho++;

}

URL voltar(Pilha * historico){

    Node *np = historico->topo;

    historico->topo = historico->topo->next;
    
    URL url = np->url;

    delete(np);
    historico->tamanho--;
    return url;
}

void imprime_url(URL url){
    
    cout << "       " << url.dia << "/" << url.mes << "/" << url.ano << "   " << url.url << endl;

    /*cout << url.dia << endl;
    cout << url.mes << endl;
    cout << url.ano << endl;*/

}

void imprime_historico(Pilha * historico){

    Node *np = historico->topo;

    cout << endl;
    cout << endl;
    cout << "Quantidade de URLs: " << historico->tamanho << " no historico." << endl;
    cout << "=================================" << endl;

    for (int i = 0; i < historico->tamanho; i++)
    {
        cout << np->url.url << endl;
        np = np->next;
    }

    cout << "----------------------------" << endl;
}


 void destruir_historico(Pilha * historico){

    for (int i = 0; i < historico->tamanho; i++)
    {
        cout << "Desempilhado a URL: " << voltar(historico).url << endl;
    }
    

 }
