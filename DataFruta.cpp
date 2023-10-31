#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // Inclua a biblioteca algorithm para usar o sort

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles 
	*/	
	static int compara(Data d1, Data d2) { 
		if (d1.ano < d2.ano){
			return -1;
		}else if (d1.ano > d2.ano){
            return 1;
		}else {
            if (d1.mes < d2.mes){
                return -1;
			}else if (d1.mes > d2.mes){
                return 1;
			}else {
                if (d1.dia < d2.dia){
                    return -1;
				}else if (d1.dia > d2.dia){
                    return 1;
				}else{
                    return 0;
				}
            }
        }
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem() =0;
	virtual void mostraNElementos(int n) = 0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override {
		string nome;  
		int quantidade;

		cout <<"Deseja adicionar quantos nomes? " << endl;
		cin >>quantidade;
		cin.ignore();

		for(int i=0; i<quantidade; i++){ 
			cout <<"Digite o nome: " << endl;
			getline(cin,nome);
		lista.push_back(nome);
		}
		sort(lista.begin(),lista.end());
		
	}
		
	void mostraMediana() override { 
		int tamanhoNome = lista.size();
		string mediana;
		cout << ">>> MEDIANA DA LISTA DE NOMES: " << endl;
		if (tamanhoNome % 2 == 1) {
			// Tamanho ímpar, a mediana é o elemento do meio
		mediana = lista[tamanhoNome / 2];
			cout << "Mediana da lista de nomes: " << mediana << endl;
    	} else {
			// Tamanho par, a mediana é o primeiro dos dois nomes em ordem alfabética
		mediana = lista.front();
			cout << "Mediana da lista de nomes: " << mediana << endl;
  	    }
	}
	
	void mostraMenor() override {
		string menor = lista.front();
		cout << ">>> MOSTRANDO PRIMEIRO NOME ALFABETICAMENTE: " << endl;
		cout << "Primeiro nome: " << menor << endl;

	}
	void mostraMaior() override {
		string maior = lista.back();
		cout << ">>> MOSTRANDO ULTIMO  NOME ALFABETICAMENTE: " << endl;
		cout << "Ultimo nome: " << maior << endl;
	}

	void listarEmOrdem(){
		cout << ">>> MOSTRANDO OS NOMES EM ORDEM ALFABETICA: " << endl;
		for(auto elemento : lista){
			cout << elemento << endl;
		}
	}
	void mostraNElementos(int n) override{
		cout << ">>> MOSTRANDO " << n << " NOMES:" << endl;
		for(int i = 0; i < n; i++){
			cout << lista[i] << endl;
			cout << "-----------------------------" << endl;
		}	
	}
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override {
		int quantidade, dia, mes, ano;
		
		cout << "Deseja inserir quantos elementos na lista de datas ?" << endl;
		cin >> quantidade;
		cin.ignore();

		for(int i =0; i<quantidade; i++){
			cout << "---- DATA: " << i+1  << " -------"<< endl;
			cout << "Informe o dia: " << endl;
			cin >> dia;

			cout << "Informe o mes: " << endl;
			cin >> mes;

			cout << "Informe o ano: " << endl;
			cin >> ano;

			Data data(dia, mes, ano);

			lista.push_back(data);
		} 
		
		selectionSortAdaptado(lista);
	}
	
	void mostraMediana() override {
		Data mediana(0,0,0);
		int tamanho = lista.size();

		cout << ">>> MEDIANA DA LISTA DE DATAS: " << endl;

		if (tamanho % 2 == 1) {
			// Tamanho ímpar, a mediana é o elemento do meio
			mediana = lista[tamanho / 2];
			cout << "Mediana da lista de datas: " << mediana.toString() << endl;
    	} else {
			// Tamanho par, a mediana é o primeiro dos dois nomes em ordem alfabética
			mediana = lista.front();
			cout << "Mediana da lista de datas: " << mediana.toString() << endl;
  	    }
	}
	
	void mostraMenor() override {
		Data menor = lista.front();
		cout << ">>> MOSTRANDO A PRIMEIRA DATA CRONOLOGICAMENTE: " << endl;
		cout << "Primeira data: " << menor.toString() << endl;
	}
	void mostraMaior() override {
		Data maior = lista.back();
		cout << ">>> MOSTRANDO A ULTIMA DATA CRONOLOGICAMENTE: " << endl;
		cout << "Ultima data: " << maior.toString() << endl;
	}


	void selectionSortAdaptado(vector<Data> &datas){
		int minIndex, retornoComparacao;
		Data auxdData(0,0,0);
		for(int i = 0; i<datas.size() - 1; i++){
			minIndex = i;
			for(int j = i+1; j < datas.size(); j++){
				retornoComparacao = Data::compara(datas[j], datas[minIndex]);
				if(retornoComparacao == -1){
					minIndex = j;
				}
			}
			auxdData = datas[i];
			datas[i] = datas[minIndex];
			datas[minIndex] = auxdData;
		}
	}

	void listarEmOrdem() override {
		cout << ">>> MOSTRANDO AS DATAS EM ORDEM: " << endl;
		for(auto elemento : lista){
			cout << elemento.toString() << endl;
		}
	}

	void mostraNElementos(int n) override{
		cout << ">>> MOSTRANDO " << n << " DATAS:" << endl;
		for(int i = 0; i < n; i++){
			cout << lista[i].toString() << endl;
			cout << "-------------------------------" << endl;
		}	
	}
};

