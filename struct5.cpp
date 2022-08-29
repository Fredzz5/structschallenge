/*
Exercício sobre struct para aprender o conceito.

faça um programa que permita criar um registro chamado pessoa e que possua dois campos
 um identificação e outro endereço. O campo identificação será outro registro de três campos
  uma string para nome, e um inteiro para a idade e um caráter para sexo. Por outro lado, o endereço
   será outro registro com um campo para cidade e um campo para bairro. O campo bairro será também
    um registro com dois campos um inteiro para número da rua e uma string para  nome do bairro.
     Na main será criada uma variável do tipo pessoa que terá todos os seus campos preenchidos
      e apresentados. */


#include <iostream>
#include <string>
using namespace std;
//observações no código abaixo...

struct identificacao
{
    string nome;
    int idade;
    char sexo;
};
struct bairro
{
    string nomebairro;
    int casa;
};
struct endereco
{
    string cidade;
    bairro mora;
   
};
struct pessoa
{
    identificacao pes;
    endereco cep;
};
int main()
{
    pessoa fred;  //era pra ser pessoa user, mas como fiz o codigo todo a partir da variavel fred, não vai mudar nada mesmo
    cout<<"insira seus dados como pessoa:"<<endl;
    cout<<"identificacao: "<<endl<<endl<<"nome: ";  
    getline(cin,fred.pes.nome); 
    cout<<"idade: "; 
    cin>>fred.pes.idade;
    while (0>=fred.pes.idade)    //o código não consegue rodar a condição (150<=fred.pes.idade<=0) por algum motivo que desconheço
    {                            //mas segue uma gambiarra...
        cout<<"idade invalida, insira uma possivel: ";
        cin>>fred.pes.idade;
            while (150<=fred.pes.idade)
    {
        cout<<"idade invalida, insira uma possivel: ";
        cin>>fred.pes.idade;
    }
    }
    while (150<=fred.pes.idade)      //tive que fazer esse duplo looping que tem muita linha pois...
    {                    //a condição while (150<=fred.pes.idade<=0) não funcionou por motivos desconhecidos
        cout<<"idade invalida, insira uma possivel: ";  //não sei mesmo o porquê de não funcionar a condição acima
        cin>>fred.pes.idade;
            while (0>=fred.pes.idade)   
    {
        cout<<"idade invalida, insira uma possivel: ";  
        cin>>fred.pes.idade;
    }
    }
    cout<<"sexo (m/f): ";
    cin>>fred.pes.sexo;
    while((fred.pes.sexo!='m')&&(fred.pes.sexo!='f'))
    {
        cout<<endl<<"o sexo apresentado nao coincide com as informadas, tente novamente: ";
        cin>>fred.pes.sexo;
    }
    cout<<endl<<"insira a sua cidade: ";
    getline(cin,fred.cep.cidade);     //se eu usar getline aqui, a cidade é pulada e vai pro bairro,
    getline(cin,fred.cep.cidade);    //deixando o campo cidade vazio
    cout<<"nome do bairro: ";         //mas se eu usar 2 getlines da msm variavel eu consigo burlar isso
    getline(cin,fred.cep.mora.nomebairro);  //sim, até eu não entendi o porquê.
    cout<<"numero da casa: ";
    cin>>fred.cep.mora.casa;
    while(fred.cep.mora.casa<0)
    {
        cout<<"insira um numero de casa valido: ";
        cin>>fred.cep.mora.casa;
    }
    cout<<endl<<"registro finalizado."<<endl<<endl;
    cout<<"nome: "<<fred.pes.nome<<endl<<"idade: "<<fred.pes.idade<<endl<<"sexo: "<<fred.pes.sexo<<endl;
    cout<<"cidade: "<<fred.cep.cidade<<endl<<"nome do bairro: "<<fred.cep.mora.nomebairro<<endl<<"casa "<<fred.cep.mora.casa<<endl;
 
    return 0;
}