class ListaSalarios : public Lista  { 
	vector<float> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deless
	*/	
	void entradaDeDados() override {
		int quantidade;
		float salario;

		cout << "Quantos salarios deseja inserir na lista: " << endl;
		cin >> quantidade;
		cin.ignore();

		for (int i = 0; i<quantidade; i++ ) {
			cout << "Digite o salario: " << endl;
			cin >> salario;

			lista.push_back(salario);
		}
		sort(lista.begin(),lista.end());
	}
			
	void mostraMediana() override {
		int tamanho;
		float mediana;

		tamanho = lista.size();

		cout << ">>> MEDIANA DA LISTA DE SALARIOS: " << endl;
		
		if (tamanho % 2 == 1 ) {
			mediana = lista[tamanho/2];
			cout << "A mediana e: " << mediana << endl;
		} else {
			mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
			cout << "A mediana e: " << mediana << endl;
		}
	}
	
	void mostraMenor() override {
		cout << ">>> MOSTRANDO O MENOR SALARIO: " << endl;
		cout << "O menor salario e: " << lista.front() << endl;
		
	}
	
	void mostraMaior()override {
		cout << ">>> MOSTRANDO O MAIOR SALARIO: " << endl;
		cout << "O maior salario e: " << lista.back() << endl;

	}

	void listarEmOrdem() override {
		cout << ">>> MOSTRANDO O SALARIO DO MENOR PARA O MAIOR: " << endl;
		for(auto elemento : lista){
			cout << elemento << endl;
		}

	}

	void mostraNElementos(int n) override{
		cout << ">>> MOSTRANDO " << n << " IDADES:" << endl;
		for(int i = 0; i < n; i++){
			cout << lista[i] << endl;
			cout << "-----------------------------" << endl;
		}	

	}

};

class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
		
		/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override {
		int qts;
		int valor;

		cout << "Quantos elementos vai existir na lista de idades? " << endl;
		cin >> qts;
		cin.ignore();

		for (int i = 0; i < qts; ++i) {
			cout << "Digite o elemento " << (i + 1) << ": " << endl;
			cin >> valor;
			lista.push_back(valor);
		}

		sort(lista.begin(), lista.end());
	
	}
	
	void mostraMediana() override {
		int  tamanho = lista.size();
		float mediana;
		
		cout << ">>> MEDIANA DA LISTA DE IDADES: " << endl;
    
	if (tamanho % 2 == 0) {
        mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
		cout << "Mediana da idade eh: " << mediana << endl;
    
    } else {
        mediana = lista[tamanho / 2];
		cout << "Mediana da idade eh: " << mediana << endl;
    }

	}
	
	void mostraMenor() override {
		int menorIdade = lista.front();
		cout << ">>> MOSTRANDO A MENOR IDADE: " << endl;
		cout << "A menor Idade " << menorIdade << endl;
	}
	void mostraMaior() override {
		int maiorIdade = lista.back();
		cout << ">>> MOSTRANDO A MAIOR IDADE: " << endl;
		cout << "A maior Idade " << maiorIdade << endl;
	}

	void listarEmOrdem() override {
		cout << ">>> MOSTRANDO AS IDADES DO MENOR PARA A MAIOR: " << endl;
		for(auto elemento : lista){
			cout << elemento << endl;
		}

	}

	void mostraNElementos(int n) override{
		cout << ">>> MOSTRANDO " << n << " IDADES:" << endl;
		for(int i = 0; i < n; i++){
			cout << lista[i] << endl;
			cout << "-----------------------------" << endl;
		}	

	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	int quantidade;
	
    ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades); 
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		l->listarEmOrdem();
		cout << "Informe quantos elementos vc deseja que seja exibidos?" << endl;
		cin >> quantidade;
		cin.ignore();
		l->mostraNElementos(quantidade);
	}
	
}
    

